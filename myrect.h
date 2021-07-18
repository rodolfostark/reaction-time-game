#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class MyRect: public QObject,
        public QGraphicsRectItem
{
    Q_OBJECT
public:
    MyRect();
    void keyPressEvent(QKeyEvent * event);
    QVector<QColor> cores = {Qt::red, Qt::blue, Qt::green, Qt::magenta};
    // Vermelho = ->; Verde = ^; Azul = <-; Magenta v.
    QMap<int, QColor> mapaCoresSetas = {{Qt::Key_Right, Qt::red},
                                        {Qt::Key_Up, Qt::green},
                                        {Qt::Key_Left, Qt::blue},
                                        {Qt::Key_Down, Qt::magenta}};
    void pontuar(int botaoClicado);
public slots:
    void reDraw();
};

#endif // MYRECT_H
