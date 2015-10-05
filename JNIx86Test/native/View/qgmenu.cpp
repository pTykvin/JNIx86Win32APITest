#include "qgmenu.h"
#include <iostream>

QGMenu::QGMenu(QRect sceneRect)
{
    _timer = new QTimeLine(1000);
    _timer->setFrameRange(0, 100);
    _rect = QRectF(sceneRect);
    _opacity = 128;
    _color = new QColor("#000000");

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setItem(this);
    animation->setTimeLine(_timer);
    _timer->setEasingCurve(QEasingCurve::OutQuad);

    for (int i = 0; i < 1000; ++i)
        animation->setPosAt(i / 1000.0, QPointF(-i, -i));
}


QRectF QGMenu::boundingRect() const
{
    return _rect;
}

void QGMenu::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *widget)
{
    std::cout << widget;
    //_color->setAlpha(_opacity);
    //painter->setBrush(*_color);
    //painter->drawRect(boundingRect());
}

void QGMenu::setOpacity(int opacity)
{
    _opacity = opacity;
    update();
}

int QGMenu::getOpacity()
{
    return _opacity;
}

void QGMenu::fadeTo(int)
{

}


bool QGMenu::sceneEventFilter(QGraphicsItem *, QEvent *event)
{
    if (event->type() == QMouseEvent::UngrabMouse) {
        fadeTo(_opacity == 0 ? 128 : 0);
        _timer->start();
    }
    return false;
}
