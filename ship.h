#ifndef SHIP_H
#define SHIP_H

#include "field.h"
#include <QGraphicsItem>
#include <QObject>


class Ship : public QGraphicsItem {

public :
    Ship( bool horizontal , int size )
        : horizontal_ ( horizontal )
        , size_ ( size )
    {
    }

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) ;
    static void setField( Field * field ) {
        field_ = field ;
    }

private :
    bool horizontal_ ;
    int size_ ;

    static Field * field_ ;

} ;

#endif
