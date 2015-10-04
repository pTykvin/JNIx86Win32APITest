#include <windows.h>
#include "../h/Win32HelloWorld.h"
using namespace std;

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_Win32HelloWorld_showWindow
  (JNIEnv *, jobject) {
    MessageBox(NULL,"Hello, World!","Test",MB_OK);
}

JNIEXPORT jint JNICALL Java_ru_tykvin_jni_nativeinvokers_Win32HelloWorld_getForegroundHwnd
  (JNIEnv *, jobject) {
/*int hwnd;
    HWND foreHwnd;
    foreHwnd = GetForegroundWindow();
    hwnd = (int) foreHwnd;
    return hwnd;
*/
    return 0;
}
