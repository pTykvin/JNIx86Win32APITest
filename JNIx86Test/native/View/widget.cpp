#include "widget.h"
#include "ui_widget.h"
#include "qgtile.h"
#include "qgmenu.h"
#include <iostream>
#include <QGraphicsItemAnimation>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{


    ui->setupUi(this);
    this->setWindowState(this->windowState() ^ Qt::WindowFullScreen);
    QGraphicsView *view = ui->graphicsView;
    view->setScene(&scene);

    view->setWindowFlags (Qt::FramelessWindowHint);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setRenderHint(QPainter::Antialiasing);

    view->setMaximumSize(size());
    view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setCacheMode(QGraphicsView::CacheBackground);


    QGMenu *menu = new QGMenu(view->rect());
    //menu->setOpacity(0);
    scene.addItem(menu);

    int size = 152 + 16;

    for (int i = 0; i < 20 ;i++) {
        int r = i / 5;
        int c = i % 5;
        QGTile *tile = new QGTile;
        scene.addItem(tile);
        tile->moveBy(c * size,  r * size);
        tile->installSceneEventFilter(menu);
    }
    menu->setZValue(100);

//    QGraphicsItem *ball = new QGraphicsEllipseItem(0, 0, 20, 20);

//    QTimeLine *timer = new QTimeLine(5000);
//    timer->setFrameRange(0, 100);

//    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
//    animation->setItem(ball);
//    animation->setTimeLine(timer);

//    for (int i = 0; i < 200; ++i)
//        animation->setPosAt(i / 200.0, QPointF(i, i));

//    scene.addItem(ball);

//    timer->start();

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *, QEvent *)
{
    std::cout << "EVENT";
}
