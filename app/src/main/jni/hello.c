#include <stdio.h>
#include <string.h>
#include <jni.h>
#include <android/log.h>

//宏定义，由于C中调用log的函数是__android_log_print()，为了简便，因此使用宏定义

#define  LOG_TAG    "C_LOG"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

//第一个参数JNIEnv* JNIEnv是一个结构体，里面定义了大量的函数指针，供开发使用。
//第二个参数是jobject 就是调用当前native方法的Java对象

JNIEXPORT jstring JNICALL Java_pub_yanng_jnidemo01_MainActivity_getValueFromC
        (JNIEnv *env, jobject thiz){
    //在LogCat中输出日志
    LOGI("调用 C getValueFromC() 函数\n");
    char *str = "Hello JNI，I'm from C";
    //通过NewStringUTF函数将C的字符串转换成java的jstring类型。
    return (*env)->NewStringUTF(env,str);
}

JNIEXPORT void JNICALL Java_pub_yanng_jnidemo01_MainActivity_setValueToC
        (JNIEnv *env, jobject thiz, jstring str){
    //在LogCat中输出日志
    LOGI("调用 C setValueToC() 函数\n");
    char *string = (char*)(*env)->GetStringUTFChars(env, str, NULL);
    LOGI("您设置的值为：%s\n", string);

    // 显示释放转换成UTf-8的string空间，如果不显示调用，JVM会一直保存该对象，不回收，容易导致内存溢出
    (*env)->ReleaseStringUTFChars(env, str, string);
}