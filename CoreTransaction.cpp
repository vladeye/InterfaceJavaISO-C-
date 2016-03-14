
#include "CoreTransaction.h"
#include "ApiSocket.h"

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_ctype.h"
#include "http_handler.h"
#include "NMCLog.h"

//#define __DEBUG_DATA_2_SEND
//#define logbasic	cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- "

#if defined(logbegin) || defined (logend) || defined (logbasic) || defined (__DEBUG_DATA_2_SEND) || defined (heavylog)
    #include <iostream>
    #define _BYTES_PER_LINE 10
#endif


#ifdef __DEBUG_DATA_2_SEND
//function for log
void LogData(const unsigned char* Buffer,const char *Title,const unsigned int Size)
{
	char BufferOutHex[(_BYTES_PER_LINE * 3) + 1];
	char TempBufferHexData[3 + 1];
	char TempBufferASCIIData[2 + 1];
	char BufferOutASCII[(_BYTES_PER_LINE * 2) + 1];
	int NumLines = (Size/_BYTES_PER_LINE) + (((Size%_BYTES_PER_LINE)!=0)?1:0);

	cout<<"["<<Title<<"]"<<endl;

	for(int i=0;i<NumLines;i++)
	{
		memset(BufferOutHex,0,sizeof(BufferOutHex));
		memset(BufferOutASCII,0,sizeof(BufferOutASCII));

		for(int j=0;j<((i==(NumLines-1) && (Size%_BYTES_PER_LINE)!=0)?Size%_BYTES_PER_LINE:_BYTES_PER_LINE);j++)
		{
			memset(TempBufferHexData,0,sizeof(TempBufferHexData));
			memset(TempBufferASCIIData,0,sizeof(TempBufferASCIIData));
			sprintf(TempBufferHexData,"%02x ",Buffer[(i*_BYTES_PER_LINE)+j]);
			sprintf(TempBufferASCIIData,"%c ",(Buffer[(i*_BYTES_PER_LINE)+j]<0x20)?'.':Buffer[(i*_BYTES_PER_LINE)+j]);
			strcat(BufferOutHex,TempBufferHexData);
			strcat(BufferOutASCII,TempBufferASCIIData);
		}

		cout<<"["<<BufferOutHex<<"] ["<<BufferOutASCII<<"]"<<endl;

	}
}
#endif

CoreTransaction::CoreTransaction(): messageFailedInvalidResponse("Failed [Invalid Response]"),
                                    messageFailedPackISO("Failed [Pack ISO]"),
                                    messageFailedCommunications("Failed [Comunications]"),
                                    messageFailedUnpackISO("Failed [UnPack ISO]"),
                                    messageFailedException("Failed [Exception]"),
                                    messageOK("OK"),
                                    messageResponseTrue("{true}"),
                                    messageResponseFalse("{false}")
{

}

bool CoreTransaction::ProceessComunication(const char * const hostname,const int port,string &dataOut,const unsigned int sleep,string &dataIn,const bool waitResponse)
{
#ifdef __DEBUG_DATA_2_SEND
    LogData((unsigned char *)dataOut.c_str(),"ISO OUT",dataOut.length());
#endif

    //socket
    DllSocket sock((char *)hostname,port);

    if(!sock.bOpenSocket())
    {
        return false;
    }

    //NMCLog::Log(string("Send [") + dataOut + string("]"));
    if(sock.uiSend((unsigned char *)dataOut.c_str(),dataOut.length())<=0)
    {
        sock.bCloseSocket();
        return false;
    }

    if(waitResponse)
    {

       // usleep(sleep*1000);
        unsigned int sizeReceived;

        unsigned char *dataReceived=new unsigned char [2048];
        sizeReceived=sock.uiReceive(dataReceived,2,2048,2000);

        //NMCLog::Log(string("Receive [") + string((char *)dataReceived,sizeReceived) + string("]"));

        sock.bCloseSocket();
        if(sizeReceived<=0)
        {
            delete [] dataReceived;
            return false;
        }

        dataIn=string ( (const char *)dataReceived, sizeReceived );

#ifdef __DEBUG_DATA_2_SEND
        LogData((unsigned char *)dataIn.c_str(),"ISO IN",dataIn.length());
#endif

        delete [] dataReceived;
    }
    else
    {
        sock.bCloseSocket();
    }


    return true;
}


//"http://192.168.0.11:8180/prototype/services/CouponListFilter2?isInp=MDMwNcKCEAEAAAAIAAAAAAAJAAEAMDkxNzE5NDYyNzIwMTIwOTE4MDExNjI3MzA1MDAwMDAwMDAwMDAwMDAwMzM5MTBDVVBMU1RGSUxUMDIyMDAyMDA1M2AAABAGAAAAMDAwMDAwMDAwMTAwMDAwMDAwMTAxMTAxOC41MTE5MzQ5MTA3My44NDQxMzU3"
bool CoreTransaction::ProceessComunicationHTTP(const char * const hostname,const int port,const string &dataOut,string &dataIn)
{
#ifdef __DEBUG_DATA_2_SEND
    LogData((unsigned char *)dataOut.c_str(),"ISO OUT",dataOut.length());
#endif

    string url;
    char chPort[7];

    memset(chPort,0,sizeof(chPort));

    snprintf(chPort,sizeof(chPort)-1,"%d",port);

    url="http://"+string(hostname)+":"+string(chPort)+dataOut;

#ifdef logbasic
    logbasic<<"URL ["<<url<<"]"<<endl;
#endif

    // URL
      HTTP_Connector connector;
      connector.connect (url.c_str(),dataIn);



    return true;
}



bool CoreTransaction::ProceessComunication(string &dataOut,const unsigned int sleep,string &dataIn,const bool waitResponse)
{
    char IP[16 + 1];
    char Port[5 + 1];

    memset(IP,0,sizeof(IP));
    memset(Port,0,sizeof(Port));


    ifstream leer;

   // const char * val = ::getenv( "CONFIU" );

    //if(val == 0)
#ifdef WIN32
        leer.open("C:\nmc\confi");
#else
        leer.open("/srv/nmc/confi");
#endif
    /*else
    {
        char nameFile[256];
        memset(nameFile,0,sizeof(nameFile));
        snprintf(nameFile,sizeof(nameFile)-1,"%s%s",val,"confi");
        leer.open(val);
    }*/



    leer.getline(IP,16,';');
    leer.getline(Port,5,';');

    leer.close();

    return this->ProceessComunication(IP,atoi(Port),dataOut,sleep,dataIn,waitResponse);
}


//"http://192.168.0.11:8180/prototype/services/CouponListFilter2?isInp=MDMwNcKCEAEAAAAIAAAAAAAJAAEAMDkxNzE5NDYyNzIwMTIwOTE4MDExNjI3MzA1MDAwMDAwMDAwMDAwMDAwMzM5MTBDVVBMU1RGSUxUMDIyMDAyMDA1M2AAABAGAAAAMDAwMDAwMDAwMTAwMDAwMDAwMTAxMTAxOC41MTE5MzQ5MTA3My44NDQxMzU3"
bool CoreTransaction::ProceessComunicationHTTP(const string &dataOut,string &dataIn)
{
    char IP[16 + 1];
    char Port[5 + 1];

    memset(IP,0,sizeof(IP));
    memset(Port,0,sizeof(Port));

    ifstream leer;

    //const char * val = ::getenv( "CONFIU" );

    //if(val == 0)
#ifdef WIN32
        leer.open("C:\nmc\confu");
#else
        leer.open("/srv/nmc/confu");
#endif
    /*else
    {
        char nameFile[256];
        memset(nameFile,0,sizeof(nameFile));
        snprintf(nameFile,sizeof(nameFile)-1,"%s%s",val,"confu");
        leer.open(val);
    }*/


    leer.getline(IP,16,';');
    leer.getline(Port,5,';');

    leer.close();

    return this->ProceessComunicationHTTP(IP,atoi(Port),dataOut,dataIn);
}


