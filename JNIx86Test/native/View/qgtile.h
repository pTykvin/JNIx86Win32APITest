#ifndef QGTILE_H
#define QGTILE_H

#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsDropShadowEffect>
#include <jni.h>

class QGTile : public QGraphicsItem
{
public:
    QGTile();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool _pressed;
    QString _name;
    QColor _color;
    QColor _pressedColor;
    QGraphicsDropShadowEffect *_shadow;
    jmethodID _callback;

    void setName(QString name) { _name = name; }
    void setCallback(jmethodID callback) { _callback = callback;}

    void paintBg(QPainter *painter);
    void paintHead(QPainter *painter);
    void paintFoot(QPainter *painter);

static int _z;

signals:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:

    // QGraphicsItem interface
protected:
    virtual bool sceneEvent(QEvent *event);
};

#endif // QGTILE_H
