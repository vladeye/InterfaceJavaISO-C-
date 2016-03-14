#include "IsoParser.h"
#include "utility.h"
#include "string.h"

template <class T>
bool IsoParser::from_string(T& t,
                 const std::string& s,
                 std::ios_base& (*f)(std::ios_base&))
{
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}

template <typename T>
string IsoParser::NumToStr(T number)
{
	return dynamic_cast<std::stringstream *> (&(std::stringstream() << number))->str();
}

IsoParser::IsoParser(void)
{


}

IsoParser::IsoParser(string isoData[][5], int aSize){

	int iLen;

	for(int iQty=0 ;iQty < aSize; iQty++){
#ifdef VERBOSE_BASIC
        cout<<"---------------- "<<isoData[iQty][1]<<endl;
#endif
		IsoCmp[isoData[iQty][0]].sName = isoData[iQty][1];
		IsoCmp[isoData[iQty][0]].sType = isoData[iQty][2];
		from_string<int>(iLen, isoData[iQty][3], std::dec);
		IsoCmp[isoData[iQty][0]].iLength = iLen;
		IsoCmp[isoData[iQty][0]].sTyDa =  isoData[iQty][4];
	}
}

IsoParser::IsoParser(string sPos, string sName, string sType, string sLength, string sTyDa)
{
	vector<string> vPos;
	vector<string> vName;
	vector<string> vType;
	vector<string> vLength;
	vector<string> vTyDa;


	int iCo = 0;
	int iLen;

	utility uPar;
	uPar.Tokenize(sPos, vPos, ",");
	uPar.Tokenize(sName, vName, ",");
	uPar.Tokenize(sType, vType, ",");
	uPar.Tokenize(sLength, vLength, ",");
	uPar.Tokenize(sTyDa, vTyDa, ",");

	for(iCo = 0;iCo < (int)vPos.size();iCo++)
	{
		IsoCmp[vPos[iCo]].sName = vName[iCo];
		IsoCmp[vPos[iCo]].sType = vType[iCo];

#ifdef VERBOSE_BASIC
		cout << "Field : " << vPos[iCo] << "-Type : " << vType[iCo] << "-Length : " << vLength[iCo] << " --- "<<endl;
#endif
		from_string<int>(iLen, vLength[iCo], std::dec);
		IsoCmp[vPos[iCo]].iLength = iLen;
		IsoCmp[vPos[iCo]].sTyDa =  vTyDa[iCo];
	}

}


bool IsoParser::ParseFromASCII(string sData){
	string sMIT = sData.substr(0,4);
	string sPrimaryBitmap = sData.substr(4,16);
	string sSecondaryBitmap;
	string sTertiaryBitmap;

	byte primaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte secondaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte tertiaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int iCo = 0;
	int offset = 20;

	for(iCo = 0;iCo < LEN_BYTE;iCo++){
		std::string str(1, static_cast<char>(std::strtoul(sPrimaryBitmap.substr(iCo*2,2).c_str(), 0, 16)));
		primaryBitmap[iCo] = str.c_str()[0];
		#ifdef VERBOSE
			cout << iCo << " : " << primaryBitmap[iCo]  << " : " << int(primaryBitmap[iCo]) << endl;
		#endif
	}
	if ((primaryBitmap[0] & 128 ) > 0) {
		sSecondaryBitmap = sData.substr(offset,16);
		for(iCo = 0;iCo < LEN_BYTE;iCo++){
			std::string str(1, static_cast<char>(std::strtoul(sSecondaryBitmap.substr(iCo*2,2).c_str(), 0, 16)));
			secondaryBitmap[iCo] = str.c_str()[0];
#ifdef VERBOSE
		cout << iCo << " : " << secondaryBitmap[7]  << " : " <<int(primaryBitmap[iCo]) << endl;
#endif
		}
		offset += 16;
		if ((secondaryBitmap[0] & 128 ) > 0) {
			sTertiaryBitmap =  sData.substr(offset - 1,16);
			for(iCo = 0;iCo < LEN_BYTE;iCo++){
				std::string str(1, static_cast<char>(std::strtoul(sTertiaryBitmap.substr(iCo*2,2).c_str(), 0, 16)));
				tertiaryBitmap[iCo] = str.c_str()[0];
			}
			offset += 16;
		}
	}

	for(iCo = 0;iCo < 8;iCo++){
		if (iCo > 0){
			if ((primaryBitmap[iCo] & 128 ) > 0) {
				ParseField(IsoCmp[NumToStr((iCo * 8) + 1)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 1)].iLength);
				vElements.push_back(NumToStr((iCo * 8) + 1));
			}
		}
		if ((primaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 2)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 2)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 2));
		}
		if ((primaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 3)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 3)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 3));
		}
		if ((primaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 4)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 4)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 4));
		}
		if ((primaryBitmap[iCo] & 8 ) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 5)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 5)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 5));
		}
		if ((primaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 6)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 6)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 6));
		}
		if ((primaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 7)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 7)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 7));
		}
		if ((primaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 8)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 8)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 8));
		}
	}

	for(iCo = 0;iCo < 8;iCo++){

		if (iCo > 0){
			if ((secondaryBitmap[iCo] & 128 ) > 0){
				ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 1)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 1)].iLength);
				vElements.push_back(NumToStr((64 + (iCo * 8)) + 1));
			}
		}
		if ((secondaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 2)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 2)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 2));
		}
		if ((secondaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 3)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 3)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 3));
		}
		if ((secondaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 4)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 4)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 4));
		}
		if ((secondaryBitmap[iCo] & 8 ) > 0) {
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 5)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 5)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 5));
		}
		if ((secondaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 6)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 6)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 6));
		}
		if ((secondaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 7)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 7)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 7));
		}
		if ((secondaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 8)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 8)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 8));
		}
	}

	for(iCo = 0;iCo < 8;iCo++){
		if (iCo > 0){
			if ((tertiaryBitmap[iCo] & 128 ) > 0){
				ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 1)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 1)].iLength);
				vElements.push_back(NumToStr((128 + (iCo * 8)) + 1));
			}
		}
		if ((tertiaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 2)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 2)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 2));
		}
		if ((tertiaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 3)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 3)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 3));
		}
		if ((tertiaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 4)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 4)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 4));
		}
		if ((tertiaryBitmap[iCo] & 8 ) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 5)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 5)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 5));
		}
		if ((tertiaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 6)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 6)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 6));
		}
		if ((tertiaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 7)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 7)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 7));
		}
		if ((tertiaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 8)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 8)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 8));
		}
	}


	return true;
}

