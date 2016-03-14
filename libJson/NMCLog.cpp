

#include "NMCLog.h"
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <iostream>


void NMCLog::Log(string log)
{

    char fileName [] = "/srv/nmc/NMCLibLogs.log";

    FILE *pfile  = fopen (fileName, "r");

    if (pfile) //Si existe
    {
        fclose(pfile);

        try
        {
            time_t t;
            struct tm *tm;
            char dateTime[100];

            t=time(NULL);
            tm=localtime(&t);
            strftime(dateTime, 100, "%y/%m/%d %H:%M:%S", tm);

            ofstream fileLog;  // objeto de la clase ofstream

            fileLog.open(fileName,ios_base::app);
            //fileLog.seekp(ios_base::end);
            fileLog << dateTime << " [ " << log << " ]" << endl;

            fileLog.close();
        }
        catch(...)
        {
            cout << "Something Wrong With Logs" << endl;
        }

    }

}
