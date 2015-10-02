#include "mainwindow.h"
#include <QApplication>
#include "../../out/production/JNIx86Test/ru_tykvin_jni_QTHelloWorld.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_QTHelloWorld_showWindow (JNIEnv *, jobject) {
//
}