bool CoreTransaction::GetFieldsFromISO(string &Input,string *Fields,const int numFields,string *out)
{

    try
    {
        IsoParser *myiso;
        myiso = getIsoParser0();

		IsoParser *myiso48;
        myiso48 = this->getIsoParser48();

		IsoParser *myiso114;
		myiso114 = this->getIsoParser114();

		IsoParser *myiso55;
		myiso55 = this->getIsoParser55();

		IsoParser *myiso62;
        myiso62 = this->getIsoParser62();

        IsoParser *myiso47;
        myiso47 = this->getIsoParser47();

        IsoParser *myiso121;
        myiso121 = this->getIsoParser121();

        IsoParser *myiso120;
        myiso120 = this->getIsoParser120();

        string iso48;
        string iso47;
        string iso114;
        string iso55;
        string iso62;
        string iso121;
        string iso120;

        bool if47=false;
        bool if48=false;
        bool if114=false;
        bool if55=false;
        bool if62=false;
        bool if121=false;
        bool if120=false;

        string AuxField;
        string SubField;

        myiso->ParseFromASCIIB(Input);

        for(int i=0;i<numFields;i++)
        {
            AuxField=Fields[i].substr(0,Fields[i].find("."));
            //get sub field
            SubField=Fields[i].substr(Fields[i].find(".")+1);


            //check 48
            if(AuxField.compare("48")==0)
            {
                if(!if48)
                {
                    iso48=myiso->GetField(48);
                    if(iso48.length()>0)
                        myiso48->ParseFromASCIISubFieldB(iso48);
                    if48=true;
                }
                if(iso48.length()>0)
                    out[i]=myiso48->GetField(atoi(SubField.c_str()));
            }
            //check 47
            else if(AuxField.compare("47")==0)
            {
                if(!if47)
                {
                    iso47=myiso->GetField(47);
                    if(iso47.length()>0)
                        myiso47->ParseFromASCIISubFieldB(iso47);
                    if47=true;
                }
                if(iso47.length()>0)
                    out[i]=myiso47->GetField(atoi(SubField.c_str()));
            }
            //check 120
            else if(AuxField.compare("120")==0)
            {
                if(!if120)
                {
                    iso120=myiso->GetField(120);
                    if(iso120.length()>0)
                        myiso120->ParseFromASCIISubFieldB(iso120);
                    if120=true;
                }

                if(iso120.length()>0)
                    out[i]=myiso120->GetField(atoi(SubField.c_str()));
            }
            //check 121
            else if(AuxField.compare("121")==0)
            {
                if(!if121)
                {
                    iso121=myiso->GetField(121);
                    if(iso121.length()>0)
                        myiso121->ParseFromASCIISubFieldB(iso121);
                    if121=true;
                }

                if(iso121.length()>0)
                    out[i]=myiso121->GetField(atoi(SubField.c_str()));
            }
            //check 114
            else if(AuxField.compare("114")==0)
            {
                if(!if114)
                {
                    iso114=myiso->GetField(114);
                    if(iso114.length()>0)
                        myiso114->ParseFromASCIISubFieldB(iso114);
                    if114=true;
                }

                if(iso114.length()>0)
                    out[i]=myiso114->GetField(atoi(SubField.c_str()));
            }
            //check 55
            else if(AuxField.compare("55")==0)
            {
                if(!if55)
                {
                    iso55=myiso->GetField(55);
                    if(iso55.length()>0)
                        myiso55->ParseFromASCIISubFieldB(iso55);
                    if55=true;
                }
                if(iso55.length()>0)
                    out[i]=myiso55->GetField(atoi(SubField.c_str()));
            }
            //check 62
            else if(AuxField.compare("62")==0)
            {
                if(!if62)
                {
                    iso62=myiso->GetField(62);
                    if(iso62.length()>0)
                        myiso62->ParseFromASCIISubFieldB(iso62);
                    if62=true;
                }
                if(iso62.length()>0)
                    out[i]=myiso62->GetField(atoi(SubField.c_str()));
            }
            else
            {
                out[i]=myiso->GetField(atoi(Fields[i].c_str()));
            }
        }


        delete myiso;
        delete myiso48;
        delete myiso47;
		delete myiso114;
		delete myiso55;
		delete myiso62;
		delete myiso121;
		delete myiso120;

        return true;
    }
    catch(...)
    {
        return false;
    }

}


bool CoreTransaction::BuildISOFormater(hasresult &hResult,string &sFormatedRsp,string &mti)
{
    bool if47 = false;
    bool if48 = false;
    bool if55 = false;
    bool if62 = false;
    bool if114 = false;
    bool if120 = false;
    bool if121 = false;

    string AuxField;

    for (hasresult::const_iterator it = hResult.begin();it != hResult.end(); ++it)
    {
        //cout << "OUT: " << it->first << " : " << it->second << endl;

        NMCLog::Log(string("Field [") + it->first + string("] Value [") + it->second + string("]"));

        AuxField=(it->first).substr(0,(it->first).find("."));
        //check 48
        if(AuxField.compare("48")==0)
        {
            if48=true;
        }
        //check 47
        else if(AuxField.compare("47")==0)
        {
            if47=true;
        }
        //check 120
        else if(AuxField.compare("120")==0)
        {
            if120=true;
        }
        //check 121
        else if(AuxField.compare("121")==0)
        {
            if121=true;
        }
        //check 114
        else if(AuxField.compare("114")==0)
        {
            if114=true;
        }
        //check 55
        else if(AuxField.compare("55")==0)
        {
            if55=true;
        }
        //check 62
        else if(AuxField.compare("62")==0)
        {
            if62=true;
        }
	}

    return this->BuildISOFormater(if47,if48,if55,if62,if114,if120,if121,hResult,sFormatedRsp,mti);
}

