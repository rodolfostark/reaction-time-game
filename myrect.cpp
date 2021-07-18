#include "myrect.h"
#include "jogador.h"

#include <QTimer>
#include <QBrush>
#include <QDebug>
#include <QKeyEvent>

#include <random>
#include <iostream>
#include <algorithm>

MyRect::MyRect()
{
    QTimer *main_timer = new QTimer();
    // Conectar o timer com o método redraw.
    connect(main_timer, SIGNAL(timeout()), this, SLOT(reDraw()));
    main_timer->start(2000);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    pontuar(event->key());
}

void MyRect::reDraw()
{
    int offset_x = rand() % 300 + 1;
    int offset_y = rand() % 300 + 1;
    setPos(offset_x, offset_y);
    int posicaoDaCor = rand() % cores.size();
    setBrush(cores[posicaoDaCor]);
}

void MyRect::pontuar(int botaoClicado)
{
    // Definir como ficará a relação de cores e setas do teclado
    // Vermelho = ->; Verde = ^; Azul = <-; Magenta v.
    // Verificar qual era a cor/seta esperada e comparar a que de fato foi clicada
    // Atribuir a pontuação
    if (mapaCoresSetas[botaoClicado] == brush().color()){
        std::cout << "Acertou otário!" << std::endl;
        Jogador::pontuacao += 1;
    }
    else {
        std::cout << "Errou otário!" << std::endl;
        if (Jogador::pontuacao > 0)
            Jogador::pontuacao -= 1;
        else
            Jogador::pontuacao = 0;
    }
}

