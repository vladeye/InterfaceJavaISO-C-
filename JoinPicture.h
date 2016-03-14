#ifndef _JOIN_PICTURE_H_
#define _JOIN_PICTURE_H_

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

class DLLIMPORT PictureTools
{
	public:
		//constructor
		PictureTools();

		//destructor
		virtual ~PictureTools(void);

		/*
		 * Class:     PictureTools
		 * Method:    JoinBMPPictures
		 *  const char ** const FilesBMP: files to be joined
		 *	const int NumFiles			: num of files in FilesBMP
		 *	const char *FileOutput		: file output
		*/
		static bool JoinBMPPictures(const char FilesBMP[][128],const int NumFiles,const char * const FileOutput);

		/*
		 * Class:     PictureTools
		 * Method:    JoinBMPPictures
		 *  const string * const FilesBMP: files to be joined
		 *	const int NumFiles			: num of files in FilesBMP
		 *	const char *FileOutput		: file output
		*/
		static bool JoinBMPPictures(const string * const FilesBMP,const int NumFiles,const char * const FileOutput);

		/*
		 * Class:     PictureTools
		 * Method:    JoinBMPPictures
		 *  const string * const FilesBMP: files to be joined
		 *	const int NumFiles			: num of files in FilesBMP
		 *	const string &FileOutput	: file output
		*/
		static bool JoinBMPPictures(const string * const FilesBMP,const int NumFiles,const string &FileOutput);

		/*
		 * Class:     PictureTools
		 * Method:    JoinBMPPictures
		 *  const char ** const FilesBMP: files to be joined
		 *	const int NumFiles			: num of files in FilesBMP
		 *	const string &FileOutput	: file output
		*/
		static bool JoinBMPPictures(const char FilesBMP[][128],const int NumFiles,const string &FileOutput);

		/*
		 * Class:     PictureTools
		 * Method:    GetSizeOfBMPPicture
		 *  const char * const NameFile	: file to get size
		 *	int &Width					: return width
		 *	int &Height					: return height
		*/
		static bool GetSizeOfBMPPicture(const char * const NameFile,int &Width, int &Height);

		/*
		 * Class:     PictureTools
		 * Method:    GetSizeOfBMPPicture
		 *  const string &NameFile		: file to get size
		 *	int &Width					: return width
		 *	int &Height					: return height
		*/
		static bool GetSizeOfBMPPicture(const string &NameFile,int &Width, int &Height);

		/*
		 * Class:     PictureTools
		 * Method:    ExportTextAsBMP
		 * 	const char Text[][128]		: Lines to generate bmp File
		 *	const int Lines				: Number of lines to generate
		 *	const int ScaleWidth		: Scale widht of chars
		 *	const int ScaleHeight		: Scale height of chars
		 *	int &Width					: return weidth of generated image
		 *	int &Height					: return height of generated image
		 *	const char * const NameFileOutput: output file
		*/
		static bool ExportTextAsBMPMonochromatic(const char Text[][128],const int Lines,const int ScaleWidth,const int ScaleHeight,int &Width,int &Height,const char * const NameFileOutput);

		/*
		 * Class:     PictureTools
		 * Method:    ExportTextAsBMP
		 * 	const char Text[][128]		: Lines to generate bmp File
		 *	const int Lines				: Number of lines to generate
		 *	const int ScaleWidth		: Scale widht of chars
		 *	const int ScaleHeight		: Scale height of chars
		 *	int &Width					: return weidth of generated image
		 *	int &Height					: return height of generated image
		 *	const string &NameFileOutput: output file
		*/
		static bool ExportTextAsBMPMonochromatic(const char Text[][128],const int Lines,const int ScaleWidth,const int ScaleHeight,int &Width,int &Height,const string &NameFileOutput);

		/*
		 * Class:     PictureTools
		 * Method:    ExportTextAsBMP
		 * 	const string Text[]			: Lines to generate bmp File
		 *	const int Lines				: Number of lines to generate
		 *	const int ScaleWidth		: Scale widht of chars
		 *	const int ScaleHeight		: Scale height of chars
		 *	int &Width					: return weidth of generated image
		 *	int &Height					: return height of generated image
		 *	const string &NameFileOutput: output file
		*/
		static bool ExportTextAsBMPMonochromatic(const string Text[],const int Lines,const int ScaleWidth,const int ScaleHeight,int &Width,int &Height,const string &NameFileOutput);

		/*
		 * Class:     PictureTools
		 * Method:    ExportTextAsBMP
		 * 	const string Text[]			: Lines to generate bmp File
		 *	const int Lines				: Number of lines to generate
		 *	const int ScaleWidth		: Scale widht of chars
		 *	const int ScaleHeight		: Scale height of chars
		 *	int &Width					: return weidth of generated image
		 *	int &Height					: return height of generated image
		 *	const char * const NameFileOutput: output file
		*/
		static bool ExportTextAsBMPMonochromatic(const string Text[],const int Lines,const int ScaleWidth,const int ScaleHeight,int &Width,int &Height,const char * const NameFileOutput);

		/*
		 * Class:     PictureTools
		 * Method:    ExportTextAsBMP
		 * 	const char * const Text		: Lines to generate bmp File
		 *	const int ScaleWidth		: Scale widht of chars
		 *	const int ScaleHeight		: Scale height of chars
		 *	int Width					: width of generated image
		 *	const string &NameFileOutput: output file
		*/
		static bool ExportTextAsBMPMonochromatic(const char * const Text,const int ScaleWidth,const int ScaleHeight,const int Width,const char * const NameFileOutput);

	private:

};


#endif /* _DLL_H_ */