IsoParser *CoreTransaction::getIsoParser0()
{
    const int arrISO = 62;

    string arrMyIso[][5] = { { "2", "de-002", "llvar", "19", "n" },
							 { "3", "de-003", "fix", "6", "ans" },
							 { "4", "de-004", "fix", "16", "n" },
							 { "6", "de-006", "fix", "16", "n" },
							 { "7", "de-007", "fix", "10", "n" },
							 { "8", "de-008", "fix", "12", "n" },
							 { "11", "de-011", "fix", "12", "n" },
							 { "12", "de-012", "fix", "14", "n" },
							 { "13", "de-013", "fix", "6", "n" },
							 { "14", "de-014", "fix", "4", "n" },
							 { "17", "de-017", "fix", "4", "n" },
							 { "18", "de-018", "lllvar", "140", "ans" },
							 { "21", "de-021", "fix", "22", "ans" },
							 { "22", "de-022", "bfix", "16", "b" },
							 { "23", "de-023", "fix", "3", "n" },
							 { "24", "de-024", "fix", "3", "n" },
							 { "25", "de-025", "fix", "4", "n" },
							 { "26", "de-026", "fix", "4", "n" },
							 { "30", "de-030", "fix", "32", "n" },
							 { "32", "de-032", "llvar", "11", "n" },
							 { "33", "de-033", "llvar", "11", "n" },
							 { "35", "de-035", "llvar", "37", "ans" },
							 { "37", "de-037", "fix", "12", "ans" },
							 { "38", "de-038", "fix", "6", "ans" },
							 { "39", "de-039", "fix", "4", "ans" },
							 { "41", "de-041", "llvar", "99", "ans" },
							 { "42", "de-042", "llvar", "99", "ans" },
							 { "43", "de-043", "bllllvar", "9999", "b" },
							 { "44", "de-044", "llvar", "25", "ans" },
							 { "45", "de-045", "llvar", "76", "ans" },
							 { "46", "de-046", "lllvar", "216", "ans" },
							 { "47", "de-047", "lllvar", "999", "ans" },
							 { "48", "de-048", "llllvar", "9999", "b" },
							 { "52", "de-052", "fix", "16", "n" },
							 { "53", "de-053", "fix", "18", "n" },
							 { "54", "de-054", "lllvar", "126", "ans" },
							 { "55", "de-055", "lllvar", "999", "ans" },
							 { "56", "de-056", "llvar", "41", "ans" },
							 { "57", "de-057", "llvar", "50", "ans" },
							 { "58", "de-058", "llvar", "99", "ans" },
							 { "59", "de-059", "llvar", "999", "ans" },
							 { "62", "de-062", "lllvar", "999", "ans" },
							 { "63", "de-063", "lllvar", "999", "ans" },
							 { "64", "de-064", "bfix", "4", "b" },
							 { "68", "de-068", "fix", "9", "ans" },
							 { "72", "de-072", "bllllvar", "9999", "b" },
							 { "74", "de-074", "fix", "78", "n" },
							 { "97", "de-097", "fix", "21", "n" },
							 { "101", "de-101", "llvar", "99", "ans" },
							 { "102", "de-102", "llvar", "28", "ans" },
							 { "103", "de-103", "llvar", "28", "ans" },
							 { "104", "de-104", "fix", "6", "n" },
							 { "105", "de-105", "fix", "6", "n" },
							 { "106", "de-106", "lllvar", "999", "ans" },
							 { "107", "de-107", "blllvar", "999", "b" },
							 { "111", "de-111", "bllllvar", "9999", "b" },
							 { "112", "de-112", "bllllvar", "9999", "b" },
							 { "113", "de-113", "fix", "11", "n" },
							 { "114", "de-114", "llllvar", "9999", "ans" },
							 { "120", "de-120", "llllvar", "9999", "ans" },
							 { "121", "de-121", "llllvar", "9999", "ans" },
							 { "128", "de-128", "bfix", "16", "b" }};


    return new IsoParser(arrMyIso, arrISO);
}


