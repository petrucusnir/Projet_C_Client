#ifndef PIXMAPDISPLAY
#define PIXMAPDISPLAY

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>

class PixmapDisplay : public QWidget
{
    Q_OBJECT

public:
    PixmapDisplay(QWidget *parent = 0); // Init Wid Game
    ~PixmapDisplay(); // Wid Game deleter

    void setToPix(QPixmap *pix);

protected:
    void paintEvent(QPaintEvent *);

private:
    QPixmap *pm; // pixmap of wid
};

#endif // PIXMAPDISPLAY

