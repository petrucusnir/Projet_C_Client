#include "graphicview.h"
#include <QDebug>
#include "mainwindow.h"

GraphicView::GraphicView(GraphicScene *scene, QWidget *parent):
    QGraphicsView(scene, parent)
{
    this->setGeometry(20, 20, 820, 820);
    this->setSceneRect(0, 0, 800, 800);
    this->setMinimumSize(805, 805);
    this->setMaximumSize(805, 805);

    vitesse = 0.5;
    /*
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(handleMultipleKeys()));*/
}

GraphicView::~GraphicView()
{
    //delete ship;
    //delete missil;
    delete timer;
    this->~GraphicView();
}

/*
void GraphicView::keyPressEvent(QKeyEvent *event)
{
    KE += event->key();
    switch(event->key())
    {
    case Qt::Key_E:
        KE -= event->key();
        MainWindow *mWind = static_cast<MainWindow*>(this->parent()->parent());
        mWind->changeMusic();
        break;
    }
}

void GraphicView::keyReleaseEvent(QKeyEvent *event)
{
    KE -= event->key();
    switch(event->key())
    {
    case Qt::Key_Z :
        if(!event->isAutoRepeat())
        {
            ship->turnOffGas();
        }
        break;
    }
}*/

/*
void GraphicView::setVaisseau(Vaisseau *v)
{
    ship = v;
}*/

/*
void GraphicView::setDevil(Devil *d)
{
    devil = d;
}*/

/*
void GraphicView::handleMultipleKeys()
{
    QRectF rect = this->sceneRect();
    rect.adjust(0, vitesse, 0, vitesse);
    this->setSceneRect(rect);

    QSetIterator<int> i(KE);
    while (i.hasNext())
    {
        switch(i.next())
        {
        case Qt::Key_Q : ship->rotate(-1); break;
        case Qt::Key_D : ship->rotate(1); break;
        case Qt::Key_Z : ship->turnOnGas(); break;
        case Qt::Key_Space : ship->tirer(); break;
        }
    }
}
*/
