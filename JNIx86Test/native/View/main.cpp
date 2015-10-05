//#include "widget.h"
#include <QGraphicsScene>
#include <QMainWindow>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsView>

#include "qgmenu.h"
#include "qgtile.h"
#include "../h/QTViewHelloWorld.h"

#include <iostream>
#include <jni.h>

using namespace std;

int i;
QGraphicsScene *scene;
void addTile(const char*);
QApplication *app;
QGMenu *menu;


static JavaVM* cachedJVM;

jmethodID midToCall = NULL;
jobject globalCallback = NULL;

int main(int argc, char *argv[])
{

    app = new QApplication(argc, argv);
    QMainWindow window;

    scene = new QGraphicsScene(&window);


    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);

    view->setWindowFlags (Qt::FramelessWindowHint);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setRenderHint(QPainter::HighQualityAntialiasing);

    view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setCacheMode(QGraphicsView::CacheBackground);

    menu = new QGMenu(view->rect());
    menu->setOpacity(0);
    //view->setWindowState(view->windowState() ^ Qt::WindowFullScreen);

    const char *name = "test";

    addTile(name);

//    scene->addItem(menu);

//    for (int i = 0; i < 20 ;i++) {
//        int r = i / 5;
//        int c = i % 5;
//        QGTile *tile = new QGTile;
//        scene->addItem(tile);
//        tile->moveBy(c * size,  r * size);
//        tile->installSceneEventFilter(menu);
//    }
//    menu->setZValue(100);

    window.setCentralWidget(view);
    window.show();
    return app->exec();
}

void call (QString *name) {
    if (cachedJVM != NULL) {
        cout << "g_vm = " << cachedJVM << endl;
        JNIEnv *env;
        cachedJVM->AttachCurrentThread((void **)&env, NULL);
        cout << "g_vm = " << env << endl;
        env->CallObjectMethod(globalCallback, midToCall, env->NewStringUTF(name->toUtf8().data()));
    }
}

void addTile(const char *name) {
    int size = 152 + 16;
    int r = i / 5;
    int c = i % 5;
    QGTile *tile = new QGTile;
    scene->addItem(tile);
    tile->moveBy(c * size,  r * size);
    tile->installSceneEventFilter(menu);
    tile->setCallback(call);
    tile->setName(name);
    i++;
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTViewHelloWorld_showView
  (JNIEnv *, jobject){
    if (app == NULL)
        main(1, new char*);
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTViewHelloWorld_addTileN
  (JNIEnv *, jobject, jstring name, jobject callback) {
    if (name != NULL && cachedJVM != NULL) {
        JNIEnv *env;
        cachedJVM->AttachCurrentThread((void **)&env, NULL);
        const char * path = env->GetStringUTFChars(name, FALSE);
        jclass cls = env->FindClass( "ru/tykvin/jni/nativeinvokers/Callback");
        midToCall = env->GetMethodID( cls, "call", "(Ljava/lang/String;)V");     
        globalCallback = env->NewGlobalRef(callback);       
        cout << "ADD TILE " << path;
        //env->CallObjectMethod(globalCallback, midToCall, name);

        //jmethodID midInit = env->GetMethodID( cls, "<init>", "(I)V");

//        jobject newObj = env->NewObject( cls, midInit, callback);

//        jmethodID midToCall = env->GetMethodID( cls, "call", "(Ljava/lang/String;)V");

//        _env->CallObjectMethodV(callback, midToCall, "TEST");

        addTile(path);
    }
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTViewHelloWorld_close
  (JNIEnv *, jobject){

}

jint JNI_OnLoad(JavaVM* aVm, void* )
{
    // cache java VM
    cachedJVM = aVm;
    cout << "INIT JVM REFERENCE";
    return JNI_VERSION_1_8;
}

