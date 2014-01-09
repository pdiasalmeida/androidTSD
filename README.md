androidTrafficSignDetector
==========================

# Build Base Project

## Environment setup for Android development with OpenCV

Further instructions to setup the developing environment can be found [here](http://docs.opencv.org/doc/tutorials/introduction/android_binary_package/android_dev_intro.html).

### Prerequisites

- Android SDK: http://developer.android.com/sdk/index.html
- Android NDK: http://developer.android.com/tools/sdk/ndk/index.html
- Eclipse IDE: http://www.eclipse.org/downloads/
- Eclipse ADT plugin: http://developer.android.com/sdk/installing/installing-adt.html
- OpenCV SDK for Android: http://opencv.org/downloads.html

## Clone Base project

	git clone https://github.com/pdiasalmeida/androidTSD.git

## Import to Eclipse

- Open Eclipse and navigate to File -> Import...;
- Choose the option “Existing Android Code Into Workspace”;
- Navigate to the folder where you cloned the project to and select it.

## Editing the Android.mk file

In the Android.mk file you have to change line 8 so that it points to the appropriate location in your setup.

	include <OpenCVAndroidSDKLocation>/sdk/native/jni/OpenCV.mk

## Building the native library

Navigate to the project directory and run ndk-build to build your native library for Android.

## Run the Application

Finally you are able to run the application using Eclipse.