IsoParser *CoreTransaction::getIsoParser120()
{
    const int arrISO120 = 180;

    string arrMyIso120[][5] = { { "4", "de-004", "llvar", "32", "ans" },
                            { "5", "de-005", "llvar", "15", "ans" },
							{ "6", "de-006", "llvar", "50", "ans" },
							{ "7", "de-007", "llvar", "15", "ans" },
							{ "8", "de-008", "llvar", "40", "ans" },
							{ "9", "de-009", "llvar", "10", "ans" },
							{ "10", "de-010", "fix", "5", "ans" },
							{ "11", "de-011", "lllvar", "100", "ans" },
							{ "12", "de-012", "llvar", "20", "ans" },
							{ "13", "de-013", "llvar", "20", "ans" },
                            { "14", "de-014", "llvar", "20", "an" },
                            { "15", "de-015", "fix", "1", "n" },
							{ "16", "de-016", "fix", "4", "n" },
							{ "17", "de-016", "fix", "10", "n" },
							{ "18", "de-18", "fix", "1", "n" },
							{ "19", "de-19", "fix", "1", "n" },
							{ "20", "de-20", "fix", "10", "n" },
							{ "21", "de-021", "llvar", "50", "ans" },
							{ "22", "de-022", "llvar", "10", "ans" },
							{ "24", "de-024", "llvar", "10", "ans" },
							{ "25", "de-025", "fix", "1", "n" },
                            { "26", "de-026", "fix", "1", "n" },
							{ "27", "de-027", "fix", "10", "n" },
							{ "28", "de-028", "fix", "1", "n" },
                            { "29", "de-029", "fix", "10", "n" },
							{ "30", "de-030", "fix","10", "n" },
                            { "31", "de-031", "fix","10", "n" },
                            { "32", "de-032", "lllvar", "255", "ans" },
                            { "33", "de-033", "fix","10", "n" },
							{ "34", "de-034", "llvar","15", "ans" },
							{ "35", "de-035", "lllvar","100", "ans" },
							{ "36", "de-036", "lllvar","255", "ans" },
                            { "37", "de-037", "llvar", "30", "ans" },
                            { "38", "de-038", "llvar","20", "ans" },
							{ "39", "de-039", "llvar","20", "ans" },
							{ "40", "de-040", "fix","1", "n" },
							{ "41", "de-041", "fix","2", "n" },
							{ "42", "de-042", "llvar","45", "ans" },
                            { "43", "de-043", "llvar","20", "ans" },
							{ "44", "de-044", "fix","10", "n" },
							{ "45", "de-045", "llvar", "45", "ans" },
                            { "46", "de-046", "fix", "8", "n" },
							{ "47", "de-047", "fix", "8", "n" },
                            { "48", "de-048", "fix", "10", "n" },
							{ "49", "de-049", "fix", "10", "n" },
							{ "50", "de-050", "fix", "14", "n" },
							{ "51", "de-051", "lllvar","255", "ans" },
							{ "52", "de-052", "llvar","30", "ans" },
							{ "53", "de-053", "lllvar","300", "ans" },
							{ "54", "de-054", "llvar","10", "n" },
							{ "55", "de-055", "fix","1", "n" },
                            { "56", "de-056", "llvar", "20", "ans" },
                            { "57", "de-057", "llvar", "99", "ans" },
                            { "58", "de-058", "llvar", "99", "ans" },
							{ "64", "de-064", "fix", "10", "n" },
                            { "66", "de-066", "llvar", "10", "n" },
							{ "67", "de-067", "llvar", "10", "n" },
							{ "68", "de-068", "llvar", "10", "n" },
							{ "69", "de-069", "fix", "10", "n" },
                            { "70", "de-070", "lllvar", "999", "ans" },
                            { "71", "de-071", "lllvar", "100", "ans" },
                            { "73", "de-073", "llvar", "20", "ans" },
                            { "74", "de-074", "fix", "5", "n" },
                            { "75", "de-075", "fix", "10", "n" },
							{ "76", "de-076", "fix", "10", "n" },
							{ "77", "de-077", "fix", "1", "n" },
							{ "78", "de-078", "lllvar", "255", "ans" },
							{ "79", "de-079", "lllvar", "255", "ans" },
							{ "80", "de-080", "fix", "10", "n" },
							{ "81", "de-081", "lllvar", "255", "ans" },
							{ "82", "de-082", "lllvar", "255", "ans" },
							{ "83", "de-083", "lllvar", "255", "ans" },
                            { "84", "de-084", "fix", "11", "n" },
							{ "85", "de-085", "fix", "10", "n" },
							{ "86", "de-086", "fix", "10", "n" },
							{ "87", "de-087", "llvar", "20", "ans" },
							{ "88", "de-088", "llvar", "11", "ans" },
							{ "89", "de-089", "llvar", "11", "ans" },
                            { "90", "de-090", "llvar", "50", "ans" },
                            { "91", "de-091", "fix", "10", "n" },
							{ "92", "de-092", "fix", "10", "n" },
							{ "93", "de-093", "llvar", "99", "ans" },
							{ "94", "de-094", "lllvar", "255", "ans" },
							{ "95", "de-095", "llvar", "99", "ans" },
                            { "96", "de-096", "llvar", "10", "ans" },
                            { "97", "de-097", "llvar", "99", "ans" },
                            { "98", "de-098", "llvar", "30", "ans" },
							{ "99", "de-099", "fix", "1", "n" },
							{ "100", "de-100", "fix", "11", "n" },
							{ "101", "de-101", "fix", "11", "n" },
							{ "102", "de-102", "lllvar", "255", "ans" },
							{ "103", "de-103", "lllvar", "255", "ans" },
							{ "104", "de-104", "lllvar", "255", "ans" },
							{ "105", "de-105", "lllvar", "255", "ans" },
                            { "106", "de-106", "fix", "10", "n" },
							{ "107", "de-107", "fix", "10", "n" },
							{ "108", "de-108", "fix", "1", "n" },
							{ "109", "de-109", "fix", "10", "n" },
							{ "110", "de-110", "fix", "10", "n" },
							{ "111", "de-111", "fix", "11", "n" },
							{ "112", "de-112", "fix", "14", "n" },
							{ "113", "de-113", "fix", "14", "n" },
							{ "114", "de-114", "llvar", "10", "ans" },
							{ "115", "de-115", "fix", "11", "n" },
							{ "116", "de-116", "fix", "11", "n" },
							{ "117", "de-117", "llvar", "15", "n" },
							{ "118", "de-118", "fix", "10", "n" },
							{ "119", "de-119", "fix", "10", "n" },
							{ "120", "de-120", "llvar", "20", "a" },
							{ "121", "de-121", "fix", "11", "n" },
							{ "122", "de-122", "llvar", "40", "ans" },
							{ "123", "de-123", "llvar", "40", "ans" },
							{ "124", "de-124", "llvar", "40", "ans" },
							{ "125", "de-125", "fix", "10", "n" },
                            { "126", "de-126", "lllvar", "300", "ans" },
							{ "127", "de-127", "lllvar", "255", "ans" },
							{ "128", "de-128", "fix", "5", "n" },
							{ "129", "de-128", "fix", "5", "ans" },
							{ "130", "de-130", "fix", "1", "n" },
							{ "131", "de-131", "fix", "1", "n" },
							{ "132", "de-132", "fix", "2", "n" },
							{ "133", "de-133", "fix", "64", "b" },
							{ "134", "de-134", "fix", "16", "b" },
                            { "135", "de-135", "fix", "10", "n" },
							{ "136", "de-136", "lllvar", "120", "n" },
							{ "137", "de-137", "fix", "10", "n" },
							{ "138", "de-138", "fix", "1", "n" },
							{ "139", "de-139", "fix", "1", "n" },
							{ "140", "de-140", "fix", "10", "n" },
							{ "141", "de-141", "fix", "2", "n" },
							{ "142", "de-142", "lllvar", "200", "ans" },
							{ "143", "de-143", "fix", "14", "n" },
							{ "144", "de-144", "fix", "10", "n" },
							{ "145", "de-145", "fix", "10", "n" },
							{ "146", "de-146", "llvar", "30", "ans" },
							{ "147", "de-147", "fix", "1", "n" },
							{ "148", "de-148", "lllvar", "300", "ans" },
							{ "149", "de-149", "llvar", "11", "n" },
							{ "150", "de-150", "llvar", "11", "n" },
							{ "151", "de-151", "llvar", "20", "ans" },
							{ "152", "de-152", "fix", "11", "n" },
							{ "153", "de-153", "fix", "10", "n" },
							{ "154", "de-154", "llvar", "50", "ans" },
							{ "155", "de-155", "fix", "10", "n" },
							{ "156", "de-156", "fix", "10", "n" },
							{ "157", "de-157", "lllvar", "255", "ans" },
                            { "158", "de-158", "llvar", "50", "ans" },
							{ "159", "de-159", "lllvar", "255", "ans" },
							{ "160", "de-160", "fix", "2", "n" },
							{ "161", "de-161", "fix", "1", "n" },
							{ "162", "de-162", "fix", "3", "n" },
							{ "163", "de-163", "fix", "1", "n" },
							{ "164", "de-164", "fix", "3", "n" },
							{ "165", "de-165", "fix", "3", "n" },
							{ "166", "de-166", "fix", "3", "n" },
							{ "167", "de-167", "fix", "3", "n" },
							{ "168", "de-168", "fix", "1", "n" },
							{ "169", "de-169", "fix", "1", "n" },
							{ "170", "de-170", "fix", "1", "n" },
							{ "171", "de-171", "fix", "1", "n" },
							{ "172", "de-172", "fix", "1", "n" },
							{ "173", "de-173", "fix", "1", "n" },
							{ "174", "de-174", "fix", "1", "n" },
							{ "175", "de-175", "fix", "1", "n" },
							{ "176", "de-176", "fix", "1", "n" },
							{ "177", "de-177", "fix", "1", "n" },
							{ "178", "de-178", "fix", "1", "n" },
							{ "179", "de-179", "fix", "1", "n" },
							{ "180", "de-180", "fix", "1", "n" },
							{ "181", "de-181", "fix", "1", "n" },
							{ "182", "de-182", "lllvar", "100", "ans" },
							{ "183", "de-183", "lllvar", "100", "ans" },
							{ "184", "de-184", "llvar", "40", "ans" },
							{ "185", "de-185", "fix", "2", "ans" },
							{ "186", "de-186", "llvar", "20", "ans" },
							{ "187", "de-187", "fix", "5", "ans" },
							{ "188", "de-188", "fix","1", "ans" },
                            { "189", "de-189", "fix","1", "ans" },
                            { "190", "de-190", "fix","1", "ans" },
                            { "191", "de-191", "fix","1", "ans" }};

    return new IsoParser(arrMyIso120, arrISO120);

}

