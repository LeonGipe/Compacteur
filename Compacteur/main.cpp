#include <QApplication>
#include "compileur.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    compilClass *compil = new compilClass;
    compil->show();

    return app.exec();
}

