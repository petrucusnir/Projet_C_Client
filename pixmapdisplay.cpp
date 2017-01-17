#include <QPainter>

#include "pixmapdisplay.h"
#include "sleeper.h"
PixmapDisplay::PixmapDisplay(QWidget *parent) :
    QWidget(parent)
{
    pm = new QPixmap(800, 800);
    pm->fill(Qt::white);
    this->setGeometry(10, 10, 810, 810);
}

PixmapDisplay::~PixmapDisplay()
{
    delete pm;
    this->~QWidget();
}

void PixmapDisplay::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, *pm);
}

void PixmapDisplay::setToPix(QPixmap *pix)
{
    QPixmap newpix(pix->scaled(800,800));
    pm->swap(newpix);
    this->update();
}