IsoParser *CoreTransaction::getIsoParser47()
{
    const int arrISO47 = 45;

    string arrMyIso47[][5] = {  { "2", "de-002", "fix", "1", "n" },
							    { "3", "de-003", "fix", "1", "n" },
								{ "4", "de-004", "fix", "1", "n" },
								{ "5", "de-005", "fix", "1", "n" },
								{ "6", "de-006", "llvar", "10", "ans" },
								{ "7", "de-007", "llvar", "10", "ans" },
								{ "8", "de-008", "llvar", "10", "ans" },
								{ "9", "de-009", "fix", "1", "n" },
								{ "10", "de-010", "llvar", "10", "ans" },
								{ "11", "de-011", "llvar", "10", "ans" },
								{ "12", "de-012", "llvar", "99", "ans" },
								{ "13", "de-013", "llvar", "20", "ans" },
								{ "14", "de-014", "llvar", "99", "ans" },
								{ "15", "de-015", "llvar", "15", "ans" },
								{ "16", "de-016", "llvar", "15", "ans" },
								{ "17", "de-017", "llvar", "10", "ans" },
								{ "18", "de-018", "llvar", "30", "ans" },
								{ "19", "de-019", "fix", "10", "n" },
								{ "20", "de-020", "llvar", "99", "ans" },
								{ "21", "de-021", "fix", "10", "n" },
								{ "22", "de-022", "llvar", "10", "ans" },
								{ "23", "de-023", "llvar", "10", "ans" },
								{ "24", "de-024", "lllvar", "200", "ans" },
								{ "25", "de-025", "lllvar", "100", "ans" },
								{ "26", "de-026", "llvar", "30", "ans" },
								{ "27", "de-027", "lllvar", "150", "ans" },
								{ "28", "de-028", "fix", "10", "n" },
								{ "29", "de-029", "fix", "10", "n" },
								{ "30", "de-030", "fix", "10", "n" },
								{ "31", "de-031", "fix", "11", "n" },
								{ "32", "de-032", "lllvar", "255", "ans" },
								{ "33", "de-033", "lllvar", "255", "ans" },
								{ "34", "de-034", "lllvar", "255", "ans" },
								{ "35", "de-035", "fix", "11", "n" },
								{ "36", "de-036", "fix", "11", "n" },
								{ "37", "de-037", "fix", "11", "n" },
								{ "38", "de-038", "lllvar", "255", "ans" },
								{ "39", "de-039", "fix", "10", "n" },
								{ "40", "de-040", "fix", "10", "n" },
								{ "41", "de-041", "lllvar", "100", "ans" },
								{ "42", "de-042", "lllvar", "255", "ans" },
								{ "43", "de-043", "fix", "1", "ans" },
								{ "44", "de-044", "fix", "11", "n" },
								{ "45", "de-045", "fix", "11", "n" },
								{ "46", "de-046", "llvar", "99", "ans" }};

    return new IsoParser(arrMyIso47, arrISO47);
}


