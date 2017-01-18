#ifndef GRAPHICVIEW
#define GRAPHICVIEW

#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QSet>
#include <QTimer>
#include "graphicscene.h"
//#include "./PRO/vaisseau.h"
//#include "./PRO/missile.h"
//#include "./PRO/devil.h"

class GraphicView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphicView(GraphicScene *scene, QWidget *parent);
    ~GraphicView();

    //void setVaisseau(Vaisseau *v);
    //void setDevil(Devil *d);
    //void setMissile(Missile *m);
    //Devil *devil;
    //Vaisseau *ship;
    double vitesse; //vitesse à laquelle la view bouge
    QTimer *timer;
/*
public slots:
    void handleMultipleKeys();*/
/*
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);*/

private:
    QSet<int> KE;

    //Missile *missil;

};

#endif // GRAPHICVIEW

