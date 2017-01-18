#include "graphicscene.h"
#include "pixitem.h"

GraphicScene::GraphicScene(QObject *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(QBrush(QPixmap("../Projet_C/PIC/Galaxie3.png")));
}


GraphicScene::~GraphicScene()
{
    this->~QGraphicsScene();
}

void GraphicScene::toDataStream(QDataStream *_dataStream)
{
    QList<QGraphicsItem*> ListOfItems = this->items();
    QListIterator<QGraphicsItem*> i(ListOfItems);
    while(i.hasNext())
    {
        PixItem *PixI = static_cast<PixItem*>(i.next());
        PixI->toDataStream(_dataStream);
    }
    //*_dataStream << ListOfItems.size();
}
