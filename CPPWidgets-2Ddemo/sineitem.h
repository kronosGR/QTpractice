#ifndef SINEITEM_H
#define SINEITEM_H

#include <QGraphicsItem>

class SineItem : public QGraphicsItem
{
public:
    SineItem();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SINEITEM_H
