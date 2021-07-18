#include "mainwindow.h"

#include <QLocale>
#include <QTranslator>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <myrect.h>
#include <sys/time.h>

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
    // criar cena
    QGraphicsScene *cena = new QGraphicsScene();
    // criar item pra botar na cena (retangulo)
    MyRect *retangulo = new MyRect();
    retangulo->setRect(0, 0, 100, 100);
    retangulo->setBrush(Qt::yellow);
    // add item na cena
    cena->addItem(retangulo);
    // fazer rect ficar focado (para receber key checks)
    retangulo->setFlag(QGraphicsItem::ItemIsFocusable);
    retangulo->setFocus();
    // add view
    QGraphicsView *view = new QGraphicsView(cena);
    view->setGeometry(0, 0, 400, 400);
    view->show();

    return a.exec();
}
