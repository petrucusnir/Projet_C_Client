#include "clienttcp.h"
#include "sleeper.h"

ClientTcp::ClientTcp(PixmapDisplay *_PixD)
{
    port=4000; // choix arbitraire (>1024)
    PixD = _PixD;
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

    QByteArray frame(soc.readAll());
    QDataStream in(&frame, QIODevice::ReadOnly);
    qreal x;
    qreal y;
    in >> y >> x;
    qDebug() << x << y;
}
