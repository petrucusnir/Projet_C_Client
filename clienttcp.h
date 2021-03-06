#ifndef CLIENTTCP
#define CLIENTTCP

#include <QObject>
#include <QTcpSocket>

//#include "pixmapdisplay.h"
#include "graphicscene.h"
#include "graphicview.h"

class ClientTcp : public QObject
{
Q_OBJECT
public :
    ClientTcp(GraphicScene *_Scene, GraphicView *_view);
public slots :
    void recoit_IP(QString IP2);  // en provenance de l'IHM et se connecte au serveur
    void recoit_texte(QString t); // en provenance de l'IHM et écrit sur la socket
private slots :
    void connexion_OK();  // en provenance de la socket et émet un signal vers l'IHM
    void lecture();       // en provenance de la socket, lit la socket, émet un signal vers l'IHM
signals :
    void vers_IHM_connexion_OK();
    void vers_IHM_texte(QString);
private :
    QString IP;
    int port;
    QTcpSocket soc;
    GraphicScene *scene;
    GraphicView *view;
};

#endif // CLIENTTCP
