#include "field.h"
#include <QDebug>
#include <assert.h>
#include <QPixmap>
#include <QPainter>
#include <QColor>


void dprint( const QString & s ) 
{
    qDebug( qPrintable( s ) ) ;
}

template < typename T >
QString point2String( const T & p ) 
{
    return QString( "x:%1 y:%2" ) . arg( p.x() ) . arg( p.y() ) ;
}



Field::Field( int logicSize , int physicSize )
    //: QGraphicsPixmapItem()
    : logicSize_ ( logicSize ) 
    , physicSize_ ( physicSize )
    , shipSize_ ( 0 )
    , margin_ ( physicSize_ / ( (float) 50 ) )
    , spacing_ ( margin_ / ( ( float ) 3 ) )
{

    shipSize_ = ( physicSize_ - 2*margin_ - ( logicSize_ - 1 ) * spacing_ ) / ( /*(float)*/ logicSize_ ) ;
    dprint( QString( "ls %1 , ps %2 , m %3 , s %4 , ship %5"  ) .
        arg( logicSize_  ) . arg( physicSize_ ) . arg( margin_ ) . arg( spacing_ ) . arg( shipSize_ ) ) ; 

    QPixmap *pix_ = new QPixmap( physicSize_ , physicSize_ ) ;
    QPainter *paint = new QPainter(pix_);

    paint -> fillRect( QRect( QPoint( 0 , 0 ) 
        , QSize( physicSize_ , physicSize_ ) ) , Qt::gray ) ;

    paint->setPen( QColor(255,34,255,255) );
    for ( int k = 0 ; k < logicSize_ ; ++k  ) {
        for ( int j = 0 ; j < logicSize_ ; ++j  ) {

            paint -> drawRect( QRect( physicPoint( QPoint ( j , k ) ) , QSize(  shipSize_ , shipSize_ ) ) ) ;
        }
    }

    paint->setPen( QColor( Qt::yellow  ) );
    paint->drawRect(0,0,physicSize_,physicSize_);

    setPixmap( *pix_ );
}

void Field::assertOutOfLogicalField( const QPoint & p ) 
{
    assert( p.x() > -1 and p.x() < logicSize_ and
            p.y() > -1 and p.y() < logicSize_ ) ;
}


void Field::assertOutOfPhysicalField( const QPoint & p) 
{
    assert( p.x() > -1 and p.x() < physicSize_ and
            p.y() > -1 and p.y() < physicSize_ ) ;
}



QPoint Field::logicPoint ( const QPoint & p ) 
{
    assertOutOfPhysicalField( p ) ;

    int k = ( p . x() - margin_ ) / ( shipSize_ + spacing_ ) ;
    int k1 = ( p . x() - margin_ ) % ( shipSize_ + spacing_ ) ;

    int q = ( p . y() - margin_ ) / ( shipSize_ + spacing_ ) ;
    int q1 = ( p . y() - margin_ ) % ( shipSize_ + spacing_ ) ;

    int nx = -1 ;
    int ny = -1 ;
    if ( k1 > 0 and k1 < shipSize_ ){
       nx = k ; 
    }

    if ( q1 > 0 and q1 < shipSize_ ){
       ny = q ; 
    }

   
    //QPoint pr( p.x()*(float) logicSize_/physicSize_ 
    //        , p.y()*(float) logicSize_/physicSize_ ) ;
    QPoint pr ( nx , ny ) ;
//    dprint( QString( "Field::logicPoint in- %1 ; out- %2"  ) 
//            . arg( point2String( p ) ) . arg( point2String( pr ) )  ) ;

    return pr ;
}

//returns top left corner coords of the cell
QPoint Field::physicPoint ( const QPoint & p ) 
{
    assertOutOfLogicalField( p ) ;

    //QPoint pr( p.x()*physicSize_ / (float) logicSize_ 
    //        , p.y()*physicSize_ / (float) logicSize_ ) ;
      
    QPoint pr( margin_ + p . x() * ( shipSize_ + spacing_ ) , margin_ + p . y() * ( shipSize_ + spacing_ )) ;

    //dprint( QString( "Field::physicPoint in- %1 ; out- %2"  ) 
    //        . arg( point2String( p ) ) . arg( point2String( pr ) )  ) ;

    return pr ;

}

QSize Field::shipSize( int size , bool horizontal ) const 
{
    Q_ASSERT( size < logicSize_ ) ;


    QSize shipSize( shipSize_ * size + spacing_ * ( size  - 1 ) , shipSize_ ) ;  
    return horizontal ? shipSize : shipSize . transposed() ;
}


void  Field::mouseMoveEvent( QGraphicsSceneMouseEvent * event ) 
{
    dprint( QString( "mouseMoveEvent %1"  ) . arg( point2String( event -> scenePos() ) ) );

}

void  Field::mousePressEvent( QGraphicsSceneMouseEvent * event ) 
{
    dprint( QString( "mousePressEvent %1"  ) . arg( point2String( event -> scenePos() ) ) );

}
