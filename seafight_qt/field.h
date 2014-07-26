#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Field : public QGraphicsPixmapItem {
public :

    Field( int logicSize , int physicSize ) ;

    void assertOutOfLogicalField( const QPoint & ) ;
    void assertOutOfPhysicalField( const QPoint & ) ;

    QPoint logicPoint ( const QPoint & p ) ;
    QPoint physicPoint ( const QPoint & p ) ;

    int shipSize() const {
        return shipSize_ ;
    }

    QSize shipSize( int size , bool horizontal = true) const ;

    int logicSize() const {
        return logicSize_ ;
    }

    int physicSize() const {
        return physicSize_ ;
    }

    int spacing() const {
        return spacing_ ;
    }


    void  mouseMoveEvent( QGraphicsSceneMouseEvent * event ) ;
    void  mousePressEvent( QGraphicsSceneMouseEvent * event ) ;
    void  hoverMoveEvent( QGraphicsSceneHoverEvent * event ) ;

private :

    int logicSize_ ;
    int physicSize_ ;
    int shipSize_ ;

    QPixmap * pix_ ;

    int margin_ ;
    int spacing_ ;
} ;


void dprint( const QString & s ) ;

#endif




