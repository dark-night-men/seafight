#include "ship.h"
#include "field.h"

#include <stdio.h>
#include <stdlib.h>

#include <QtCore>
#include <QtGui>

#include <QApplication>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QPixmap>
#include <QPainter>
#include <QColor>


int main (  int argc ,  char * argv[]  ) {


    QApplication app( argc , argv ) ;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QMessageBox msgBox;
    msgBox.setText( "seafight has been started" );
    msgBox.exec();

    const int fieldSize = QApplication::desktop() -> width() / ( float ) 2 ;
    const int halfField = fieldSize / ( float ) 2 ;

    Field field( 10 , fieldSize ) ;
//    field . setZValue( 0 ) ;
    //field . setPos( - halfField , - halfField ) ;
    field . setPos( 0 , 0 ) ;
    Ship::setField( &field ) ;

    QGraphicsScene scene;
    scene.setSceneRect( 0 , 0 ,  fieldSize + 10  , fieldSize + 10 );
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

//    Ship *ship = new Ship ( true , 3 );
//    ship -> setPos(  QPoint( 1,1 ) ) ;
//
    Ship ship ( true , 3 );
    ship . setPos( field . physicPoint(  QPoint( 1,1 ) ) ) ;


    scene . addItem( &field ) ;
    scene . addItem( & ship );
/*
    for (int i = 0; i < MouseCount; ++i) {
        Mouse *mouse = new Mouse;
        mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
                      ::cos((i * 6.28) / MouseCount) * 200);
        scene.addItem(mouse);
    }
*/

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Seafight"));

#if defined(Q_WS_S60) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    view.showMaximized();
#else
    view.resize( fieldSize , fieldSize );

    //view.resize( view . width() , view . height() );
    view.show();
#endif

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);

    return app . exec() ;

}
