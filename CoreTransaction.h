

#ifndef __BUILD_ISO_H__
#define __BUILD_ISO_H__


#include "IsoParser.h"
#include <string>

using namespace std;





class CoreTransaction
{
    public:
        CoreTransaction();
        virtual string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog)=0;
        bool ProceessComunication(const char * const hostname,const int port,string &dataOut,const unsigned int sleep,string &dataIn,const bool waitResponse);
        bool ProceessComunicationHTTP(const char * const hostname,const int port,const string &dataOut,string &dataIn);

        bool ProceessComunication(string &dataOut,const unsigned int sleep,string &dataIn,const bool waitResponse);
        bool ProceessComunicationHTTP(const string &dataOut,string &dataIn);

        bool BuildISOFormater(const bool if47,const bool if48,const bool if55,const bool if62,const bool if114,const bool if120,const bool if121,hasresult &hResult,string &sFormatedRsp,string &mti);
        bool BuildISOFormater(hasresult &hResult,string &sFormatedRsp,string &mti);
        bool GetFieldsFromISO(string &Input,string *Fields,const int numFields,string *out);

    private:
        //methods for get instance of each type of iso
        IsoParser *getIsoParser0();
        IsoParser *getIsoParser120();
        IsoParser *getIsoParser47();
        IsoParser *getIsoParser114();
        IsoParser *getIsoParser48();
        IsoParser *getIsoParser55();
        IsoParser *getIsoParser62();
        IsoParser *getIsoParser121();

    protected:
        const string messageFailedInvalidResponse;
        const string messageFailedPackISO;
        const string messageFailedCommunications;
        const string messageFailedUnpackISO;
        const string messageFailedException;
        const string messageOK;
        const string messageResponseTrue;
        const string messageResponseFalse;

        //method for common fields
        void buildCommonFields(hasresult &hData);
};

#endif
