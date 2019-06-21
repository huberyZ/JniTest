#include <string.h>
#include <jni.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <android/log.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TAG "JNITEST"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)


char * byteArrayToCharArray(JNIEnv *env, jbyteArray byteArray)
{
    return (char*)(*env)->GetByteArrayElements(env, byteArray, NULL);
}

void charArrayToByteArray(JNIEnv *env, char *bufArray, jbyteArray byteArray)
{
    int length = strlen(bufArray);

    (*env)->SetByteArrayRegion(env, byteArray, 0, length, bufArray);
}

JNIEXPORT void
Java_com_test_jnitest_jnitest_MainActivity_encryption( JNIEnv* env,jobject thiz, jbyteArray srcByte, jint srcLen, jbyteArray enByte)
{
    char *buf = malloc(srcLen + 1);
    memset(buf, 0, srcLen + 1);
    strncpy(buf, byteArrayToCharArray(env, srcByte), srcLen);
    LOGI("buf: %s\n", buf);
    char *p = buf;
    int i;
    for (i = 0; i < srcLen; i++) {
        *(p + i) = *(p + i) + 1;
    }

    charArrayToByteArray(env, buf, enByte);
    free(buf);
//    return (*env)->NewStringUTF(env, p);
//    return env->NewStringUTF((char *)"Hello from JNI !");
}


