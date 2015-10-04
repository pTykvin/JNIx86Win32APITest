#include "qgmenu.h"
#include <iostream>

QGMenu::QGMenu(QRect sceneRect)
{
    _timer = new QTimeLine(1000);
    _timer->setFrameRange(0, 100);
    _rect = QRectF(sceneRect);

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

void QGMenu::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void QGMenu::fadeTo(int opacity)
{

}


bool QGMenu::sceneEventFilter(QGraphicsItem *watched, QEvent *event)
{
    if (event->type() == QMouseEvent::UngrabMouse) {
        fadeTo(_opacity == 0 ? 128 : 0);
        _timer->start();
    }
    return false;
}
