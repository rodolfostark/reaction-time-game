#include "myrect.h"
#include "jogador.h"

#include <QBrush>
#include <QDebug>
#include <QKeyEvent>

#include <random>
#include <iostream>
#include <unistd.h>
#include <algorithm>

MyRect::MyRect()
{
    main_timer = new QTimer();
    // Conectar o timer com o método redraw.
    connect(main_timer, SIGNAL(timeout()), this, SLOT(reDraw()));
    main_timer->start(2000);
}

MyRect::MyRect(QLabel *label)
{
    this->label = label;
    main_timer = new QTimer();
    // Conectar o timer com o método redraw.
    connect(main_timer, SIGNAL(timeout()), this, SLOT(moscouVei()));
    connect(main_timer, SIGNAL(timeout()), this, SLOT(reDraw()));
    main_timer->start(2500);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    reagiu = true;
    pontuar(event->key());
}

void MyRect::reDraw()
{
    int offset_x = rand() % 300 + 1;
    int offset_y = (rand() % 200 + 1) + 100;
    setPos(offset_x, offset_y);
    int posicaoDaCor = rand() % cores.size();
    setBrush(cores[posicaoDaCor]);
    reagiu = false;
}

void MyRect::moscouVei()
{
    if(!reagiu) {
        if (pontuacao > 0 && (pontuacao - 2500) >= 0) {
            pontuacao -= 2500;
        } else {
            pontuacao = 0;
        }

        qDebug() << "moscou vei";
    }

}

void MyRect::pontuar(int botaoClicado)
{
    // Definir como ficará a relação de cores e setas do teclado
    // Vermelho = ->; Verde = ^; Azul = <-; Magenta v.
    // Verificar qual era a cor/seta esperada e comparar a que de fato foi clicada
    // Atribuir a pontuação
    int timeOut;
    if (mapaCoresSetas[botaoClicado] == brush().color()){
        std::cout << "Acertou otário!" << std::endl;
        timeOut = main_timer->remainingTime();
        pontuacao += timeOut;
    }
    else {
        std::cout << "Errou otário!" << std::endl;
        timeOut = main_timer->remainingTime();
        if (pontuacao > 0 && (pontuacao - timeOut) >= 0)
            pontuacao -= timeOut;
        else
            pontuacao = 0;
    }
    QString pontuacaoString = QString::number(pontuacao);
    label->setText("Pontuação: " + pontuacaoString);
    usleep(timeOut * 1000);
}

