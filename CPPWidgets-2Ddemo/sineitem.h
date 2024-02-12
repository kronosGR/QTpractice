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
    float maxX() const;
    void setMaxX(float newMaxX);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    float m_maxX;
};

#endif // SINEITEM_H
