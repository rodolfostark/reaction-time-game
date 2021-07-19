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
    MyRect(QLabel *label, QLabel *label_t_reacao);
    void keyPressEvent(QKeyEvent * event);
    QVector<QColor> cores = {Qt::red, Qt::blue, Qt::green, Qt::magenta};
    // Vermelho = ->; Verde = ^; Azul = <-; Magenta v.
    QMap<int, QColor> mapaCoresSetas = {{Qt::Key_Right, Qt::red},
                                        {Qt::Key_Up, Qt::green},
                                        {Qt::Key_Left, Qt::blue},
                                        {Qt::Key_Down, Qt::magenta}};
    void pontuar(int botaoClicado);
    QLabel *label;
    QLabel *label_t_reacao;
    QTimer *main_timer;
    QTimer *tempo_de_jogo;
    int pontuacao = 0;
    int tempo_reacao = 0;
    QVector<int> tempos;
    bool reagiu = false;
public slots:
    void reDraw();
    void moscouVei();
    void acabarJogo();
};

#endif // MYRECT_H
