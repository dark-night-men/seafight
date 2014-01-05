#include "field.h"
#include <assert.h>
#include <QPixmap>
#include <QPainter>
#include <QColor>


void dprint( const QString & s ) {
    qDebug( qPrintable( s ) ) ;
}

QString point2String( const QPoint & p ) {

    return QString( "x:%1 y:%2" ) . arg( p.x() ) . arg( p.y() ) ;

}

Field::Field( int logicSize , int physicSize )
    //: QGraphicsPixmapItem()
    : logicSize_ ( logicSize ) 
    , physicSize_ ( physicSize )
    , shipSize_ ( physicSize/(float) logicSize ) 
{
    QPixmap *pix_ = new QPixmap( physicSize_ , physicSize_ ) ;
    QPainter *paint = new QPainter(pix_);

    paint -> fillRect( QRect( QPoint( 0 , 0 ) 
        , QSize( physicSize_ , physicSize_ ) ) , Qt::gray ) ;

    paint->setPen(*(new QColor(255,34,255,255)));

    for ( int k =1 ; k < logicSize_ ; ++k ) {

        int v1 = k * physicSize_ / ( float ) logicSize_  ;

        paint -> drawLine( 0 , v1 , physicSize_ , v1  ) ;
        paint -> drawLine( v1 , 0 , v1 , physicSize_   ) ;
    }

    paint->drawRect(0,0,physicSize_,physicSize_);

    setPixmap( *pix_ );
}

 Field::~Field( ) {
    //delete pix_ ;
}

void Field::assertOutOfLogicalField( const QPoint & p ) {
    assert( p.x() > -1 and p.x() < logicSize_ and
            p.y() > -1 and p.y() < logicSize_ ) ;
}


void Field::assertOutOfPhysicalField( const QPoint & p) {
    assert( p.x() > -1 and p.x() < physicSize_ and
            p.y() > -1 and p.y() < physicSize_ ) ;
}



QPoint Field::logicPoint ( const QPoint & p ) {
    assertOutOfPhysicalField( p ) ;
    
    QPoint pr( p.x()*(float) logicSize_/physicSize_ 
            , p.y()*(float) logicSize_/physicSize_ ) ;
    dprint( QString( "Field::logicPoint in- %1 ; out- %2"  ) 
            . arg( point2String( p ) ) . arg( point2String( pr ) )  ) ;

    return pr ;
}

//returns top left corner coords of the cell
QPoint Field::physicPoint ( const QPoint & p ) {
    assertOutOfLogicalField( p ) ;

    QPoint pr( p.x()*physicSize_ / (float) logicSize_ 
            , p.y()*physicSize_ / (float) logicSize_ ) ;
    dprint( QString( "Field::physicPoint in- %1 ; out- %2"  ) 
            . arg( point2String( p ) ) . arg( point2String( pr ) )  ) ;

    return pr ;

}


