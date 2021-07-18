#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QPushButton>


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
    MainWindow w;
    w.show();



    QPushButton *button = new QPushButton(QApplication::translate("childwidget", "Press me"), &w);
    button->move(w.geometry().width()/2 - button->geometry().width()/2,
                 w.geometry().height()/2 - button->geometry().height()/2);

    // Calculando os intervalos de amostragem do botão
    struct timeval tempo_inicial, tempo_final;
    int tempo_milisegundos = 0;
    gettimeofday(&tempo_inicial, NULL);  // início é uma struct com dois campos:tv_sec e tv_usec.

    button->show();
    while (tempo_milisegundos < 10000) {
       gettimeofday(&tempo_final, NULL);
       tempo_milisegundos = (int) (1000 * (tempo_final.tv_sec - tempo_inicial.tv_sec) + (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000);
    }
    return a.exec();
}
