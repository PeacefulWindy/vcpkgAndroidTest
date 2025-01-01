#include <jni.h>
#include <string>
#include<fmt/format.h>

extern "C" JNIEXPORT jstring JNICALL
Java_org_agpl_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = fmt::format("Hello {}","vcpkg");
    return env->NewStringUTF(hello.c_str());
}