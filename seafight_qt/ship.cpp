#include "ship.h"

#include <QtCore>
#include <QtGui>

Field *  Ship::field_ = 0 ;

QRectF Ship::boundingRect() const {

    return QRectF ( field_ -> physicPoint( QPoint( 3,4 ) ) 
            , QSize( field_ -> shipSize() * size_ , field_ -> shipSize() ) ) ;
}



void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    QColor color( "Qt::red"  ) ;

    // Body
    painter->setBrush(color);
    painter->drawEllipse(-10, -20, 20, 40);

    // Eyes
    painter->setBrush(Qt::white);
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);

    // Nose
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(-2, -22, 4, 4));

    // Pupils
    painter->drawEllipse(QRectF(-8.0 , -17, 4, 4));
    painter->drawEllipse(QRectF(4.0 + 0 , -17, 4, 4));

    // Ears
    painter->setBrush(/*scene()->collidingItems(this).isEmpty() ? */ Qt::darkYellow/* : Qt::red*/);
    painter->drawEllipse(-17, -12, 16, 16);
    painter->drawEllipse(1, -12, 16, 16);

    // Tail
    QPainterPath path(QPointF(0, 20));
    path.cubicTo(-5, 22, -5, 22, 0, 25);
    path.cubicTo(5, 27, 5, 32, 0, 30);
    path.cubicTo(-5, 32, -5, 42, 0, 35);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);

    painter -> fillRect( QRect( QPoint( 0 , 0 ) 
            , QSize( field_ -> shipSize() * size_ 
                , field_ -> shipSize() ) ) , Qt::black   ) ;


}




