#ifndef PIXITEM
#define PIXITEM

#include <QObject>
#include <QList>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "graphicscene.h"
//s#include "PRO/vec2d.h"

class PixItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit PixItem(int _TypeCorp, qreal rotation, qreal x, qreal y, GraphicScene *scene = NULL, PixItem *parent = NULL);
    ~PixItem();

    void Animation(QList<QString> SPI);
    int TypeCorp; //1 : vaisseau, 2 : missile, 3 : asteroid, 4 : particle
    bool readyToAnimate;
    //Vec2D *vitesse;
    //void setVitesse(Vec2D *v);
    void toDataStream(QDataStream *_dataStream);

public slots:
    void AnimAux();

private:
    QTimer *timer;
    QList<QString> personalAnimation;
};

#endif // PIXITEM

