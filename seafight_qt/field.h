#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Field : public QGraphicsPixmapItem {
public :

    Field( int logicSize , int physicSize ) ;
    virtual ~Field( ) ;

    void assertOutOfLogicalField( const QPoint & ) ;
    void assertOutOfPhysicalField( const QPoint & ) ;

    QPoint logicPoint ( const QPoint & p ) ;
    QPoint physicPoint ( const QPoint & p ) ;

    int shipSize() const {
        return shipSize_ ;
    }

    int logicSize() const {
        return logicSize_ ;
    }

    int physicSize() const {
        return physicSize_ ;
    }

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




