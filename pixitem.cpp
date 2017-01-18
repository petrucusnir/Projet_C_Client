#include <QPixmap>
#include <QDir>
#include <QTimer>
#include <QDebug>
#include <QVariantAnimation>
#include "pixitem.h"

PixItem::PixItem(int _TypeCorp, qreal rotation, qreal x, qreal y, GraphicScene *scene, PixItem *parent) :
    QGraphicsPixmapItem(parent, scene)
{
    switch(_TypeCorp)
    {
    case 1 : this->setPixmap(QPixmap("../Projet_C_Client/PIC/Vaisseau1.png")); break;
    case 2 : this->setPixmap(QPixmap("../Projet_C_Client/PIC/missile.png")); this->scale(2, 2); break;
    case 3 : this->setPixmap(QPixmap("../Projet_C_Client/PIC/asteroide.png")); break;
    case 4 : this->setPixmap(QPixmap("../Projet_C_Client/PIC/particle2.png")); break;
    case 5 : this->setPixmap(QPixmap("../Projet_C/PIC/wall2.png")); break;
    case 6 : this->setPixmap(QPixmap("../Projet_C_Client/PIC/fissure.png")); break;
    case 7 : this->setPixmap(QPixmap("../Projet_C_Client/PIC/partial.png")); break;
    case 8 : this->setPixmap(QPixmap("../Projet_C_Client/PIC/exploded.png")); break;
    default: qDebug() << "error";
    }
    QTransform t = transform();
    t.translate(boundingRect().width()/2, boundingRect().height()/2);
    t.rotate(rotation);
    t.translate(-boundingRect().width()/2, -boundingRect().height()/2);
    setTransform(t);
    setPos(x, y);
    readyToAnimate = true;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(AnimAux()));
    //vitesse = new Vec2D(0, 0);
}

PixItem::~PixItem()
{
    delete timer;
    //delete vitesse;
    this->deleteLater();
}

void PixItem::Animation(QList<QString> SPI)
{
    if(personalAnimation.isEmpty())
    {
        QListIterator<QString> i(SPI);
        while (i.hasNext())
        {
            personalAnimation += i.next();
        }
        timer->start(100);
        readyToAnimate = false;
    }
}

void PixItem::AnimAux()
{
    if(personalAnimation.isEmpty())
    {
        readyToAnimate = true;
        timer->stop();
    }else{
        QPixmap pix(personalAnimation.takeFirst());
        this->setPixmap(pix);
        this->scene()->update();
    }
}

/*
void PixItem::setVitesse(Vec2D *v)
{
    vitesse->set(v->x, v->y);
}*/

void PixItem::toDataStream(QDataStream *_dataStream)
{
    *_dataStream << x() << y() << TypeCorp;
}