bool IsoParser::ParseFromASCIIB(string sData){
	string sPrimaryBitmap = sData.substr(4,8);
	string sSecondaryBitmap;
	string sTertiaryBitmap;

	byte primaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte secondaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte tertiaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int iCo = 0;
	int offset = 12;
	memcpy(primaryBitmap,sPrimaryBitmap.c_str(),8);
#ifdef VERBOSE
	cout << "0: " << primaryBitmap[0] << " : " << int(primaryBitmap[0]) << endl;
	cout << "1: " << primaryBitmap[1] << " : " << int(primaryBitmap[1]) << endl;
	cout << "2: " << primaryBitmap[2] << " : " << int(primaryBitmap[2]) << endl;
	cout << "3: " << primaryBitmap[3] << " : " << int(primaryBitmap[3]) << endl;
	cout << "4: " << primaryBitmap[4] << " : " << int(primaryBitmap[4]) << endl;
	cout << "5: " << primaryBitmap[5] << " : " << int(primaryBitmap[5]) << endl;
	cout << "6: " << primaryBitmap[6] << " : " << int(primaryBitmap[6]) << endl;
	cout << "7: " << primaryBitmap[7] << " : " << int(primaryBitmap[7]) << endl;
#endif

	if ((primaryBitmap[0] & 128 ) > 0) {
		sSecondaryBitmap = sData.substr(offset,8);
		memcpy(secondaryBitmap,sSecondaryBitmap.c_str(),8);
#ifdef VERBOSE
	cout << "16: " << secondaryBitmap[0] << " : " << int(secondaryBitmap[0]) << endl;
	cout << "17: " << secondaryBitmap[1] << " : " << int(secondaryBitmap[1]) << endl;
	cout << "18: " << secondaryBitmap[2] << " : " << int(secondaryBitmap[2]) << endl;
	cout << "19: " << secondaryBitmap[3] << " : " << int(secondaryBitmap[3]) << endl;
	cout << "20: " << secondaryBitmap[4] << " : " << int(secondaryBitmap[4]) << endl;
	cout << "21: " << secondaryBitmap[5] << " : " << int(secondaryBitmap[5]) << endl;
	cout << "22: " << secondaryBitmap[6] << " : " << int(secondaryBitmap[6]) << endl;
	cout << "23: " << secondaryBitmap[7] << " : " << int(secondaryBitmap[7]) << endl;
#endif
		offset += 8;
		if ((secondaryBitmap[0] & 128 ) > 0) {
			sTertiaryBitmap =  sData.substr(offset - 1,8);
			memcpy(tertiaryBitmap,sTertiaryBitmap.c_str(),8);
			offset += 8;
		}
	}

	for(iCo = 0;iCo < 8;iCo++){

		if (iCo > 0){
			if ((primaryBitmap[iCo] & 128 ) > 0) {
				ParseField(IsoCmp[NumToStr((iCo * 8) + 1)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 1)].iLength);
				vElements.push_back(NumToStr((iCo * 8) + 1));
			}
		}
		if ((primaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 2)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 2)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 2));
		}
		if ((primaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 3)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 3)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 3));
		}
		if ((primaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 4)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 4)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 4));
		}
		if ((primaryBitmap[iCo] & 8 ) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 5)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 5)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 5));
		}
		if ((primaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 6)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 6)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 6));
		}
		if ((primaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 7)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 7)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 7));
		}
		if ((primaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 8)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 8)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 8));
		}
	}

	for(iCo = 0;iCo < 8;iCo++){

		if (iCo > 0){
			if ((secondaryBitmap[iCo] & 128 ) > 0){
				ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 1)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 1)].iLength);
				vElements.push_back(NumToStr((64 + (iCo * 8)) + 1));
			}
		}
		if ((secondaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 2)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 2)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 2));
		}
		if ((secondaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 3)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 3)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 3));
		}
		if ((secondaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 4)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 4)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 4));
		}
		if ((secondaryBitmap[iCo] & 8 ) > 0) {
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 5)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 5)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 5));
		}
		if ((secondaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 6)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 6)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 6));
		}
		if ((secondaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 7)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 7)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 7));
		}
		if ((secondaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 8)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 8)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 8));
		}
	}

	for(iCo = 0;iCo < 8;iCo++){
		if (iCo > 0){
			if ((tertiaryBitmap[iCo] & 128 ) > 0){
				ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 1)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 1)].iLength);
				vElements.push_back(NumToStr((128 + (iCo * 8)) + 1));
			}
		}
		if ((tertiaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 2)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 2)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 2));
		}
		if ((tertiaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 3)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 3)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 3));
		}
		if ((tertiaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 4)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 4)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 4));
		}
		if ((tertiaryBitmap[iCo] & 8 ) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 5)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 5)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 5));
		}
		if ((tertiaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 6)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 6)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 6));
		}
		if ((tertiaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 7)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 7)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 7));
		}
		if ((tertiaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 8)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 8)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 8));
		}
	}


	return true;
}



