#include "doodlearea.h"

DoodleArea::DoodleArea(QWidget *parent) :
    QWidget(parent)
{
    this->setAttribute(Qt::WA_StaticContents);
    this->modified = false;
    this->doodling = false;
    this->currentColor = Qt::blue;
    this->currentTool = DOODLETOOL_PEN;

    this->resizeImage(this->size());
}

void DoodleArea::resizeImage(const QSize &newSize){
    this->image = new QImage(newSize, QImage::Format_RGB32);
}

void DoodleArea::setToolPen(){
    this->currentTool = DOODLETOOL_PEN;
}

void DoodleArea::setToolRect(){
    this->currentTool = DOODLETOOL_RECT;
}

void DoodleArea::setToolOval(){
    this->currentTool = DOODLETOOL_OVAL;
}

void DoodleArea::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        this->lastPoint = event->pos();
        this->doodling = true;
    }
}

void DoodleArea::mouseMoveEvent(QMouseEvent *event){
    if ((event->button() & Qt::LeftButton) && this->doodling && (this->currentTool == DOODLETOOL_PEN)){
        this->drawLineTo(event->pos());
    }
}

void DoodleArea::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && this->doodling){
        this->drawLineTo(event->pos());
        this->doodling = false;
    }
}
