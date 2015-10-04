#ifndef QGMENU_H
#define QGMENU_H

#include <QEvent>
#include <QDebug>
#include <QPainter>
#include <QTimeLine>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>

class QGMenu : public QGraphicsItem
{
public:
    QGMenu(QRect sceneRect);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setOpacity(int opacity);
    int getOpacity();

    QRectF _rect;
    int _opacity = 128;

private:
    QColor *_color = new QColor("#000000");
    QTimeLine *_timer;
    void fadeTo(int opacity);
signals:

public slots:

    // QGraphicsItem interface
protected:
    virtual bool sceneEventFilter(QGraphicsItem *watched, QEvent *event);
};

#endif // QGMENU_H