bool IsoParser::ParseFromASCIISubField(string sData){
	string sPrimaryBitmap = sData.substr(0,16);
	string sSecondaryBitmap;
	string sTertiaryBitmap;

	byte primaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte secondaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte tertiaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int iCo = 0;
	int offset = 16;

	for(iCo = 0;iCo < LEN_BYTE;iCo++){
		std::string str(1, static_cast<char>(std::strtoul(sPrimaryBitmap.substr(iCo*2,2).c_str(), 0, 16)));
		primaryBitmap[iCo] = str.c_str()[0];
	}
	if ((primaryBitmap[0] & 128 ) > 0) {
		sSecondaryBitmap = sData.substr(offset,16);
		for(iCo = 0;iCo < LEN_BYTE;iCo++){
			std::string str(1, static_cast<char>(std::strtoul(sSecondaryBitmap.substr(iCo*2,2).c_str(), 0, 16)));
			secondaryBitmap[iCo] = str.c_str()[0];
		}
		offset += 16;
		if ((secondaryBitmap[0] & 128 ) > 0) {
			sTertiaryBitmap =  sData.substr(offset - 1,16);
			for(iCo = 0;iCo < LEN_BYTE;iCo++){
				std::string str(1, static_cast<char>(std::strtoul(sTertiaryBitmap.substr(iCo*2,2).c_str(), 0, 16)));
				tertiaryBitmap[iCo] = str.c_str()[0];
			}
			offset += 16;
		}
	}


	for(iCo = 0;iCo < 8;iCo++){
		if (iCo > 0){
			if ((primaryBitmap[iCo] & 128 ) > 0) {
				ParseField(IsoCmp[NumToStr((iCo * 8) + 1)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 1)].iLength);
				vElements.push_back(NumToStr((iCo * 8) + 1));
			}
		}
		if ((primaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 2)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 2)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 2));
		}
		if ((primaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 3)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 3)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 3));
		}
		if ((primaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 4)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 4)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 4));
		}
		if ((primaryBitmap[iCo] & 8 ) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 5)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 5)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 5));
		}
		if ((primaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 6)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 6)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 6));
		}
		if ((primaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 7)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 7)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 7));
		}
		if ((primaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 8)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 8)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 8));
		}
	}

	for(iCo = 0;iCo < 8;iCo++){

		if (iCo > 0){
			if ((secondaryBitmap[iCo] & 128 ) > 0){
				ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 1)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 1)].iLength);
				vElements.push_back(NumToStr((64 + (iCo * 8)) + 1));
			}
		}
		if ((secondaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 2)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 2)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 2));
		}
		if ((secondaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 3)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 3)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 3));
		}
		if ((secondaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 4)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 4)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 4));
		}
		if ((secondaryBitmap[iCo] & 8 ) > 0) {
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 5)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 5)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 5));
		}
		if ((secondaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 6)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 6)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 6));
		}
		if ((secondaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 7)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 7)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 7));
		}
		if ((secondaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 8)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 8)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 8));
		}
	}

	for(iCo = 0;iCo < 8;iCo++){
		if (iCo > 0){
			if ((tertiaryBitmap[iCo] & 128 ) > 0){
				ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 1)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 1)].iLength);
				vElements.push_back(NumToStr((128 + (iCo * 8)) + 1));
			}
		}
		if ((tertiaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 2)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 2)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 2));
		}
		if ((tertiaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 3)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 3)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 3));
		}
		if ((tertiaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 4)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 4)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 4));
		}
		if ((tertiaryBitmap[iCo] & 8 ) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 5)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 5)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 5));
		}
		if ((tertiaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 6)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 6)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 6));
		}
		if ((tertiaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 7)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 7)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 7));
		}
		if ((tertiaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 8)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 8)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 8));
		}
	}


	return true;
}


bool IsoParser::ParseFromASCIISubFieldB(string sData){
	string sPrimaryBitmap = sData.substr(0,8);
	string sSecondaryBitmap;
	string sTertiaryBitmap;

	byte primaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte secondaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte tertiaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int iCo = 0;
	int offset = 8;

	memcpy(primaryBitmap,sPrimaryBitmap.c_str(),8);
	if ((primaryBitmap[0] & 128 ) > 0) {
		sSecondaryBitmap = sData.substr(offset,8);
		memcpy(secondaryBitmap,sSecondaryBitmap.c_str(),8);
		offset += 8;
		if ((secondaryBitmap[0] & 128 ) > 0) {
			sTertiaryBitmap =  sData.substr(offset ,8);
			memcpy(tertiaryBitmap,sTertiaryBitmap.c_str(),8);
			offset += 8;
		}
	}

#ifdef VERBOSE_IMP
	cout << "0: " << primaryBitmap[0] << " : " << int(primaryBitmap[0]) << endl;
	cout << "1: " << primaryBitmap[1] << " : " << int(primaryBitmap[1]) << endl;
	cout << "2: " << primaryBitmap[2] << " : " << int(primaryBitmap[2]) << endl;
	cout << "3: " << primaryBitmap[3] << " : " << int(primaryBitmap[3]) << endl;
	cout << "4: " << primaryBitmap[4] << " : " << int(primaryBitmap[4]) << endl;
	cout << "5: " << primaryBitmap[5] << " : " << int(primaryBitmap[5]) << endl;
	cout << "6: " << primaryBitmap[6] << " : " << int(primaryBitmap[6]) << endl;
	cout << "7: " << primaryBitmap[7] << " : " << int(primaryBitmap[7]) << endl;
	cout << "8: " << secondaryBitmap[0] << " : " << int(secondaryBitmap[0]) << endl;
	cout << "9: " << secondaryBitmap[1] << " : " << int(secondaryBitmap[1]) << endl;
	cout << "10: " << secondaryBitmap[2] << " : " << int(secondaryBitmap[2]) << endl;
	cout << "11: " << secondaryBitmap[3] << " : " << int(secondaryBitmap[3]) << endl;
	cout << "12: " << secondaryBitmap[4] << " : " << int(secondaryBitmap[4]) << endl;
	cout << "13: " << secondaryBitmap[5] << " : " << int(secondaryBitmap[5]) << endl;
	cout << "14: " << secondaryBitmap[6] << " : " << int(secondaryBitmap[6]) << endl;
	cout << "15: " << secondaryBitmap[7] << " : " << int(secondaryBitmap[7]) << endl;
	cout << "16: " << tertiaryBitmap[0] << " : " << int(tertiaryBitmap[0]) << endl;
	cout << "17: " << tertiaryBitmap[1] << " : " << int(tertiaryBitmap[1]) << endl;
	cout << "18: " << tertiaryBitmap[2] << " : " << int(tertiaryBitmap[2]) << endl;
	cout << "19: " << tertiaryBitmap[3] << " : " << int(tertiaryBitmap[3]) << endl;
	cout << "20: " << tertiaryBitmap[4] << " : " << int(tertiaryBitmap[4]) << endl;
	cout << "21: " << tertiaryBitmap[5] << " : " << int(tertiaryBitmap[5]) << endl;
	cout << "22: " << tertiaryBitmap[6] << " : " << int(tertiaryBitmap[6]) << endl;
	cout << "23: " << tertiaryBitmap[7] << " : " << int(tertiaryBitmap[7]) << endl;

#endif


	for(iCo = 0;iCo < 8;iCo++){
		if (iCo > 0){
			if ((primaryBitmap[iCo] & 128 ) > 0) {
				ParseField(IsoCmp[NumToStr((iCo * 8) + 1)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 1)].iLength);
				vElements.push_back(NumToStr((iCo * 8) + 1));
			}
		}
		if ((primaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 2)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 2)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 2));
		}
		if ((primaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 3)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 3)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 3));
		}
		if ((primaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 4)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 4)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 4));
		}
		if ((primaryBitmap[iCo] & 8 ) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 5)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 5)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 5));
		}
		if ((primaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 6)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 6)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 6));
		}
		if ((primaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 7)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 7)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 7));
		}
		if ((primaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((iCo * 8) + 8)], sData, offset, IsoCmp[NumToStr((iCo * 8) + 8)].iLength);
			vElements.push_back(NumToStr((iCo * 8) + 8));
		}
	}

	for(iCo = 0;iCo < 8;iCo++){
		if (iCo > 0){
			if ((secondaryBitmap[iCo] & 128 ) > 0){
				ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 1)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 1)].iLength);
				vElements.push_back(NumToStr((64 + (iCo * 8)) + 1));
			}
		}
		if ((secondaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 2)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 2)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 2));
		}
		if ((secondaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 3)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 3)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 3));
		}
		if ((secondaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 4)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 4)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 4));
		}
		if ((secondaryBitmap[iCo] & 8 ) > 0) {
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 5)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 5)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 5));
		}
		if ((secondaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 6)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 6)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 6));
		}
		if ((secondaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 7)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 7)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 7));
		}
		if ((secondaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((64 + (iCo * 8)) + 8)], sData, offset, IsoCmp[NumToStr((64 + (iCo * 8)) + 8)].iLength);
			vElements.push_back(NumToStr((64 + (iCo * 8)) + 8));
		}
	}

	for(iCo = 0;iCo < 8;iCo++)
	{
		if (iCo > 0)
		{
			if ((tertiaryBitmap[iCo] & 128 ) > 0){
				ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 1)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 1)].iLength);
				vElements.push_back(NumToStr((128 + (iCo * 8)) + 1));
			}
		}
		if ((tertiaryBitmap[iCo] & 64) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 2)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 2)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 2));
		}
		if ((tertiaryBitmap[iCo] & 32) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 3)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 3)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 3));
		}
		if ((tertiaryBitmap[iCo] & 16) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 4)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 4)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 4));
		}
		if ((tertiaryBitmap[iCo] & 8 ) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 5)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 5)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 5));
		}
		if ((tertiaryBitmap[iCo] & 4) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 6)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 6)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 6));
		}
		if ((tertiaryBitmap[iCo] & 2) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 7)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 7)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 7));
		}
		if ((tertiaryBitmap[iCo] & 1) > 0){
			ParseField(IsoCmp[NumToStr((128 + (iCo * 8)) + 8)], sData, offset, IsoCmp[NumToStr((128 + (iCo * 8)) + 8)].iLength);
			vElements.push_back(NumToStr((128 + (iCo * 8)) + 8));
		}
	}


	return true;
}


