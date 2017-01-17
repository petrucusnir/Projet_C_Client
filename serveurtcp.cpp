#include "serveurtcp.h"

ServeurTcp :: ServeurTcp (QObject *parent)
{
    listen(QHostAddress::Any,4000);
    QObject:: connect(this, SIGNAL(newConnection()),
    this, SLOT(demande_connexion()));
}

// si un client demande une connexion
void ServeurTcp :: demande_connexion()
 {
    emit vers_IHM_connexion(); // on envoie un signal à l'IHM
    // on crée une nouvelle socket pour ce client
    clientConnection = nextPendingConnection();
    // si on reçoit des données, le slot lecture() est appelé
    QObject:: connect(clientConnection, SIGNAL(readyRead()),
    this, SLOT(lecture()));
}
void ServeurTcp ::lecture()
{
    QString ligne;
    while(clientConnection->canReadLine())    // tant qu'on peut lire sur la socket
    {
        ligne = clientConnection->readLine(); // on lit une ligne
        emit vers_IHM_texte(ligne);           // on l'envoie à l'IHM
    }
    QTextStream texte(clientConnection);      // création d'un flux pour écrire dans la socket
    texte << "message reçu" << endl;          // message à envoyer au client
    texte.flush();
}