IsoParser *CoreTransaction::getIsoParser114()
{
    const int arrISO114 = 190;

    string arrMyIso114[][5] = { { "2", "de-002", "llvar", "20", "b" },
								{ "3", "de-003", "llvar", "40", "ans" },
								{ "4", "de-004", "llvar", "40", "ans" },
								{ "5", "de-005", "llvar", "40", "ans" },
								{ "6", "de-006", "llvar", "40", "ans" },
								{ "7", "de-007", "lllvar", "300", "ans" },
								{ "8", "de-008", "fix", "8", "n" },
								{ "9", "de-009", "bfix", "1", "b" },
								{ "10", "de-010", "llvar", "10", "ans" },
								{ "11", "de-011", "fix","1", "ans" },
								{ "12", "de-012", "lllvar","99", "ans" },
								{ "13", "de-013", "lllvar","99", "ans" },
								{ "14", "de-014", "llvar","40", "ans" },
								{ "15", "de-015", "fix","2", "ans" },
								{ "16", "de-016", "llvar","20", "ans" },
								{ "17", "de-017", "fix","2", "ans" },
								{ "18", "de-018", "llvar", "15", "ans" },
								{ "19", "de-019", "llvar", "15", "ans" },
								{ "20", "de-020", "llvar", "15", "ans" },
								{ "21", "de-021", "llvar", "15", "ans" },
								{ "22", "de-022", "lllvar", "120", "ans" },
								{ "23", "de-023", "llvar", "20", "ans" },
								{ "24", "de-024", "llvar", "20", "ans" },
								{ "25", "de-025", "fix", "1", "n" },
								{ "26", "de-026", "llvar", "50", "ans" },
								{ "27", "de-027", "llvar", "50", "ans" },
								{ "28", "de-028", "fix", "10", "ans" },
								{ "29", "de-029", "llvar", "99", "ans" },
								{ "30", "de-030", "llvar", "99", "ans" },
								{ "31", "de-031", "llvar", "40", "ans" },
								{ "32", "de-032", "fix", "2", "ans" },
								{ "33", "de-033", "llvar", "20", "ans" },
								{ "34", "de-034", "fix", "5", "n" },
								{ "35", "de-035", "fix", "1", "n" },
								{ "36", "de-036", "fix", "1", "n" },
								{ "37", "de-037", "fix", "1", "n" },
								{ "38", "de-038", "fix", "1", "n" },
								{ "39", "de-039", "fix", "1", "n" },
								{ "40", "de-040", "fix", "1", "n" },
								{ "41", "de-041", "fix", "1", "n" },
								{ "42", "de-042", "fix", "1", "ans" },
								{ "43", "de-043", "llvar", "50", "ans" },
								{ "44", "de-044", "lllvar", "100", "ans" },
								{ "45", "de-045", "lllvar", "100", "ans" },
								{ "46", "de-046", "llvar", "99", "ans" },
								{ "47", "de-047", "fix", "11", "n" },
								{ "48", "de-048", "llvar", "30", "ans" },
								{ "49", "de-049", "fix", "1", "n" },
								{ "50", "de-050", "llvar", "99" "ans" },
								{ "51", "de-051", "llvar", "99", "ans" },
								{ "52", "de-052", "llvar", "20", "ans" },
								{ "53", "de-053", "llvar", "99", "ans" },
								{ "54", "de-054", "fix", "10", "n" },
								{ "55", "de-055", "fix", "10", "ans" },
								{ "56", "de-056", "llvar", "99", "ans" },
								{ "57", "de-057", "fix", "10", "n" },
								{ "58", "de-058", "llvar", "99", "ans" },
								{ "59", "de-059", "llvar", "99", "ans" },
								{ "60", "de-060", "fix", "11", "n" },
								{ "61", "de-061", "fix", "1", "n" },
								{ "62", "de-062", "fix", "1", "n" },
								{ "63", "de-063", "lllvar", "100", "ans" },
								{ "64", "de-064", "lllvar", "100", "ans" },
								{ "65", "de-065", "lllvar", "500", "ans" },
								{ "67", "de-067", "lllvar", "100", "ans" },
								{ "68", "de-068", "lllvar", "100", "ans" },
								{ "69", "de-069", "lllvar", "100", "ans" },
								{ "70", "de-070", "lllvar", "300", "ans" },
								{ "71", "de-071", "llvar", "30","ans" },
								{ "72", "de-072", "llvar", "11", "n" },
								{ "73", "de-073", "llvar", "11", "n" },
								{ "74", "de-074", "llvar", "20", "ans" },
								{ "75", "de-075", "lllvar", "300", "ans" },
								{ "76", "de-076", "fix", "10", "n" },
								{ "77", "de-077", "fix", "2", "n" },
								{ "78", "de-078", "lllvar", "200", "ans" },
								{ "79","de-079", "llvar", "20", "ans" },
								{ "80", "de-080", "fix", "1", "n" },
								{ "81", "de-081", "fix", "1", "n" },
								{ "82", "de-082", "llvar", "99", "ans" },
								{ "83", "de-083", "llvar", "99", "ans" },
								{ "84", "de-084", "llvar", "40", "ans" },
								{ "85", "de-085", "fix", "2", "ans" },
								{ "86", "de-086", "llvar", "20", "ans" },
								{ "87", "de-087", "fix", "5", "ans" },
								{ "88", "de-088", "fix", "11", "n" },
								{ "89", "de-089", "fix", "4", "n" },
								{ "90", "de-090", "fix", "11", "n" },
								{ "91", "de-091", "lllvar", "255", "ans" },
								{ "92", "de-092", "fix", "11", "n" },
								{ "93", "de-093", "fix", "11", "n" },
								{ "94", "de-094", "lllvar", "255", "ans" },
								{ "95", "de-095", "lllvar", "255", "ans" },
								{ "96", "de-096", "fix", "10", "n" },
								{ "97", "de-097", "fix", "10", "n" },
								{ "98", "de-098", "fix", "11", "n" },
								{ "99", "de-099", "lllvar", "255", "ans" },
								{ "100", "de-100", "lllvar", "255", "ans" },
								{ "101", "de-101", "fix", "11", "n" },
								{ "102", "de-102", "lllvar", "255", "ans" },
								{ "103", "de-103", "lllvar", "255", "ans" },
								{ "104", "de-104", "lllvar", "255", "ans" },
								{ "105", "de-105", "lllvar", "255", "ans" },
								{ "106", "de-106", "llvar", "99", "ans" },
								{ "107", "de-107", "llvar", "99", "ans" },
								{ "108", "de-108", "llvar", "40", "ans" },
								{ "109", "de-109", "fix", "2", "ans" },
								{ "110", "de-110", "llvar", "20", "ans" },
								{ "111", "de-111", "fix", "3", "ans" },
								{ "112", "de-112", "fix", "1", "n" },
								{ "113", "de-113", "llvar", "11", "ans" },
								{ "114", "de-114", "llvar", "11", "ans" },
								{ "115", "de-115", "fix", "11", "n" },
								{ "116", "de-116", "fix", "11", "n" },
								{ "117", "de-117", "fix", "11", "n" },
								{ "118", "de-118", "fix", "15", "ans" },
								{ "119", "de-119", "fix","4", "n" },
								{ "120", "de-120", "fix", "11", "n" },
								{ "121", "de-121", "fix", "11", "n" },
								{ "122", "de-122", "fix", "11", "n" },
								{ "123", "de-123", "fix", "2", "n" },
								{ "124", "de-124", "fix", "1", "n" },
								{ "125", "de-125", "fix", "1", "n" },
								{ "126", "de-126", "fix", "1", "n" },
								{ "127", "de-127", "lllvar", "255", "ans" },
								{ "128", "de-128", "lllvar", "255", "ans" },
								{ "129", "de-129", "lllvar", "255", "ans" },
								{ "130", "de-130", "lllvar", "255", "ans" },
								{ "131", "de-131", "llvar", "11", "ans" },
								{ "132", "de-132", "llvar", "11", "ans" },
								{ "133", "de-133", "llvar" "10", "ans" },
								{ "134", "de-134", "llvar", "99", "ans" },
								{ "135", "de-135", "fix", "2", "n" },
								{ "136", "de-136", "llvar", "25", "ans" },
								{ "137", "de-137", "llvar", "45", "ans" },
								{ "138", "de-138", "fix", "8", "n" },
								{ "139", "de-139", "fix", "8", "n" },
								{ "140", "de-140", "fix", "1", "n" },
								{ "141", "de-141", "fix", "10", "n" },
								{ "142", "de-142", "lllvar", "255", "ans" },
								{ "143", "de-143", "fix", "1", "n" },
								{ "144", "de-144", "fix", "10", "n" },
								{ "145", "de-145", "fix", "10", "n" },
								{ "146", "de-146", "fix", "14", "n" },
								{ "147", "de-147", "llvar", "10", "ans" },
								{ "148", "de-148", "lllvar", "255", "ans" },
								{ "149", "de-149", "llvar", "99", "ans" },
								{ "150", "de-150", "fix", "10", "n" },
								{ "151", "de-151", "fix", "1", "n" },
								{ "152", "de-152", "fix", "14","n" },
								{ "153", "de-153", "fix", "14", "n" },
								{ "154", "de-154", "fix", "10", "n" },
								{ "155", "de-155", "fix", "1", "n" },
								{ "156", "de-156", "lllvar", "255", "ans" },
								{ "157", "de-157", "fix", "2", "n" },
								{ "158", "de-158", "fix", "1", "n" },
								{ "159", "de-159", "fix", "3", "n" },
								{ "160", "de-160", "fix", "1", "n" },
								{ "161", "de-161", "fix", "3", "n" },
								{ "162", "de-162", "fix", "3", "n" },
								{ "163", "de-163", "fix", "3", "n" },
								{ "164", "de-164", "fix", "3", "n" },
								{ "165", "de-165", "fix", "1", "n" },
								{ "166", "de-166", "fix", "1", "n" },
								{ "167", "de-167", "fix", "1", "n" },
								{ "168", "de-168", "fix", "1", "n" },
								{ "169", "de-169", "fix", "1", "n" },
								{ "170", "de-170", "fix", "1", "n" },
								{ "171", "de-171", "fix", "1", "n" },
								{ "172", "de-172", "fix", "1", "n" },
								{ "173", "de-173", "fix", "1", "n" },
								{ "174", "de-174", "fix", "1", "n" },
								{ "175", "de-175", "fix", "1", "n" },
								{ "176", "de-176", "fix", "1", "n" },
								{ "177", "de-177", "fix", "1", "n" },
								{ "178", "de-178", "fix", "1", "n" },
								{ "179", "de-179", "fix", "10", "n" },
								{ "180", "de-180", "fix", "2", "n" },
								{ "181", "de-181", "llvar", "99", "ans" },
								{ "182", "de-182", "llvar", "99", "ans" },
								{ "183", "de-183", "llvar", "40", "ans" },
								{ "184", "de-184", "fix", "2", "ans" },
								{ "185", "de-185", "llvar", "20", "ans" },
								{ "186", "de-186", "fix", "5", "ans" },
								{ "187", "de-187", "lllvar", "255", "ans" },
								{ "188", "de-188", "lllvar", "255", "ans" },
								{ "189", "de-189", "fix", "1", "n" },
								{ "190", "de-190", "fix", "10", "n" },
								{ "191", "de-191", "lllvar", "100", "ans" },
								{ "192", "de-192", "lllvar", "100", "ans" }};

    return new IsoParser(arrMyIso114, arrISO114);
}


IsoParser *CoreTransaction::getIsoParser48()
{
    const int arrISO48 = 20;

    string arrMyIso48[][5] = { { "2", "de-002", "llvar", "99", "ans" },
							   { "3", "de-003", "fix", "1", "n" },
							   { "4", "de-004", "fix", "5", "n" },
							   { "5", "de-005", "fix", "1", "ans" },
							   { "6", "de-006", "llvar", "20", "ans" },
							   { "7", "de-007", "llvar", "20", "ans" },
							   { "8", "de-008", "llvar", "99", "ans" },
							   { "9", "de-009", "llvar", "99", "ans" },
							   { "10", "de-010", "llvar", "10", "ans" },
							   { "11", "de-011", "llvar", "20", "ans" },
							   { "12", "de-012", "llvar", "20", "ans" },
							   { "13", "de-013", "llvar", "20", "ans" },
							   { "14", "de-014", "fix", "1", "n" },
							   { "15", "de-015", "llvar", "40", "ans" },
							   { "16", "de-016", "llvar", "30", "ans" },
							   { "25", "de-025", "blllvar", "255", "b" },
							   { "26", "de-026", "fix", "10", "n" },
							   { "27", "de-027", "lllvar", "300", "ans" },
							   { "28", "de-028", "llvar", "20", "ans" },
							   { "29", "de-029", "fix", "1", "n" }};

    return new IsoParser(arrMyIso48, arrISO48);
}


