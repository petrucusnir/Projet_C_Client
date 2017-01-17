#include <QApplication>
#include "mainwindow.h"
#include <unistd.h>
#include <QDebug>
#include "clienttcp.h"
#include <QInputDialog>
#include <QDir>

using namespace Phonon;

int main(int argc, char *argv[])

{
    srand(time(NULL));

    QApplication app(argc, argv);

    ClientTcp c1;
    QString ip = "192.168.43.98";
    c1.recoit_IP(ip);
    QWidget showWid;
    showWid.setGeometry(10,10,200,200);
    showWid.show();
    while(true)
    {
        bool ok;
        QString text = QInputDialog::getText(&showWid, "Hello", "enter text", QLineEdit::Normal,
                              QDir::home().dirName(), &ok);
        if (ok && !text.isEmpty())
        {
            c1.recoit_texte(text);
        }
    }

    return app.exec();

}
