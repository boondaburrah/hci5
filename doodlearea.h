#ifndef DOODLEAREA_H
#define DOODLEAREA_H

#define DOODLETOOL_PEN 0
#define DOODLETOOL_RECT 1
#define DOODLETOOL_OVAL 2

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QFileDialog>

class DoodleArea : public QWidget
{
    Q_OBJECT
public:
    explicit DoodleArea(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent *event);

signals:
    void disableNonPen(bool disable);
    void disableNonRect(bool disable);
    void disableNonOval(bool disable);

public slots:
    void setToolPen(bool enabled);
    void setToolRect(bool enabled);
    void setToolOval(bool enabled);
    void setColor(int colorIndex);
    void setPenWidth(int size);
    void save();
    void clear();

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(const QSize &newSize);

    int currentTool;
    int currentPenSize;
    bool modified;
    bool doodling;
    QColor currentColor;
    QImage* image;
    QPoint lastPoint;

};

#endif // DOODLEAREA_H
