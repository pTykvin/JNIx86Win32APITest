#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();       
    return a.exec();
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTHelloWorld_close (JNIEnv *, jobject) {
    QApplication::exit(0);
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTHelloWorld_showWindow (JNIEnv *, jobject) {
    char** args = new char*;
    main(1, args);
}
