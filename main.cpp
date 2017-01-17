#include <QApplication>
#include "mainwindow.h"
#include <unistd.h>
#include <QDebug>
#include "clienttcp.h"
#include <QInputDialog>
#include <QDir>
#include "pixmapdisplay.h"

#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include <phonon/mediasource.h>
#include <phonon/videowidget.h>

using namespace Phonon;

int main(int argc, char *argv[])

{
    srand(time(NULL));

    QApplication app(argc, argv);
    MainWindow mwindow;
    mwindow.setGeometry(50,50,950,950);
    PixmapDisplay PixD(&mwindow);
    mwindow.show();
    ClientTcp c1(&PixD);
    QString ip = "localhost";
    c1.recoit_IP(ip);
    bool ok;
    QString text = QInputDialog::getText(&mwindow, "Hello", "enter text", QLineEdit::Normal,
                          QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
    {
        c1.recoit_texte(text);
    }

    return app.exec();

}