IsoParser::~IsoParser(void)
{
}

bool IsoParser::ParseField(IsoObj &isObj, string buf, int &offset, int iLen){
#ifdef VERBOSE
	cout << "offset:  " << offset << " : " << iLen << " : " << isObj.sData << " Type: " << isObj.sType <<" NAME ["<<isObj.sName << "]" << endl;
#endif
	if(isObj.sType.compare("fix") == 0) isObj.sData = ReadFixRaw(buf, offset, iLen);
	else if(isObj.sType.compare("llvar") == 0) isObj.sData = ReadVar2Raw(buf, offset, iLen);
	else if(isObj.sType.compare("lllvar") == 0) isObj.sData = ReadVar3Raw(buf, offset, iLen);
	else if(isObj.sType.compare("llllvar") == 0) isObj.sData = ReadVar4Raw(buf, offset, iLen);
	else if(isObj.sType.compare("bfix") == 0) isObj.sData = ReadFixPacked(buf, offset, iLen);
	else if(isObj.sType.compare("bllvar") == 0) isObj.sData = ReadVar2Packed(buf, offset, iLen);
	else if(isObj.sType.compare("blllvar") == 0) isObj.sData = ReadVar2Packed(buf, offset, iLen);
	else if(isObj.sType.compare("bllllvar") == 0) isObj.sData = ReadVar3Packed(buf, offset, iLen);
#ifdef VERBOSE
	cout << "data: " << isObj.sData << endl;
#endif
	return true;
}


/// <summary>
/// Converts 0-15 to '0-9A-F'
/// </summary>
char IsoParser::XtoC(int x)
{
#ifdef VERBOSE
	cout << "INSIDE XtoC : " << x << endl;
#endif
	if (x < 10) return (char)('0' + x);
	return (char)('7' + x);
}

char IsoParser::CtoX(char x[])
{
	char r;
	r = x[0];
	r <<=4;
	r |= (x[1] & 0xf);
	return r;
}

/// <summary>
/// Grab bytes from a buffer
/// </summary>
string IsoParser::B(string buf, int off, int len)
{
#ifdef VERBOSE
	cout << buf.substr(off,len) << " : " << off << " : " << len << endl;
#endif
	//cout << buf << endl;
	//Array.Copy(buf, off, a, 0, len);
	return buf.substr(off,len);
}

/// <summary>
/// Converts a buffer to a string
/// </summary>
/*string IsoParser::S(byte buf[])
{
	return Encoding.ASCII.GetString(buf);
}*/

string IsoParser::ReadFixRaw(string buf, int &offset, int len)
{
	string sResult = B(buf,offset,len);
	offset += len;

	return sResult;
}

string IsoParser::ReadVar2Raw(string buf, int &offset, int unused)
{
	int len = (buf.c_str()[offset] - 0x30) * 10 + buf.c_str()[offset + 1] - 0x30;
	int oldoffset = offset;
	offset += len + 2;

	return B(buf,oldoffset + 2,len);
}

string IsoParser::ReadVar3Raw(string buf, int &offset, int unused)
{
	int len = (buf.c_str()[offset]-0x30)*100 + (buf.c_str()[offset+1]-0x30)*10 + buf.c_str()[offset+2]-0x30;
	int oldoffset = offset;
	offset += len + 3;
	return B(buf, oldoffset + 3, len);
}


string IsoParser::ReadVar4Raw(string buf, int &offset, int unused)
{
	int len = (buf.c_str()[offset]-0x30)*1000 + (buf.c_str()[offset+1]-0x30)*100 + (buf.c_str()[offset+2]-0x30)*10 + buf.c_str()[offset+3]-0x30;
	int oldoffset = offset;
	offset += len + 4;
	return B(buf, oldoffset + 4, len);
}

