#include <myrect.h>
#include <QKeyEvent>
#include <QTimer>

#include <QDebug>
#include <random>

MyRect::MyRect()
{
    QTimer * main_timer = new QTimer();

    // conectar o timer com a função redraw
    connect(main_timer, SIGNAL(timeout()), this, SLOT(redraw()));

    main_timer->start(500);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10, y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }
}

void MyRect::redraw()
{
    int off_x = rand() % 300 + 1;
    int off_y = rand() % 300 + 1;
    setPos(off_x, off_y);
}

