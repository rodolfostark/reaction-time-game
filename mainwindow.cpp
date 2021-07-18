#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jogador.h"

#include <string>

#include <QtWidgets>
#include <QApplication>
#include <QLocale>
#include <QTranslator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::modificarLabelPontuacao() {
    QString pontuacao = QString::number(Jogador::pontuacao);
    ui->label->setText(pontuacao);
}
