#ifndef GRAPHICSCENE
#define GRAPHICSCENE

#include <QObject>
#include <QGraphicsScene>
#include <QDataStream>

class GraphicScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GraphicScene(QObject *parent);
    ~GraphicScene();

    void toDataStream(QDataStream *_dataStream);
};


#endif // GRAPHICSCENE