/// <summary>
/// Reads an LLVARn
/// eg input: 31 31 12 34 56 78 91 2F
/// 31 31 is ascii '11' which means 11 numbers
/// Those 11 numbers are binary packed decimal = 1234567891
/// The 'F' at the end is filler.
/// </summary>
string IsoParser::ReadVar2Packed(string buf, int &offset, int unused)
{
	int len = (buf.c_str()[offset] - 0x30) * 10 + (buf.c_str()[offset + 1] - 0x30);
	int bytes = (len + 1) / 2; // The +1 is so it rounds up
	byte b;
	string sb;
	if (len % 2 == 0) // Even number of chars, so there's no padding at the end
	{
	  for (int i = 0; i < bytes; i++)
	  {
		b = buf.c_str()[offset + 2 + i];
		sb.append(1, XtoC(b >> 4)).append(1, XtoC(b & 0xf));
	  }
	}
	else
	{
	  int i;
	  for (i = 0; i < bytes - 1; i++)
	  {
		  b = buf.c_str()[offset + 2 + i];
		  sb.append(1, XtoC(b >> 4)).append(1, XtoC(b & 0xf));
	  }
	  sb.append(1,XtoC(buf.c_str()[offset + 2 + i] >> 4)); // Get the last char
	}
	offset += bytes + 2;
	return sb;
}

/// <summary>
/// Reads an LLLVARn
/// eg input: 30 31 31 12 34 56 78 91 2F
/// 30 31 31 is ascii '011' which means 11 numbers
/// Those 11 numbers are binary packed decimal = 1234567891
/// The 'F' at the end is filler.
/// </summary>
string IsoParser::ReadVar3Packed(string buf, int &offset, int unused)
{
	int len = (buf.c_str()[offset] - 0x30) * 100 + (buf.c_str()[offset + 1] - 0x30) * 10 + (buf.c_str()[offset + 2] - 0x30);
	int bytes = (len + 1) / 2; // The +1 is so it rounds up
	byte b;
	string sb;
	if (len % 2 == 0) // Even number of chars, so there's no padding at the end
	{
	  for (int i = 0; i < bytes; i++)
	  {
		  b = buf.c_str()[offset + 3 + i];
		sb.append(1, XtoC(b >> 4)).append(1, XtoC(b & 0xf));
	  }
	}
	else
	{
	  int i;
	  for (i = 0; i < bytes - 1; i++)
	  {
		  b = buf.c_str()[offset + 3 + i];
		sb.append(1, XtoC(b >> 4)).append(1, XtoC(b & 0xf));
	  }
	  sb.append(1, XtoC(buf.c_str()[offset + 3 + i] >> 4)); // Get the last char
	}
	offset += bytes + 3;
	return sb;
}

/// <summary>
/// Reads an LLLVARn
/// eg input: 30 31 31 12 34 56 78 91 2F
/// 30 31 31 is ascii '011' which means 11 numbers
/// Those 11 numbers are binary packed decimal = 1234567891
/// The 'F' at the end is filler.
/// </summary>
string IsoParser::ReadVar4Packed(string buf, int &offset, int unused)
{
	int len = (buf.c_str()[offset] - 0x30) * 1000 + (buf.c_str()[offset + 1] - 0x30) * 100 + (buf.c_str()[offset + 2] - 0x30) * 10 + (buf.c_str()[offset + 3] - 0x30);
	int bytes = (len + 1) / 2; // The +1 is so it rounds up
	byte b;
	string sb;
	if (len % 2 == 0) // Even number of chars, so there's no padding at the end
	{
	  for (int i = 0; i < bytes; i++)
	  {
		  b = buf.c_str()[offset + 4 + i];
		sb.append(1, XtoC(b >> 4)).append(1, XtoC(b & 0xf));
	  }
	}
	else
	{
	  int i;
	  for (i = 0; i < bytes - 1; i++)
	  {
		  b = buf.c_str()[offset + 4 + i];
		sb.append(1, XtoC(b >> 4)).append(1, XtoC(b & 0xf));
	  }
	  sb.append(1, XtoC(buf.c_str()[offset + 4 + i] >> 4)); // Get the last char
	}
	offset += bytes + 4;
	return sb;
}


/// <summary>
/// Parse a fixed length packed [hexi]decimal field
/// If it is an odd number of digits, it skips the first nibble
/// eg for input 0x01 23 of length 3, it grabs the "123"
/// </summary>
string IsoParser::ReadFixPacked(string buf, int &offset, int len)
{
	int bytes = (len + 1) / 2; // The +1 is so it rounds up
	byte b;
	string sb;
#ifdef VERBOSE
	cout << "INSIDE ReadFixPacked" << endl;
#endif
	if (len % 2 == 0) // Even number of chars, so there's no padding at the end
	{
	  for (int i = 0; i < bytes; i++)
	  {
		  b = buf.c_str()[offset + i];
#ifdef VERBOSE
		cout << "i : " << i << " char:  " << (int)b << endl;
#endif
		  sb.append(1, XtoC(b >> 4)).append(1, XtoC(b & 0xf));
	  }
	}
	else // Odd number
	{
	  int i;
	  sb.append(1, XtoC(buf.c_str()[offset] & 0xf)); // Get the first char from the second nibble
	  for (i = 1; i < bytes; i++)
	  {
		  b = buf.c_str()[offset + i];
		  sb.append(1, XtoC(b >> 4)).append(1, XtoC(b & 0xf));
	  }
	}
	offset += bytes;
	return sb;
}

string IsoParser::GetField(int iIndex){
	string sResp = "";
	if(IsoCmp.find(NumToStr(iIndex)) != IsoCmp.end())
		sResp = IsoCmp[NumToStr(iIndex)].sData;
	return sResp;
}


bool IsoParser::GetFormatedStr(string &sForStr, string sWElem){

	int iCo = 0;
	int iFirst = 0;
	string sRes = "";

	for(iCo = 0;iCo < (int)vElements.size();iCo++){
		if(iFirst == 0){
			if(sWElem.find("," + vElements[iCo] + ",") == string::npos){
				sRes = "('" + vElements[iCo] + "','" + IsoCmp[vElements[iCo]].sData + "')";
				iFirst++;
			}
		} else {
			if(sWElem.find("," + vElements[iCo] + ",") == string::npos){
				sRes += ",('" + vElements[iCo] + "','" + IsoCmp[vElements[iCo]].sData + "')";
			}
		}
	}
	sForStr += sRes;

	return true;

}


bool IsoParser::GetFormatedStrSub(string &sForStr, string sWElem, string sAnt, int iPAdd){

	int iCo = 0;
	int iFirst = 0;
	string sRes = "";

	if(iPAdd == 1)
		iFirst++;

	for(iCo = 0;iCo < (int)vElements.size();iCo++){
		if(iFirst == 0){
			if(sWElem.find("," + vElements[iCo] + ",") == string::npos){
				sRes = "('" + sAnt + "." + vElements[iCo] + "','" + IsoCmp[vElements[iCo]].sData + "')";
				iFirst++;
			}
		} else {
			if(sWElem.find("," + vElements[iCo] + ",") == string::npos){
				sRes += ",('" + sAnt + "." + vElements[iCo] + "','" + IsoCmp[vElements[iCo]].sData + "')";
			}
		}
	}


	sForStr += sRes;

	return true;

}

