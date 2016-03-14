#ifndef _DLLSOCKET_H_
#define _DLLSOCKET_H_
//#include <string>
//#include <winsock2.h>
#include "ace/SOCK_Connector.h"
#include "ace/INET_Addr.h"





	class DllSocket
	{
		public:
			//constructores
			DllSocket(char *hostname, int port);

			//destructor
			virtual ~DllSocket(void);

			//metodos para realizar la apertura del socket
			bool bOpenSocket(void);
			unsigned int uiReceive(unsigned char *DataOut,const unsigned int culTimer,const unsigned int cuiSizeDataReceive,const unsigned int sleep);
			bool bCloseSocket(void);
			unsigned int uiSend(const unsigned char *pcucDataSend,const unsigned int cuiSizeDataSend)const;

		private:
			//atributos
			ACE_INET_Addr remote_addr_;
			ACE_SOCK_Stream client_stream_;
			ACE_SOCK_Connector connector_;
	};


#endif /* _DLL_H_ */
