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
    painter -> fillRect( QRect( QPoint( 0 , 0 ) , field_ -> shipSize ( 3 , horizontal_ ) ) , Qt::black ) ;
}




