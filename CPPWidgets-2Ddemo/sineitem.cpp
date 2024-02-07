#include "sineitem.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QtMath>

static const float MAX_X = 50;

SineItem::SineItem() {}

QRectF SineItem::boundingRect() const
{
    return QRectF(0, -1, MAX_X, 2);
}

void SineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const qreal detail = QStyleOptionGraphicsItem::levelOfDetailFromTransform(
        painter->worldTransform());
    const qreal dx = 1 / detail;

    QPen pen;
    pen.setCosmetic(true);
    painter->setPen(pen);
    const int steps = qRound(MAX_X / dx);
    QPointF previousPoint(0, sin(0));
    for (int i = 1; i < steps; ++i) {
        const float x = dx * i;
        QPointF point(x, sin(x));
        painter->drawLine(previousPoint, point);
        previousPoint = point;
    }

    if (option->state && QStyle::State_Selected) {
        pen.setColor(Qt::green);
    }
    painter->setPen(pen);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void SineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton) {
        float x = event->pos().x();
        QPointF point(x, sin(x));
        static const float r = 0.3;
        QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(-r, -r, 2 * r, 2 * r, this);
        ellipse->setPen(Qt::NoPen);
        ellipse->setBrush(QBrush(Qt::red));
        ellipse->setPos(point);
        event->accept();
    } else {
        event->ignore();
    }
}