bool IsoParser::PackField(IsoObj isObj, string &buf, string sData, int iLen){
	if(isObj.sType.compare("fix") == 0) WriteFixRaw(buf, sData, isObj.sTyDa, isObj.iLength);
	else if(isObj.sType.compare("llvar") == 0) WriteVar2Raw(buf, sData, isObj.sTyDa, sData.size());
	else if(isObj.sType.compare("lllvar") == 0) WriteVar3Raw(buf, sData, isObj.sTyDa, sData.size());
	else if(isObj.sType.compare("llllvar") == 0) WriteVar4Raw(buf, sData, isObj.sTyDa, iLen);
	else if(isObj.sType.compare("bfix") == 0) WriteFixPacked(buf, sData, isObj.sTyDa, isObj.iLength);
	else if(isObj.sType.compare("bllvar") == 0) WriteVar2Packed(buf, sData, isObj.sTyDa, sData.size());
	else if(isObj.sType.compare("blllvar") == 0) WriteVar3Packed(buf, sData, isObj.sTyDa, sData.size());
	else if(isObj.sType.compare("bllllvar") == 0) WriteVar4Packed(buf, sData, isObj.sTyDa, sData.size());

	return true;
}

bool IsoParser::WriteFixRaw(string &buf, string sData, string sTyDa, int iLen){
	char buff[100];
	char format[10];
	memset(format,0x00,10);
	memset(buff,0x00,100);
#ifdef VERBOSE
	cout << "sTyDa : " << sTyDa << " Data: " << sData << endl;
#endif
	if(sTyDa == "n")
		sprintf(format,"%%0%ds",iLen);
	else if(iLen == (int)strlen(sData.c_str()))
		sprintf(format,"%%0%ds",iLen);
	else
		sprintf(format,"%%-%d.%ds",iLen,iLen);
#ifdef VERBOSE
	cout << "format data: " << format << endl;
#endif
	sprintf(buff, format, sData.c_str());

	buf.append(buff,strlen(buff));
#ifdef VERBOSE
	cout << "Info fix: " << " Data : " << buff << " size : " << strlen(buff) << endl;
#endif
	return true;
}


bool IsoParser::WriteVar2Raw(string &buf, string sData, string sTyDa, int iLen){
	char buff[100];
	memset(buff,0x00,100);

	sprintf(buff, "%02d", sData.size());
	memcpy(buff+2,sData.c_str(),sData.size());
	buf.append(buff,2 + sData.size());
	//cout << "Info var 2: " << " Data : " << buff << " size : " << strlen(buff) << endl;
#ifdef VERBOSE
	cout << "Info 2: " << " Data : " << buff << " size : " << strlen(buff) << endl;
#endif

	return true;
}

bool IsoParser::WriteVar3Raw(string &buf, string sData, string sTyDa, int iLen){
	char buff[1000];
	memset(buff,0x00,1000);
	sprintf(buff, "%03d", sData.size());
	memcpy(buff+3,sData.c_str(),sData.size());
	buf.append(buff,3 + sData.size());
#ifdef VERBOSE
	cout << "Info 3: " << " Data : " << buff << " size : " << strlen(buff) << endl;
#endif

	return true;
}


bool IsoParser::WriteVar4Raw(string &buf, string sData, string sTyDa, int iLen){
	char buff[10000];
	memset(buff,0x00,10000);
	sprintf(buff, "%04d", sData.size());
	memcpy(buff+4,sData.c_str(),sData.size());
	buf.append(buff,4 + sData.size());
#ifdef VERBOSE
	cout << "Info var4: " << " Data : " << buff << " size : " << 4 + sData.size() << endl;
#endif
	return true;
}
bool IsoParser::WriteVar2Packed(string &buf, string sData, string sTyDa, int iLen){
	//int bytes = (iLen + 1) / 2; // The +1 is so it rounds up
	int size[4];
	char sizeC[4];

	char fPa[2];
	string sb;

	size[0] = iLen/10;
	size[1] = (iLen - (size[0] * 10));

	sizeC[0] = size[0] + 0x30;
	sizeC[1] = size[1] + 0x30;

	buf.append(sizeC,2);
	if (iLen % 2 == 0) // Even number of chars, so there's no padding at the end
	{
	  for (int i = 0; i < iLen; i+=2)
	  {
		  strncpy(fPa,buf.substr(i,2).c_str(),2);
		  sb.append(1, CtoX(fPa));
	  }
	}
	else
	{
	  int i;

	  fPa[0] = '0';
	  fPa[1] = buf.c_str()[0];
	  sb.append(1, CtoX(fPa)); // Get the first char from the second nibble
	  for (i = 1; i < iLen; i+=2)
	  {
		  strncpy(fPa,buf.substr(i,2).c_str(),2);
		  sb.append(1, CtoX(fPa));
	  }
	}
	buf.append(sb);

	return true;
}


bool IsoParser::WriteVar3Packed(string &buf, string sData, string sTyDa, int iLen){
	//int bytes = (iLen + 1) / 2; // The +1 is so it rounds up
	int size[4];
	char sizeC[4];

	char fPa[2];
	string sb;

	size[0] = iLen/100;
	size[1] = (iLen - (size[0] * 100))/10;
	size[2] = (iLen - ((size[0] * 100) + (size[1] * 10)));

	sizeC[0] = size[0] + 0x30;
	sizeC[1] = size[1] + 0x30;
	sizeC[2] = size[2] + 0x30;
	buf.append(sizeC,3);
	if (iLen % 2 == 0) // Even number of chars, so there's no padding at the end
	{
	  for (int i = 0; i < iLen; i+=2)
	  {
		  strncpy(fPa,buf.substr(i,2).c_str(),2);
		  sb.append(1, CtoX(fPa));
	  }
	}
	else
	{
	  int i;

	  fPa[0] = '0';
	  fPa[1] = buf.c_str()[0];
	  sb.append(1, CtoX(fPa)); // Get the first char from the second nibble
	  for (i = 1; i < iLen; i+=2)
	  {
		  strncpy(fPa,buf.substr(i,2).c_str(),2);
		  sb.append(1, CtoX(fPa));
	  }
	}
	buf.append(sb);

	return true;
}

