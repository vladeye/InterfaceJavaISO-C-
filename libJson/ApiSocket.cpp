/* Replace "dll.h" with the name of your header */
#include "ApiSocket.h"
//#include <windows.h>
#include <time.h>

#define __SIZE_NULL_CHAR		1
#define __MAX_VALUE_VALID_PORT	65535
#define __DEFAULT_SIZE_RECEIVE_BUFFER 4096



/*
contructores
*/
DllSocket::DllSocket(char *hostname, int port):remote_addr_(port,hostname)
{

}



//destructor
DllSocket::~DllSocket ()
{

}


//método para abrir el socket
bool DllSocket::bOpenSocket()
{
	bool ret=true;

	if (connector_.connect(client_stream_, remote_addr_) == -1)
		ret=false;

    return ret;
}

unsigned int DllSocket::uiSend(const unsigned char *pcucDataSend,const unsigned int cuiSizeDataSend)const
{
	int ret = client_stream_.send_n (pcucDataSend, cuiSizeDataSend, 0);

    if (ret == -1)
	{
		return 0;
	}


    return ret;
}


//metodo para recibir
unsigned int DllSocket::uiReceive(unsigned char *DataOut,const unsigned int culTimer,const unsigned int cuiSizeDataReceive,const unsigned int sleep)
{
	/*ACE_Time_Value objTimer((int)culTimer);
    size_t SizeReceived=0;
    usleep(sleep*1000);

    client_stream_.recv_n (DataOut,cuiSizeDataReceive,&objTimer,&SizeReceived);
    return SizeReceived;*/

    ACE_Time_Value objTimer1(1);
    ACE_Time_Value objTimer2(0);
    size_t SizeReceived=0;
    unsigned int sizeTotal=0;
//    usleep(1000000);
    bool first = true;

    for(;;)
    {
        client_stream_.recv_n (&DataOut[sizeTotal],(first)?cuiSizeDataReceive:0,(first)?&objTimer1:&objTimer2,&SizeReceived);
        if(!first)
        {
            if(SizeReceived<=0)
                break;
        }
        first = false;
        sizeTotal+=SizeReceived;
//        usleep(1000000);
    }

    return sizeTotal;

}

//metodo para cerra el socket
bool DllSocket::bCloseSocket()
{
	client_stream_.close();
	return true;
}

