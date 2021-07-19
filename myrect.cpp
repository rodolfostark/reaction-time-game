#include "myrect.h"

#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QKeyEvent>

#include <random>
#include <iostream>
#include <unistd.h>
#include <algorithm>

MyRect::MyRect()
{

}

MyRect::MyRect(QLabel *label, QLabel *label_t_reacao)
{
    this->label = label;
    this->label_t_reacao = label_t_reacao;

    main_timer = new QTimer();
    tempo_de_jogo = new QTimer();
    // Conectar o timer com o método moscou e com redraw.
    connect(main_timer, SIGNAL(timeout()), this, SLOT(moscouVei()));
    connect(main_timer, SIGNAL(timeout()), this, SLOT(reDraw()));
    // Conectar o timer tempo_de_jogo ao slot acabarJogo
    connect(tempo_de_jogo, SIGNAL(timeout()), this, SLOT(acabarJogo()));
    main_timer->start(2500);
    tempo_de_jogo->start(30000);    // 30s de tempos
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
    setPen(cores[posicaoDaCor]);
    reagiu = false;
}

void MyRect::moscouVei()
{
    if(!reagiu) {
        if (pontuacao > 0)
            pontuacao--;
    }

}

void MyRect::acabarJogo()
{
    sleep(5);
    exit(0);
}

void MyRect::pontuar(int botaoClicado)
{
    // Definir como ficará a relação de cores e setas do teclado
    // Vermelho = ->; Verde = ^; Azul = <-; Magenta v.
    // Verificar qual era a cor/seta esperada e comparar a que de fato foi clicada
    // Atribuir a pontuação
    int timeOut;
    if (mapaCoresSetas[botaoClicado] == brush().color()){
        std::cout << "Acertou!" << std::endl;
        timeOut = main_timer->remainingTime();
        tempos.append(main_timer->interval() - timeOut);

        pontuacao++;
    }
    else {
        std::cout << "Errou!" << std::endl;
        timeOut = main_timer->remainingTime();
        tempos.append(main_timer->interval() - timeOut);

        if (pontuacao > 0)
            pontuacao--;
    }

    // calcula a media dos tempos
    for(auto tempo: tempos) {tempo_reacao += tempo;}
    tempo_reacao = tempo_reacao/tempos.size();

    if(tempos.size() > 5) {
        tempos.pop_front();
    }

    QString pontuacaoString = QString::number(pontuacao);
    QString tempoMedioReacaoString = QString::number(tempo_reacao);
    label->setText("Pontuação: " + pontuacaoString);
    label_t_reacao->setText("Reação Média: " + tempoMedioReacaoString + "ms");

    usleep(timeOut * 1000);
}

