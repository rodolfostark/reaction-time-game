#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    MyRect();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void redraw();
};

#endif // MYRECT_H
