#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QPushButton>

#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <random>

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

void MainWindow::show_temp(){
    for (int i = 0; i < 5; i++) {
        QPushButton *button = new QPushButton(QApplication::translate("childwidget", "Press me"), this);
        int x, y;
        x = rand() % 200;
        y = rand() % 200;
        button->move(200+x, 200+y);
        button->show();
        //sleep(1);
    }
}

void MainWindow::on_BOTAOZINHO_clicked()
{
    ui->LABELZASSA->setText("teucu!");
}
