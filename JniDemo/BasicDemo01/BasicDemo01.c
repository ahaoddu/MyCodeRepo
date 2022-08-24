#include "BasicDemo01.h"
#include <iostream>

using namespace std;

JNIEXPORT jdouble JNICALL Java_BasicDemo01_average(JNIEnv * env, jobject obj, jint n1, jint n2) {

    cout << "n1 = " << n1 <<", n2 = " << n2 << endl;
    return jdouble ((n1 + n2)/2.0);

}