bool IsoParser::WriteVar4Packed(string &buf, string sData, string sTyDa, int iLen){
	//int bytes = (iLen + 1) / 2; // The +1 is so it rounds up
	int size[4];
	char sizeC[4];

	char fPa[2];
	string sb;

	size[0] = iLen/1000;
	size[1] = (iLen - (size[0] * 1000))/100;
	size[2] = (iLen - ((size[0] * 1000) + (size[1] * 100))) / 10;
	size[3] = iLen - ((size[0] * 1000) + (size[1] * 100) + (size[2] * 10));

	sizeC[0] = size[0] + 0x30;
	sizeC[1] = size[1] + 0x30;
	sizeC[2] = size[2] + 0x30;
	sizeC[3] = size[3] + 0x30;
	buf.append(sizeC,4);
	if (iLen % 2 == 0) // Even number of chars, so there's no padding at the end
	{
	  for (int i = 0; i < iLen; i+=2)
	  {
		  strncpy(fPa,buf.substr(i,2).c_str(),2);
		  sb.append(1, CtoX(fPa));
	  }
	}
	else
	{
	  int i;

	  fPa[0] = '0';
	  fPa[1] = buf.c_str()[0];
	  sb.append(1, CtoX(fPa)); // Get the first char from the second nibble
	  for (i = 1; i < iLen; i+=2)
	  {
		  strncpy(fPa,buf.substr(i,2).c_str(),2);
		  sb.append(1, CtoX(fPa));
	  }
	}
	buf.append(sb);

	return true;
}

bool IsoParser::WriteFixPacked(string &buf, string sData, string sTyDa, int iLen){
	//int bytes = (iLen + 1) / 2; // The +1 is so it rounds up
	//byte b;
	string sb;
	char fPa[2];
	if (iLen % 2 == 0) // Even number of chars, so there's no padding at the end
	{
	  for (int i = 0; i < iLen; i+=2)
	  {
		  strncpy(fPa,buf.substr(i,2).c_str(),2);
		  sb.append(1, CtoX(fPa));
	  }
	}
	else // Odd number
	{
	  int i;

	  fPa[0] = '0';
	  fPa[1] = buf.c_str()[0];
	  sb.append(1, CtoX(fPa)); // Get the first char from the second nibble
	  for (i = 1; i < iLen; i+=2)
	  {
		  strncpy(fPa,buf.substr(i,2).c_str(),2);
		  sb.append(1, CtoX(fPa));
	  }
	}
	buf.append(sb);
	return true;
}


bool IsoParser::GetFormatedRsp(string &mti,string &sForStr, string sWElem, hasresult hCont, int iPAdd){

	byte primaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte secondaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte tertiaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	sForStr = "";
	int iBitmap = 0;
	string sRsp = "";
	bool bResult = false;

	for (hasresult::iterator it = hCont.begin();it != hCont.end(); ++it)
	{
		if(it->first.find(".") == string::npos)
		{
#ifdef VERBOSE
			cout << "Item: " << it->first << " Data: " << it->second << " Type: " << IsoCmp[it->first].sType << " TyDa: " << IsoCmp[it->first].sTyDa  << endl;
#endif
			PackField(IsoCmp[it->first], sForStr, it->second, it->second.size());
			iBitmap = SetBitmaps(primaryBitmap,secondaryBitmap, tertiaryBitmap, it->first);
			bResult = true;
		}
#ifdef VERBOSE
		else
		{
		    cout << "-- -- Item: " << it->first << " Data: " << it->second << " Type: " << IsoCmp[it->first].sType << " TyDa: " << IsoCmp[it->first].sTyDa  << endl;
		}
#endif
	}




	if(bResult){
		if(iBitmap == 1)
			sRsp.append((char *)primaryBitmap,8);
		else if(iBitmap == 2)
			sRsp.append((char *)primaryBitmap,8).append((char *)secondaryBitmap,8);
		else if(iBitmap == 3)
			sRsp.append((char *)primaryBitmap,8).append((char *)secondaryBitmap,8).append((char *)tertiaryBitmap,8);

		sRsp.append(sForStr);
	}

	sForStr = mti + sRsp;
	return true;
}


bool IsoParser::GetFormatedRsp(string &sForStr, string sWElem, hasresult hCont, int iPAdd){

	byte primaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte secondaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte tertiaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	sForStr = "";
	int iBitmap = 0;
	string sRsp = "";
	bool bResult = false;

	for (hasresult::iterator it = hCont.begin();it != hCont.end(); ++it)
	{
		if(it->first.find(".") == string::npos)
		{
#ifdef VERBOSE
			cout << "Item: " << it->first << " Data: " << it->second << " Type: " << IsoCmp[it->first].sType << " TyDa: " << IsoCmp[it->first].sTyDa  << endl;
#endif
			PackField(IsoCmp[it->first], sForStr, it->second, it->second.size());
			iBitmap = SetBitmaps(primaryBitmap,secondaryBitmap, tertiaryBitmap, it->first);
			bResult = true;
		}
#ifdef VERBOSE
		else
		{
		    cout << "-- -- Item: " << it->first << " Data: " << it->second << " Type: " << IsoCmp[it->first].sType << " TyDa: " << IsoCmp[it->first].sTyDa  << endl;
		}
#endif
	}




	if(bResult){
		if(iBitmap == 1)
			sRsp.append((char *)primaryBitmap,8);
		else if(iBitmap == 2)
			sRsp.append((char *)primaryBitmap,8).append((char *)secondaryBitmap,8);
		else if(iBitmap == 3)
			sRsp.append((char *)primaryBitmap,8).append((char *)secondaryBitmap,8).append((char *)tertiaryBitmap,8);

		sRsp.append(sForStr);
	}

	sForStr = "0204" + sRsp;
	return true;
}

string IsoParser::OrganizeStrIsoData(string isoData[][5], int aSize, int iIndex){
	string strRet = "";
	for(int iQty=0; iQty < aSize; iQty++){
		if(iQty == 0){
			strRet = isoData[ iQty ][ iIndex ];
		} else {
			strRet += "," + isoData[ iQty ][ iIndex ];
		}
	}
	return strRet;

}


