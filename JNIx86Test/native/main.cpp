#include <windows.h>
#include "h/HelloWorld.h"

int WINAPI IsolatedFunction(const char *title, const char *test)
{
    MessageBox(0, title, test, MB_OK);
    return 1;
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_HelloWorld_sayHello (JNIEnv *, jobject) {
    IsolatedFunction("Hello", "Hello World");
}

