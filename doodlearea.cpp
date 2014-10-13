#include "doodlearea.h"

DoodleArea::DoodleArea(QWidget *parent) :
    QWidget(parent)
{
    this->setAttribute(Qt::WA_StaticContents);
    this->modified = false;
    this->doodling = false;
    this->currentColor = Qt::blue;
    this->currentTool = DOODLETOOL_PEN;

    int width = this->size().width();
    int height = this->size().height();

    this->resizeImage(this->size());
//    this->clear();
}

void DoodleArea::resizeImage(const QSize &newSize){
    this->image = new QImage(newSize, QImage::Format_RGB32);
}

void DoodleArea::setToolPen(bool enabled){
    if(enabled){
        this->currentTool = DOODLETOOL_PEN;
        emit disableNonPen(false);
    }
}

void DoodleArea::setToolRect(bool enabled){
    if(enabled){
        this->currentTool = DOODLETOOL_RECT;
        emit disableNonRect(false);
    }
}

void DoodleArea::setToolOval(bool enabled){
    if(enabled){
        this->currentTool = DOODLETOOL_OVAL;
        emit disableNonOval(false);
    }
}

void DoodleArea::clear(){
    this->image->fill(Qt::white);
    this->modified = true;
    this->update();
}

void DoodleArea::drawLineTo(const QPoint &endPoint){
    QPainter painter(this->image);
    painter.setPen(QPen(this->currentColor, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(this->lastPoint, endPoint);
    this->lastPoint = endPoint;
    this->modified = true;
    this->update();
}

void DoodleArea::resizeEvent(QResizeEvent *event){
    this->resizeImage(event->size());
}

void DoodleArea::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        this->lastPoint = event->pos();
        this->doodling = true;
    }
}

void DoodleArea::mouseMoveEvent(QMouseEvent *event){
    if (/*(event->button() & Qt::LeftButton) && */this->doodling && (this->currentTool == DOODLETOOL_PEN)){
        this->drawLineTo(event->pos());
    }
}

void DoodleArea::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && this->doodling){
        if(this->currentTool == DOODLETOOL_PEN){
            this->drawLineTo(event->pos());
        } else if(this->currentTool == DOODLETOOL_RECT){
            QPainter painter(this->image);
            painter.fillRect(QRect(this->lastPoint, event->pos()), this->currentColor);
            this->update();
        } else if(this->currentTool == DOODLETOOL_OVAL){
            QPainter painter(this->image);
            painter.setBrush(QBrush(this->currentColor));
            painter.setPen(Qt::NoPen);
            painter.drawEllipse(QRect(this->lastPoint, event->pos()));
            this->update();
        }
        this->doodling = false;
    }
}

void DoodleArea::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, *this->image);
}
