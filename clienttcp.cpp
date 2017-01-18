#include "clienttcp.h"
#include "sleeper.h"
#include "pixitem.h"
#include <QGraphicsColorizeEffect>

ClientTcp::ClientTcp(GraphicScene *_Scene, GraphicView *_view)
{
    port=4000; // choix arbitraire (>1024)
    scene = _Scene;
    view = _view;
    QObject::connect(&soc,SIGNAL(connected()),this,SLOT(connexion_OK()));
    // signal émis lors de la connexion au serveur
    QObject:: connect(&soc, SIGNAL(readyRead()), this, SLOT(lecture()));
    // signal émis lorsque des données sont prêtes à être lues
}
void ClientTcp::recoit_IP(QString IP2)
{
    IP=IP2;
    soc.connectToHost(IP,port); // pour se connecter au serveur
}
void ClientTcp::recoit_texte(QString t)
{
    QTextStream texte(&soc); // on associe un flux à la socket
    texte << t<<endl;        // on écrit dans le flux le texte saisi dans l'IHM
}
void ClientTcp::connexion_OK()
{
    emit vers_IHM_connexion_OK(); // on envoie un signal à l'IHM
}
void ClientTcp::lecture()
{
    /*
    QByteArray frame(soc.readAll());
    QDataStream in(&frame, QIODevice::ReadOnly);
    QPixmap pix;
    in >> pix;
    PixD->setToPix(&pix);
    */
    scene->clear();
    QByteArray frame(soc.readAll());
    QDataStream in(&frame, QIODevice::ReadOnly);
    qreal xToSee;
    qreal yToSee;
    in >> xToSee >> yToSee;
    view->setSceneRect(xToSee, yToSee, 800, 800);
    while(!in.atEnd())
    {
        qreal x;
        qreal y;
        qreal rotation;
        int TypeCorp;
        int red;
        int green;
        int blue;
        qreal strength;
        double scaleX;
        double scaleY;
        in >> x >> y >> rotation >> TypeCorp >> red >> green >> blue >> strength >> scaleX >> scaleY;
        PixItem *PixToAdd = new PixItem(TypeCorp, rotation, x, y);
        QGraphicsColorizeEffect *colorEffect = new QGraphicsColorizeEffect();
        colorEffect->setColor(QColor(red, green, blue));
        colorEffect->setStrength(strength);
        PixToAdd->setGraphicsEffect(colorEffect);
        PixToAdd->scale(scaleX, scaleY);
        scene->addItem(PixToAdd);
        PixToAdd->setPos(x - PixToAdd->boundingRect().width()/2, y - PixToAdd->boundingRect().height()/2);
    }
}
