//#include "widget.h"
#include <QGraphicsScene>
#include <QMainWindow>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsView>

#include "qgmenu.h"
#include "qgtile.h"
#include "../h/QTViewHelloWorld.h"

int i;
QGraphicsScene *scene;
void addTile(const char*, jmethodID callback);
QApplication *app;
QGMenu *menu;

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

    addTile(name, NULL);

//    scene->addItem(menu);

//    for (int i = 0; i < 20 ;i++) {
//        int r = i / 5;
//        int c = i % 5;
//        QGTile *tile = new QGTile;
//        scene->addItem(tile);
//        tile->moveBy(c * size,  r * size);
////        tile->installSceneEventFilter(menu);
//    }
//    menu->setZValue(100);

    window.setCentralWidget(view);
    window.show();
    return app->exec();
}

void addTile(const char *name, jmethodID callback) {
    int size = 152 + 16;
    int r = i / 5;
    int c = i % 5;
    QGTile *tile = new QGTile;
    scene->addItem(tile);
    tile->moveBy(c * size,  r * size);
    tile->installSceneEventFilter(menu);
    tile->setCallback(callback);
    tile->setName(name);
    i++;
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTViewHelloWorld_showView
  (JNIEnv *, jobject){
    if (app == NULL)
        main(1, new char*);
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTViewHelloWorld_addTile
  (JNIEnv *env, jobject, jstring name) {
    if (name != NULL) {
        const char * path = env->GetStringUTFChars(name, FALSE);

//        jclass cls = env->FindClass( "ru/tykvin/jni/nativeinvokers/Callback");
//        jmethodID midInit = env->GetMethodID( cls, "<init>", "(I)V");
//        // Call back constructor to allocate a new instance, with an int argument
//        jobject newObj = env->NewObject( cls, midInit, callback);

//        // Try runnning the toString() on this newly create object
//        jmethodID midToCall = env->GetMethodID( cls, "call", "(Ljava/lang/String;)V");
        addTile(path, NULL);
    }
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTViewHelloWorld_close
  (JNIEnv *, jobject){

}

