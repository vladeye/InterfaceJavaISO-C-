#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef WIN32
#include <windows.h>
#endif
#include <jni.h>


#include <string>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif



/*
 * Class:     InterfaceJava
 * Method:    QRCode
 *	jobjectArray Fields		: fields
 */
JNIEXPORT jcharArray JNICALL Java_InterfaceJavaISO_NMC_BuildIsoMessage
  (JNIEnv *env, jobject obj, jobjectArray Fields,jint transaction);


string InterfaceJavaISO_NMC_BuildIsoMessage (string Fields[][2] , int size , int trancsation);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
