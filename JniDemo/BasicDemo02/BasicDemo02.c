#include "BasicDemo02.h"
#include <iostream>
#include <string>

using namespace std;

JNIEXPORT jstring JNICALL Java_BasicDemo02_sayHello (JNIEnv *env, jobject obj, jstring jstr) {
    const char* str = env->GetStringUTFChars(jstr, NULL);
    if (NULL == str) 
    {
        return NULL;
    }

    cout << "c received string: " << str <<endl;
    //释放内存
    env->ReleaseStringUTFChars(jstr, str);

    string outStr = "String from C++";
    return env->NewStringUTF(outStr.c_str());
}