#ifndef _QRCODEDLL_H_
#define _QRCODEDLL_H_

#include <string>

#ifdef WIN32
    #if BUILDING_DLL
            # define DLLIMPORT __declspec (dllexport)
        #else /* Not BUILDING_DLL */
            # define DLLIMPORT __declspec (dllimport)
    #endif
#else /* Not BUILDING_DLL */
    #if BUILDING_DLL
        #define DLLIMPORT __attribute__((visibility("default")))
    #else
        #define DLLIMPORT
    #endif
#endif

using namespace std;

//enum for levels of qrcode
enum QRLevel{QRLEVEL_L=0,QRLEVEL_M=1,QRLEVEL_Q=2,QRLEVEL_H=3};

//enum for return values
enum ValueRetQRCode{Unknown=-1,Success=0,InvalidLevel=1,InvalidVersion=2};

class DLLIMPORT QRCode
{
	public:
		//constructor
		QRCode();

		/*
		 * Class:     QRCode
		 * Method:    GenerateQRCode
		 *  const QRLevel Level			: Level of qrcode
		 *  const int Version			: Version qrcode
		 *  const char * const Data		: Data for generating qrcode
		 */
		ValueRetQRCode GenerateQRCode(const QRLevel Level,const int Version,const char * const Data);

		/*
		 * Class:     QRCode
		 * Method:    GenerateQRCode
		 *  const QRLevel Level			: Level of qrcode
		 *  const int Version			: Version qrcode
		 *  const char * const Data		: Data for generating qrcode
		 *  const int Size				: Size of data
		 */
		ValueRetQRCode GenerateQRCode(const QRLevel Level,const int Version,const char * const Data,const int Size);

		/*
		 * Class:     QRCode
		 * Method:    GenerateQRCode
		 *  const QRLevel Level			: Level of qrcode
		 *  const int Version			: Version qrcode
		 *  const char * const Data		: Data for generating qrcode
		 *  const int Ini				: first position in the array
		 *  const int Size				: Size of data
		 */
		ValueRetQRCode GenerateQRCode(const QRLevel Level,const int Version,const char * const Data,const int Ini,const int Size);

		/*
		 * Class:     QRCode
		 * Method:    GenerateQRCode
		 *  const QRLevel Level			: Level of qrcode
		 *  const int Version			: Version qrcode
		 *  const string &Data			: string with data of qrcode
		 */
		ValueRetQRCode GenerateQRCode(const QRLevel Level,const int Version,const string &Data);

		/*
		 * Class:     QRCode
		 * Method:    GenerateQRCode
		 *  const QRLevel Level			: Level of qrcode
		 *  const int Version			: Version qrcode
		 *  const string &Data			: string with data of qrcode
		 *	const int Size				: size of data
		 */
		ValueRetQRCode GenerateQRCode(const QRLevel Level,const int Version,const string &Data,const int Size);

		/*
		 * Class:     QRCode
		 * Method:    GenerateQRCode
		 *  const QRLevel Level			: Level of qrcode
		 *  const int Version			: Version qrcode
		 *  const string &Data			: string with data of qrcode
		 *	const int Ini				: First position in data
		 *	const int Size				: size of data
		 */
		ValueRetQRCode GenerateQRCode(const QRLevel Level,const int Version,const string &Data,const int Ini,const int Size);

		/*
		 * Class:     QRCode
		 * Method:    ExportAsArray
		 *  char *QRCodeData			: buffer to stored qrcode data
		 *  const int MaxSizeArray		: size of QRCodeData
		 *  const string &Data			: string with data of qrcode
		 *	int *SizeReturnedData		: size of returned data in bytes
		 */
		bool ExportAsArray(char *QRCodeData,const int MaxSizeArray,int *SizeQrCodePixels,int *SizeReturnedData);

		/*
		 * Class:     QRCode
		 * Method:    ExportAsString
		 *  string &QRCodeData			: buffer to stored qrcode data
		 *	int *SizeReturnedData		: size of returned data in bytes
		 */
		bool ExportAsString(string &QRCodeData,int *SizeQrCodePixels);

		/*
		 * Class:     QRCode
		 * Method:    ExportAsBMPMonochromatic
		 *  const char * const FileName	: file where the bmp file will be stored
		 *	const int Scale				: scale of image
		 *	const int MarginLeft		: left margin in pixels
		 *	const int MarginRight		: right margin in pixels
		 *	const int MarginUp			: up margin in pixels
		 *	const int MarginDown		: down margin in pixels
		 */
		bool ExportAsBMPMonochromatic(const char * const FileName,const int Scale,const int MarginLeft,const int MarginRight,const int MarginUp,const int MarginDown);

		/*
		 * Class:     QRCode
		 * Method:    ExportAsBMPMonochromatic
		 *  const char * const FileName	: file where the bmp file will be stored
		 *	const int Scale				: scale of image
		 */
		bool ExportAsBMPMonochromatic(const char * const FileName,const int Scale);

		/*
		 * Class:     QRCode
		 * Method:    ExportAsBMPMonochromatic
		 *  const char * const FileName	: file where the bmp file will be stored
		 *	const int Scale				: scale of image
		 *	const int Width				: Width image pixels
		 *	const int Height			: Height image pixels
		 */
		bool ExportAsBMPMonochromatic(const char * const FileName,const int Scale,const int Width,const int Height);

		/*
		 * Class:     QRCode
		 * Method:    ExportAsBMPMonochromatic
		 *  const char * const FileName	: file where the bmp file will be stored
		 *	const int Width				: Width image pixels
		 *	const int Height			: Height image pixels
		 */
		bool ExportAsBMPMonochromatic(const char * const FileName,const int Width,const int Height);

		/*
		 * Class:     QRCode
		 * Method:    ExportAsBMPMonochromatic
		 *  const string &FileName		: file where the bmp file will be stored
		 *	const int Width				: Width image pixels
		 *	const int Height			: Height image pixels
		 */
		bool ExportAsBMPMonochromatic(const string &FileName,const int Width,const int Height);

		//destructor
		virtual ~QRCode(void);

	private:
		//array for saving qrcode
		unsigned char *QR_data;
		//array with size in pixels of qrcode generated
		int QR_width;
		//size of qrcode generated in bytes
		int SizeArray;
		//build a line of bmp struct
		void BuildLineBMPFileMonochromatic(int &l,unsigned char *MatrixBMP,int &m,const bool Write,const int Scale);
};


#endif /* _DLL_H_ */
