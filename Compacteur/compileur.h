#ifndef COMPILEUR_H
#define COMPILEUR_H

#include <QtCore>
#include <QtGui>

class compilClass : public QWidget
{
    Q_OBJECT
public:
    compilClass();
private slots:
    void selectImage();
    void selectArchive();
    void selectResul();
    void execCopy();
private:
    QLineEdit lineFichier;
    QLineEdit lineArchive;
    QLineEdit lineResul;
};

#endif // COMPILEUR_H
