#include <QPainter>

#include "pixmapdisplay.h"

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
    pm = pix;
}
