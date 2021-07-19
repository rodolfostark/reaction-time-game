#ifndef MYRECT_H
#define MYRECT_H

#include <QTimer>
#include <QLabel>
#include <QObject>
#include <QGraphicsRectItem>

class MyRect: public QObject,
        public QGraphicsRectItem
{
    Q_OBJECT
public:
    MyRect();
    MyRect(QLabel *label);
    void keyPressEvent(QKeyEvent * event);
    QVector<QColor> cores = {Qt::red, Qt::blue, Qt::green, Qt::magenta};
    // Vermelho = ->; Verde = ^; Azul = <-; Magenta v.
    QMap<int, QColor> mapaCoresSetas = {{Qt::Key_Right, Qt::red},
                                        {Qt::Key_Up, Qt::green},
                                        {Qt::Key_Left, Qt::blue},
                                        {Qt::Key_Down, Qt::magenta}};
    void pontuar(int botaoClicado);
    QLabel *label;
    QTimer *main_timer;
    int pontuacao = 0;
    bool reagiu = false;
public slots:
    void reDraw();
    void moscouVei();
};

#endif // MYRECT_H
