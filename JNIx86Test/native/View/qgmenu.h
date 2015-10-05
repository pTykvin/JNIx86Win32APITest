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
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

    void setOpacity(int opacity);
    int getOpacity();

    QRectF _rect;
    int _opacity;

private:
    QColor *_color;
    QTimeLine *_timer;
    void fadeTo(int opacity);
signals:

public slots:

    // QGraphicsItem interface
protected:
    virtual bool sceneEventFilter(QGraphicsItem *, QEvent *);
};

#endif // QGMENU_H
