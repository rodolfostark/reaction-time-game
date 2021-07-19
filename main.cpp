#include "mainwindow.h"
#include "jogador.h"

#include <QLabel>
#include <QLocale>
#include <QTranslator>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <myrect.h>
#include <sys/time.h>

int Jogador::pontuacao = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ReactionTimeGame_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    // Criar a cena.
    QGraphicsScene *cena = new QGraphicsScene();
    cena->setSceneRect(0, 0, 400, 400);
    // Criar a label.
    QLabel *label = new QLabel("Pontuacao:");
    label->setGeometry(200, 0, 100, 50);
    // criar item pra botar na cena (retangulo)
    MyRect *retangulo = new MyRect(label);
    retangulo->setRect(0, 0, 100, 100);
    // add item na cena
    cena->addItem(retangulo);
    cena->addWidget(label);
    // fazer rect ficar focado (para receber key checks)
    retangulo->setFlag(QGraphicsItem::ItemIsFocusable);
    retangulo->setFocus();
    // add view
    QGraphicsView *view = new QGraphicsView(cena);
    //view->setGeometry(0, 0, 400, 400);
    view->show();

    return a.exec();
}
