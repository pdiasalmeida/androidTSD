#include <jni.h>

#ifndef _Included_com_example_trafficsigndetector_NativeTrafficSignDetector
#define _Included_com_example_trafficsigndetector_NativeTrafficSignDetector

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeCreateObject
(JNIEnv *, jclass);

JNIEXPORT void JNICALL Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeDestroyObject
(JNIEnv *, jclass, jlong);

JNIEXPORT void JNICALL Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeDetect
(JNIEnv *, jclass, jlong, jlong, jlong);

#ifdef __cplusplus
}
#endif

#endif
