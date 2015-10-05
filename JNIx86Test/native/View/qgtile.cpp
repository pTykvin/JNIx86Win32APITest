#include "qgtile.h"
#include <iostream>

using namespace std;

int QGTile::_z = 0;



QGTile::QGTile()
{
    _name = "NO NAME";

    _pressed = false;
    _color = QColor("#e4f7e5");
    _pressedColor = QColor("#6ec071");

    _shadow = new QGraphicsDropShadowEffect();
    _shadow->setBlurRadius(10);
    _shadow->setOffset(0,0);

    setGraphicsEffect(_shadow);

    setFlag(ItemIsMovable);
}

QRectF QGTile::boundingRect() const
{
    return QRectF(0,0,152,152);
}

void QGTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    paintBg(painter);
    QPen penHText(QColor(0, 0, 0, 136));
    painter->setPen(penHText);
    paintHead(painter);
    paintFoot(painter);
}

void QGTile::paintBg(QPainter *painter) {
    QRectF rect = boundingRect();

    painter->setPen(Qt::NoPen);
    painter->setBrush(_pressed ? _color : Qt::white);
    painter->drawRoundedRect(0, 0, rect.width(), rect.height(), 2, 2, Qt::AbsoluteSize);
    painter->setBrush(_pressed ? _pressedColor : _color);
    int y = 2 * rect.height() / 3;
    QRectF rectangle(0, y, rect.width(), rect.height() - y);
    painter->drawRoundedRect(rectangle, 2, 2, Qt::AbsoluteSize);
    rectangle.setHeight(10);
    painter->drawRect(rectangle);
}

void QGTile::paintHead(QPainter *painter) {
    QRectF rect = boundingRect();

    QFont font("Roboto");
    font.setPixelSize(56);
    painter->setFont(font);
    int h = 2 * rect.height() / 3;
    QRectF rectangle(0, 0, rect.width(), h);
    painter->drawText(rectangle, Qt::AlignCenter, _name.left(2));
}

void QGTile::paintFoot(QPainter *painter)
{
    QRectF rect = boundingRect();

    QFont font("Roboto");
    font.setPixelSize(16);
    painter->setFont(font);
    int y = 2 * rect.height() / 3;
    QRectF rectangle(0, y, rect.width(), rect.height() - y);
    painter->drawText(rectangle.marginsRemoved(QMarginsF(8, 4 , 8, 4)), Qt::AlignLeft, _name);
}

void QGTile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    _pressed = true;
    _shadow->setBlurRadius(5);
    update();
    QGraphicsItem::mousePressEvent(event);
}

void QGTile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    _pressed = false;
    _shadow->setBlurRadius(10);
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

bool QGTile::sceneEvent(QEvent *event)
{
    qDebug() << event->type();
    switch(event->type()) {
    case QMouseEvent::GrabMouse:
        setOpacity(0.5);
        setZValue(++QGTile::_z);
        break;
    case QMouseEvent::UngrabMouse:
        setOpacity(1.0);
        if (_callback != NULL) {
            (*_callback)(&_name);
        }
        break;
    default:
        break;
    }
    QGraphicsItem::sceneEvent(event);
    return true;
}
