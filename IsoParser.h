#pragma once


#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
//#include <hash_map>
#include <map>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

#define LEN_BYTE	8
//#define VERBOSE true
//#define VERBOSE_BASIC true
//#define VERBOSE_IMP true

typedef unsigned char byte;

using namespace std;
using namespace __gnu_cxx;

class IsoObj {
public:
	string sType;
	int iLength;
	string sData;
	string sName;
	string sTyDa;
};

#ifndef ltstrh_H_
#define ltstrh_H_
class stringhasher //: public stdext::hash_compare <std::string>
{
public:
  size_t operator() (const std::string& sp) const
  {
        size_t hash = 1;
        const char * s = sp.c_str();
        for (; *s; ++s) hash = hash * 5 + *s;
        return hash;
  }


  bool operator() (const std::string& s1, const std::string& s2) const
  {
      string s1Tmp = "";
      string s2Tmp = "";
      string s1Tmp_S = "";
      string s2Tmp_S = "";
      bool rDt = false;

      s1Tmp = s1.substr(0,s1.find("."));
      if(s1Tmp != s1)
        s1Tmp_S = s1.substr(s1.find(".")+1);
      s2Tmp = s2.substr(0,s2.find("."));
      if(s2Tmp != s2)
        s2Tmp_S = s2.substr(s2.find(".")+1);

      if(s1Tmp != s2Tmp)
        rDt = atoi( s1Tmp.c_str() ) < atoi( s2Tmp.c_str() );
      else if(s1Tmp == s2Tmp)
            rDt = atoi( s2Tmp_S.c_str() ) < atoi( s2Tmp_S.c_str() );

      return rDt;
  }
};

struct strCmp {
    bool operator()( std::string s1, std::string s2 ) const {

      string s1Tmp = "";
      string s2Tmp = "";
      string s1Tmp_S = "";
      string s2Tmp_S = "";
      bool rDt = false;

      s1Tmp = s1.substr(0,s1.find("."));
      if(s1Tmp != s1)
        s1Tmp_S = s1.substr(s1.find(".")+1);
      s2Tmp = s2.substr(0,s2.find("."));
      if(s2Tmp != s2)
        s2Tmp_S = s2.substr(s2.find(".")+1);

      if(s1Tmp != s2Tmp)
        rDt = atoi( s1Tmp.c_str() ) < atoi( s2Tmp.c_str() );
      else if(s1Tmp == s2Tmp)
            rDt = atoi( s1Tmp_S.c_str() ) < atoi( s2Tmp_S.c_str() );

      return rDt;
    }
};
#endif



typedef map< string, string, strCmp > hasresult;
typedef map< string, IsoObj, strCmp > hashmap;



class IsoParser
{
public:

	IsoParser(string sPos, string sName, string sType, string sLength, string sTyDa);
	IsoParser(string isoData[][5], int aSize);
	IsoParser(void);
	~IsoParser(void);
	hashmap IsoCmp;
	vector<string> vElements;
	hasresult hMessSec;
	template <class T>
	bool from_string(T& t, const std::string& s, std::ios_base& (*f)(std::ios_base&));
	template <typename T>
	string NumToStr(T number);
	bool ParseFromASCII(string sData);
	bool ParseFromASCIISubField(string sData);
	bool ParseField(IsoObj &isObj, string buf, int &offset, int iLen);

	char XtoC(int x);
	char CtoX(char x[]);
	string B(string buf, int off, int len);

	string ReadFixRaw(string buf, int &offset, int len);
	string ReadVar2Raw(string buf, int &offset, int unused);
	string ReadVar3Raw(string buf, int &offset, int unused);
	string ReadVar4Raw(string buf, int &offset, int unused);
	string ReadVar2Packed(string buf, int &offset, int unused);
	string ReadVar3Packed(string buf, int &offset, int unused);
	string ReadVar4Packed(string buf, int &offset, int unused);
	string ReadFixPacked(string buf, int &offset, int len);
	string GetField(int iIndex);
	bool GetFormatedStr(string &sForStr, string sWElem);
	bool GetFormatedStrSub(string &sForStr, string sWElem, string sAnt, int iPAdd);
    bool GetFormatedRspSub48(string &sForStr, string sWElem, hasresult &hCont, int iPAdd);

    bool GetFormatedRsp(string &mti,string &sForStr, string sWElem, hasresult hCont, int iPAdd);

	bool GetFormatedRsp( string &sForStr, string sWElem, hasresult hCont, int iPAdd);
	bool GetFormatedRspSub(string &sForStr, string sWElem, hasresult &hCont, int iPAdd);
	hasresult GetResult( );
	bool PackField(IsoObj isObj, string &buf, string sData, int iLen);
	bool WriteFixRaw(string &buf, string sData, string sTyDa, int iLen);
	bool WriteVar2Raw(string &buf, string sData, string sTyDa, int iLen);
	bool WriteVar3Raw(string &buf, string sData, string sTyDa, int iLen);
	bool WriteVar4Raw(string &buf, string sData, string sTyDa, int iLen);
	bool WriteVar2Packed(string &buf, string sData, string sTyDa, int iLen);
	bool WriteVar3Packed(string &buf, string sData, string sTyDa, int iLen);
	bool WriteVar4Packed(string &buf, string sData, string sTyDa, int iLen);
	bool WriteFixPacked(string &buf, string sData, string sTyDa, int iLen);
	int SetBitmaps(byte * primaryBitmap, byte * secondaryBitmap, byte * tertiaryBitmap, string sKey);
	bool ParseFromASCIIB(string sData);
	bool ParseFromASCIISubFieldB(string sData);
	static string OrganizeStrIsoData(string isoData[][5], int aSize, int iIndex);
	bool AddData(string key, string Data);

};