bool IsoParser::GetFormatedRspSub48(string &sForStr, string sWElem, hasresult &hCont, int iPAdd){

	byte primaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte secondaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte tertiaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int iBitmap = 0;
	string sRsp = "";
	bool bResult = false;
	for (hasresult::const_iterator it = hCont.begin();
        it != hCont.end(); ++it){

		if(it->first.find(sWElem + ".") != string::npos){
			bResult = true;
			PackField(IsoCmp[it->first.substr(it->first.find(".") + 1) ], sForStr, it->second, it->second.size());
			iBitmap = SetBitmaps(primaryBitmap,secondaryBitmap, tertiaryBitmap, it->first.substr(it->first.find(".") + 1));
			//hCont.erase(it);
#ifdef VERBOSE
			std::cout << sWElem << " : [" << it->first << ", " << it->second << "]" << std::endl;
#endif
		}
	}



	if(bResult){
		if(iBitmap == 1)
			sRsp.append((char *)primaryBitmap,8);
		else if(iBitmap == 2)
			sRsp.append((char *)primaryBitmap,8).append((char *)secondaryBitmap,8);
		else if(iBitmap == 3)
			sRsp.append((char *)primaryBitmap,8).append((char *)secondaryBitmap,8).append((char *)tertiaryBitmap,8);
		sRsp.append(sForStr);
cout << "Result " + sWElem << " : " << sRsp << endl;
cout << "Len : " << sRsp.size() << endl;
		hCont[sWElem].append(sRsp.c_str(),sRsp.size());
	}
	sForStr = sRsp;

	return true;
}

bool IsoParser::GetFormatedRspSub(string &sForStr, string sWElem, hasresult &hCont, int iPAdd){

	byte primaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte secondaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	byte tertiaryBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int iBitmap = 0;
	string sRsp = "";
	bool bResult = false;
#ifdef VERBOSE
			std::cout << "inside GetFormatedRspSub" << std::endl;
#endif
	for (hasresult::const_iterator it = hCont.begin();
        it != hCont.end(); ++it){

		if(it->first.find(sWElem + ".") != string::npos){
			bResult = true;
			PackField(IsoCmp[it->first.substr(it->first.find(".") + 1) ], sForStr, it->second, it->second.size());
			iBitmap = SetBitmaps(primaryBitmap,secondaryBitmap, tertiaryBitmap, it->first.substr(it->first.find(".") + 1));
			//hCont.erase(it);
#ifdef VERBOSE
			std::cout << sWElem << " : [" << it->first << ", " << it->second << "]" << std::endl;
#endif
		}
	}



	if(bResult){
		if(iBitmap == 1)
			sRsp.append((char *)primaryBitmap,8);
		else if(iBitmap == 2)
			sRsp.append((char *)primaryBitmap,8).append((char *)secondaryBitmap,8);
		else if(iBitmap == 3)
			sRsp.append((char *)primaryBitmap,8).append((char *)secondaryBitmap,8).append((char *)tertiaryBitmap,8);
		sRsp.append(sForStr);

		hCont[sWElem].append(sRsp.c_str(),sRsp.size());
	}
	sForStr = sRsp;

	return true;
}

int IsoParser::SetBitmaps(byte * primaryBitmap, byte * secondaryBitmap, byte * tertiaryBitmap, string sKey){
	int iVal, iPos, iPosIn;
	from_string<int>(iVal, sKey, std::dec);
	int iBitmap = 0;
#ifdef VERBOSE
	cout << "iVal : " << iVal << endl;
#endif
	if((0 < iVal) && (iVal <= 64)){
		iPos = (iVal / 8);
		iPosIn = iVal - (iPos * 8);
		if(iPosIn == 0){
			iPos--;
			iPosIn = 8;
		}
#ifdef VERBOSE
		cout << "iPos 1: " << iPos << " iPosIn: " << iPosIn << endl;
#endif
		if(iPosIn == 1) primaryBitmap[ iPos ] |= 128;
		if(iPosIn == 2) primaryBitmap[ iPos ] |= 64;
		if(iPosIn == 3) primaryBitmap[ iPos ] |= 32;
		if(iPosIn == 4) primaryBitmap[ iPos ] |= 16;
		if(iPosIn == 5) primaryBitmap[ iPos ] |= 8;
		if(iPosIn == 6) primaryBitmap[ iPos ] |= 4;
		if(iPosIn == 7) primaryBitmap[ iPos ] |= 2;
		if(iPosIn == 8) primaryBitmap[ iPos ] |= 1;
		iBitmap = 1;
	} else if((65 <= iVal) && (iVal <= 128)){
		iPos = ((iVal - 64)/ 8);
		iPosIn = (iVal - 64) - (iPos * 8);
		if(iPosIn == 0){
			iPos--;
			iPosIn = 8;
		}
		primaryBitmap[ 0 ] |= 128;
#ifdef VERBOSE
		cout << "iPos 2: " << iPos << " iPosIn: " << iPosIn << endl;
#endif
		if(iPosIn == 1) secondaryBitmap[ iPos ] |= 128;
		if(iPosIn == 2) secondaryBitmap[ iPos ] |= 64;
		if(iPosIn == 3) secondaryBitmap[ iPos ] |= 32;
		if(iPosIn == 4) secondaryBitmap[ iPos ] |= 16;
		if(iPosIn == 5) secondaryBitmap[ iPos ] |= 8;
		if(iPosIn == 6) secondaryBitmap[ iPos ] |= 4;
		if(iPosIn == 7) secondaryBitmap[ iPos ] |= 2;
		if(iPosIn == 8) secondaryBitmap[ iPos ] |= 1;
		iBitmap = 2;
	} else if((129 <= iVal) && (iVal <= 192)){

        iPos = ((iVal - 128)/ 8);
		iPosIn = (iVal - 128) - (iPos * 8);
		if(iPosIn == 0){
			iPos--;
			iPosIn = 8;
		}
		primaryBitmap[ 0 ] |= 128;
        secondaryBitmap[ 0 ] |= 128;
#ifdef VERBOSE
		cout << "iPos 3: " << iPos << " iPosIn: " << iPosIn << endl;
#endif
		if(iPosIn == 1) tertiaryBitmap[ iPos ] |= 128;
		if(iPosIn == 2) tertiaryBitmap[ iPos ] |= 64;
		if(iPosIn == 3) tertiaryBitmap[ iPos ] |= 32;
		if(iPosIn == 4) tertiaryBitmap[ iPos ] |= 16;
		if(iPosIn == 5) tertiaryBitmap[ iPos ] |= 8;
		if(iPosIn == 6) tertiaryBitmap[ iPos ] |= 4;
		if(iPosIn == 7) tertiaryBitmap[ iPos ] |= 2;
		if(iPosIn == 8) tertiaryBitmap[ iPos ] |= 1;
		iBitmap = 3;
	}

	return iBitmap;
}

bool IsoParser::AddData(string key, string Data){

    hMessSec[ key ] = Data;
    return true;
}


hasresult IsoParser::GetResult( void ){
    return hMessSec;
}