IsoParser *CoreTransaction::getIsoParser55()
{
    const int arrISO55 = 4;

    string arrMyIso55[][5] = {  { "2", "de-002", "llvar", "10", "ans" },
								{ "3", "de-003", "llvar", "10", "ans" },
								{ "4", "de-004", "fix", "10", "n" },
								{ "5", "de-005", "fix", "10", "n" }};

    return new IsoParser(arrMyIso55, arrISO55);
}


IsoParser *CoreTransaction::getIsoParser62()
{
    const int arrISO62 = 4;

    string arrMyIso62[][5] = {  { "2", "de-002", "llvar", "30", "ans" },
								{ "3", "de-003", "llvar", "10", "ans" },
								{ "4", "de-004", "llvar", "10", "ans" },
								{ "5", "de-005", "fix", "10", "n" }};

    return new IsoParser(arrMyIso62, arrISO62);
}


IsoParser *CoreTransaction::getIsoParser121()
{
    const int arrISO121 = 185;

    string arrMyIso121[][5] = { { "2", "de-002", "fix","10", "n" },
								{ "3", "de-003", "fix","10", "n" },
								{ "4", "de-004", "lllvar","100", "ans" },
								{ "5", "de-005", "lllvar","100", "ans" },
								{ "6", "de-006", "llvar","40", "ans" },
								{ "7", "de-007", "fix","2", "an" },
								{ "8", "de-008", "llvar","20", "ans" },
								{ "9", "de-009", "llvar","10", "ans" },
								{ "10", "de-010", "lllvar","100", "ans" },
								{ "11", "de-011", "lllvar","100", "ans" },
								{ "12", "de-012", "llvar","40", "ans" },
								{ "13", "de-013", "llvar","45", "ans" },
								{ "14", "de-014", "llvar","20", "ans" },
								{ "15", "de-015", "llvar","45", "ans" },
								{ "16", "de-016", "llvar","45", "ans" },
								{ "17", "de-017", "llvar","45", "ans" },
								{ "18", "de-018", "llvar","40", "ans" },
								{ "19", "de-019", "llvar","45", "ans" },
								{ "20", "de-020", "llvar","45", "ans" },
								{ "21", "de-021", "llvar","10", "ans" },
								{ "22", "de-022", "fix","11", "n" },
								{ "23", "de-023", "fix","11", "n" },
								{ "24", "de-024", "fix","11", "n" },
								{ "25", "de-025", "lllvar","255", "ans" },
								{ "26", "de-026", "llvar","45", "ans" },
								{ "27", "de-027", "lllvar","255", "ans" },
                                { "28", "de-028", "llvar","255", "ans" },
                                { "29", "de-029", "fix","1", "ans" },
								{ "30", "de-030", "fix","11", "n" },
                                { "31", "de-031", "lllvar","150", "ans" },
								{ "32", "de-032", "fix","1", "ans" },
								{ "33", "de-033", "fix","1", "ans" },
								{ "34", "de-034", "fix","1", "ans" },
								{ "35", "de-035", "fix","1", "ans" },
								{ "36", "de-036", "llvar", "45", "ans" },
								{ "37", "de-037", "llvar", "45", "ans" },
								{ "38", "de-038", "llvar","11", "n" },
								{ "39", "de-039", "llvar","11", "n" },
								{ "40", "de-040", "llvar","11", "n" },
								{ "41", "de-041", "llvar","45", "an" },
                                { "42", "de-042", "llvar","45", "an" },
                                { "43", "de-043", "llvar","45", "an" },
                                { "44", "de-044", "llvar","45", "ans" },
								{ "45", "de-045", "llvar","45", "ans" },
								{ "46", "de-046", "llvar","45", "an" },
								{ "47", "de-047", "fix","1", "ans" },
								{ "48", "de-048", "llvar","11", "n" },
								{ "49", "de-049", "llvar","11", "n" },
								{ "50", "de-050", "llvar","11", "n" },
								{ "51", "de-051", "llvar","45", "n" },
								{ "52", "de-052", "llvar","11", "n" },
								{ "53", "de-053", "fix","1", "ans" },
								{ "54", "de-054", "fix","11", "n" },
								{ "55", "de-055", "llvar","45", "ans" },
								{ "56", "de-056", "llvar","45", "ans" },
								{ "57", "de-057", "llvar","45", "ans" },
								{ "58", "de-058", "llvar","45", "ans" },
								{ "59", "de-059", "llvar","45", "ans" },
								{ "60", "de-060", "fix","1", "ans" },
								{ "61", "de-061", "llvar","45", "ans" },
								{ "62", "de-062", "llvar","45", "ans" },
								{ "63", "de-063", "llvar","11", "ans" },
								{ "64", "de-064", "llvar","45", "ans" },
								{ "65", "de-065", "llvar","11", "n" },
								{ "66", "de-066", "llvar","11", "n" },
								{ "67", "de-067", "llvar","45", "ans" },
								{ "68", "de-068", "llvar","45", "ans" },
								{ "69", "de-069", "fix","1", "ans" },
								{ "70", "de-070", "llvar","11", "n" },
								{ "71", "de-071", "llvar","45", "ans" },
								{ "72", "de-072", "llvar","45", "ans" },
								{ "73", "de-073", "llvar", "11", "n" },
								{ "74", "de-074", "llvar", "45", "an" },
								{ "75", "de-075", "fix","11", "n" },
								{ "76", "de-076", "llvar", "11", "n" },
								{ "77", "de-077", "llvar","45", "ans" },
								{ "78", "de-078", "fix","1", "an" },
                                { "79", "de-079", "llvar","11", "n" },
								{ "80", "de-080", "fix", "11" "n" },
                                { "81", "de-081", "llvar","45", "ans" },
								{ "82", "de-082", "llvar","45", "ans" },
								{ "83", "de-083", "llvar","45", "ans" },
                                { "84", "de-084", "fix","11", "n" },
                                { "85", "de-085", "fix","11", "n" },
								{ "86", "de-086", "llvar", "45", "ans" },
								{ "87", "de-087", "llvar", "45", "ans" },
								{ "88", "de-088", "llvar","11", "n" },
								{ "89", "de-089", "fix","1", "n" },
								{ "90", "de-090", "fix", "1", "ans" },
								{ "91", "de-091", "fix", "1", "ans" },
								{ "92", "de-092", "fix", "1", "ans" },
								{ "93", "de-093", "llvar", "45", "n" },
								{ "94", "de-094", "llvar", "45", "n" },
								{ "95", "de-095", "llvar", "11", "n" },
								{ "96", "de-096", "fix", "1", "n" },
								{ "97", "de-097", "llvar", "11", "n" },
								{ "98", "de-098", "llvar", "45", "an" },
								{ "99", "de-099", "llvar", "45", "an" },
								{ "100", "de-100", "llvar", "45", "an" },
								{ "101", "de-101", "llvar", "45", "an" },
								{ "102", "de-102", "llvar", "45", "an" },
								{ "103", "de-103", "llvar", "45", "an" },
								{ "104", "de-104", "llvar", "45", "an" },
								{ "105", "de-105", "llvar", "45", "an" },
								{ "106", "de-106", "llvar", "45", "an" },
								{ "107", "de-107", "llvar", "45", "an" },
								{ "108", "de-108", "llvar", "45", "an" },
								{ "109", "de-109", "llvar", "11", "n" },
								{ "110", "de-110", "llvar", "11", "n" },
								{ "111", "de-111", "llvar", "45", "ans" },
								{ "112", "de-112", "fix","11", "n" },
								{ "113", "de-113", "fix","11", "n" },
								{ "114", "de-114", "fix","11", "n" },
								{ "115", "de-115", "llvar","20", "an" },
								{ "116", "de-116", "llvar","45", "an" },
								{ "117", "de-117", "fix","10", "n" },
								{ "118", "de-118", "lllvar","255", "ans" },
								{ "119", "de-119", "llvar","11", "ans" },
								{ "120", "de-120", "llvar","11", "ans" },
								{ "121", "de-121", "llvar","45", "an" },
								{ "122", "de-122", "llvar","45", "an" },
								{ "123", "de-123", "llvar","45", "an" },
								{ "124", "de-124", "llvar","45", "an" },
								{ "125", "de-125", "llvar","45", "an" },
								{ "126", "de-126", "fix","1", "an" },
                                { "127", "de-127", "fix","16", "ans" },
								{ "128", "de-128", "fix","11", "n" },
								{ "129", "de-129", "llvar","45", "ans" },
								{ "130", "de-130", "llvar","45", "ans" },
								{ "131", "de-131", "llvar","45", "ans" },
								{ "132", "de-132", "llvar","45", "ans" },
								{ "133", "de-133", "llvar","45", "ans"},
								{ "134", "de-134", "llvar","45", "ans"},
								{ "135", "de-135", "llvar","45", "ans"},
								{ "136", "de-136", "llvar","45", "ans"},
								{ "137", "de-137", "llvar","45", "ans" },
								{ "140", "de-140", "llvar","45", "ans" },
								{ "141", "de-141", "llvar","45", "ans" },
								{ "142", "de-142", "llvar", "45", "an" },
								{ "143", "de-143", "llvar", "11", "n" },
								{ "144", "de-144", "llvar", "45", "an" },
								{ "145", "de-145", "llvar", "45", "an" },
								{ "146", "de-146", "llvar", "45", "an" },
								{ "147", "de-147", "llvar","20", "ans" },
								{ "148", "de-148", "fix","3", "n" },
								{ "149", "de-149", "llvar","20", "ans" },
								{ "150", "de-150", "llvar","45", "ans" },
								{ "151", "de-151", "llvar","45", "ans" },
								{ "152", "de-152", "fix","1", "n" },
								{ "153", "de-153", "fix","11", "n" },
								{ "154", "de-154", "fix","11", "n" },
								{ "155", "de-155", "fix","11", "n" },
                                { "156", "de-156", "fix","11", "n" },
                                { "157", "de-157", "fix","1", "n" },
                                { "158", "de-158", "llvar","10", "ans" },
                                { "159", "de-159", "fix", "10", "n" },
                                { "160", "de-160", "fix", "1", "n" }, //TOB Retail
                                { "161", "de-161", "fix", "1", "n" }, // TOB Hospitality
                                { "162", "de-162", "fix", "1", "n" }, // TOB Online
                                { "163", "de-163", "fix", "1", "n" }, // TOB Restaurant/Bar
                                { "164", "de-164", "fix", "1", "n" }, // TOB Mail order/Telephone order
                                { "165", "de-165", "fix", "1", "n" }, // Quantity location
                                { "166", "de-166", "fix", "1", "n" }, // Merchant Account
                                { "167", "de-167", "llvar", "11", "n" }, // Phone Extension
                                { "168", "de-168", "llvar", "11", "n" }, // Phone Extension 2
                                { "169", "de-169", "lllvar","255", "ans" },
                                { "170", "de-170", "llllvar", "9999", "ans" },
                                { "171", "de-171", "llvar","45", "ans" },
                                { "172", "de-172", "llvar","45", "ans" },
                                { "173", "de-173", "llvar","10", "ans" },
                                { "174", "de-174", "llvar","10", "ans" },
                                { "175", "de-175", "lllvar","255", "ans" },
                                { "176", "de-176", "llvar","10", "ans" },
                                { "177", "de-177", "llvar","10", "ans" },
                                { "178", "de-178", "lllvar", "255", "ans" },
                                { "179", "de-179", "fix", "11", "n" },
                                { "180", "de-180", "fix", "11", "n" },
                                { "181", "de-181", "llvar", "45", "ans" },
                                { "182", "de-182", "llvar","45", "ans" },
                                { "183", "de-183", "fix", "11", "n" },
                                { "184", "de-184", "llvar", "20", "ans" },
                                { "185", "de-185", "llvar", "20", "ans" },
                                { "186", "de-186", "llvar", "20", "ans" },
                                { "187", "de-187", "llvar", "20", "ans" },
                                { "188", "de-188", "llvar", "45", "ans" }
                                };

    return new IsoParser(arrMyIso121, arrISO121);
}

