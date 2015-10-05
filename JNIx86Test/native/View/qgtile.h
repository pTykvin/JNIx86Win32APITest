#ifndef QGTILE_H
#define QGTILE_H

#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsDropShadowEffect>

void callback(void (*pf)(char*));

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
    jmethodID _callMethod;
    void (*_callback)(QString *);

    void setName(QString name) { _name = name; }
    void setCallback(void (*callback)(QString *)) {
        _callback = callback;
    }

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
