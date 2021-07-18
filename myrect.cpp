#include <myrect.h>

#include <QDebug>
void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        setPos(x()-10, y());
    }
}