bool CoreTransaction::BuildISOFormater(const bool if47,const bool if48,const bool if55,const bool if62,const bool if114,const bool if120,const bool if121,hasresult &hResult,string &sFormatedRsp,string &mti)
{

    try
    {
        IsoParser *myiso;
        IsoParser *myiso47;
        IsoParser *myiso48;
        IsoParser *myiso114;
        IsoParser *myiso55;
        IsoParser *myiso62;
        IsoParser *myiso121;
        IsoParser *myiso120;


        myiso = this->getIsoParser0();
        myiso47 = this->getIsoParser47();
		myiso48 = this->getIsoParser48();
		myiso114 = this->getIsoParser114();
		myiso55 = this->getIsoParser55();
		myiso62 = this->getIsoParser62();
		myiso121 = this->getIsoParser121();
        myiso120 = this->getIsoParser120();


        string aux="";
        //check if its necessary add field 47
        if(if47)
			myiso47->GetFormatedRspSub(aux, "47", hResult, 1);

        aux="";
        //check if its necessary add field 48
        if(if48)
			myiso48->GetFormatedRspSub(aux, "48", hResult, 1);

        aux="";
		//check if its necessary add field 55
		if(if55)
			myiso55->GetFormatedRspSub(aux, "55", hResult, 1);

        aux="";
		//check if its necessary add field 114
		if(if114)
			myiso114->GetFormatedRspSub(aux, "114", hResult, 1);

        aux="";
		//check if its necessary add field 114
		if(if62)
			myiso62->GetFormatedRspSub(aux, "62", hResult, 1);

        aux="";
		//check if its necessary add field 114
		if(if121)
			myiso121->GetFormatedRspSub(aux, "121", hResult, 1);

        aux="";
		//check if its necessary add field 114
		if(if120)
			myiso120->GetFormatedRspSub(aux, "120", hResult, 1);


		myiso->GetFormatedRsp(mti,sFormatedRsp, "", hResult, 1);


		delete myiso;
        delete myiso47;
		delete myiso48;
		delete myiso114;
		delete myiso55;
		delete myiso62;
		delete myiso121;
        delete myiso120;


        return true;
    }
    catch(...)
    {
        return false;
    }

}


void CoreTransaction::buildCommonFields(hasresult &hData)
{
    //get current date
    /*struct tm *tmPtr;
    time_t now = time(NULL);
    tmPtr = localtime(&now);

    char Temp[64];

    //P7
    memset(Temp,0,sizeof(Temp));
    strftime(Temp, 11, "%m%d%H%M%S", tmPtr);
    hResult["7"]=Temp;

    //P12
    memset(Temp,0,sizeof(Temp));
    strftime(&Temp[2], 13, "%y%m%d%H%M%S", tmPtr);
    memcpy(Temp,"21",2);
    hResult["12"]=Temp;*/
}
