#ifndef DOODLEAREA_H
#define DOODLEAREA_H

#define DOODLETOOL_PEN 0
#define DOODLETOOL_RECT 1
#define DOODLETOOL_OVAL 2

#include <QWidget>
#include <QMouseEvent>

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
    //void resizeEvent(QResizeEvent *event);

signals:

public slots:
    void setToolPen();
    void setToolRect();
    void setToolOval();

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(const QSize &newSize);

    int currentTool;
    bool modified;
    bool doodling;
    QColor currentColor;
    QImage* image;
    QPoint lastPoint;

};

#endif // DOODLEAREA_H
