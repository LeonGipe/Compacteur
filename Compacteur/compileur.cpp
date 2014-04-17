#include "compileur.h"

compilClass::compilClass()
{
    QPushButton *buttonFichier = new QPushButton("Fichier png/jpg"), *buttonArchive = new QPushButton("Fichier zip/rar"), *buttonResul = new QPushButton("Fichier png/jpg"),
                *buttonExec = new QPushButton("Terminer");
    buttonFichier->setMinimumHeight(40);
    buttonArchive->setMinimumHeight(35);
    buttonResul->setMinimumHeight(35);
    buttonExec->setMinimumHeight(35);

    QLabel *labelFichier = new QLabel("Etape 1 :\nSélectionnez une image, c'est celle qui sera visible sur le résultat final.\nNous vous conseillons une "
                                      "image pas très lourde, et peut-être même,\nqui explique comment ouvrire l'archive qui s'y cache.");
    QLabel *labelArchive = new QLabel("Etape 2 :\nSélectionnez une archive, c'est celle qui sera contenue dans l'image.\nNous vous conseillons d'utiliser"
                                      "une archive de type zip.");
    QLabel *labelResul = new QLabel("Etape 3 :\nChoisissez où vous voulez sauvegarder le résultat, laissez par défaut\nsi vous voulez écraser l'image d'origine.");
    QLabel *labelExec = new QLabel("Etape 4 :\nCliquez sur terminer, assurez-vous d'avoir complété toute les étapes\nprécédente.");

    lineFichier.setReadOnly(true);
    lineArchive.setReadOnly(true);

    QFrame *line1 = new QFrame;
    line1->setGeometry(QRect(160, 150, 3, 61));
    line1->setFrameShape(QFrame::HLine);
    line1->setFrameShadow(QFrame::Sunken);
    QFrame *line2 = new QFrame;
    line2->setGeometry(QRect(160, 150, 3, 61));
    line2->setFrameShape(QFrame::HLine);
    line2->setFrameShadow(QFrame::Sunken);
    QFrame *line3 = new QFrame;
    line3->setGeometry(QRect(160, 150, 3, 61));
    line3->setFrameShape(QFrame::HLine);
    line3->setFrameShadow(QFrame::Sunken);

    QHBoxLayout *firstBox = new QHBoxLayout;
    firstBox->addWidget(labelFichier);
    firstBox->addWidget(buttonFichier);
    QHBoxLayout *secondBox = new QHBoxLayout;
    secondBox->addWidget(labelArchive);
    secondBox->addWidget(buttonArchive);
    QHBoxLayout *thirdBox = new QHBoxLayout;
    thirdBox->addWidget(labelResul);
    thirdBox->addWidget(buttonResul);
    QHBoxLayout *fourthBox = new QHBoxLayout;
    fourthBox->addWidget(labelExec);
    fourthBox->addWidget(buttonExec);
    QVBoxLayout *finalBox = new QVBoxLayout;
    finalBox->addLayout(firstBox);
    finalBox->addWidget(&lineFichier);
    finalBox->addWidget(line1);
    finalBox->addLayout(secondBox);
    finalBox->addWidget(&lineArchive);
    finalBox->addWidget(line2);
    finalBox->addLayout(thirdBox);
    finalBox->addWidget(&lineResul);
    finalBox->addWidget(line3);
    finalBox->addLayout(fourthBox);

    setLayout(finalBox);
    setWindowTitle("Compacteur");

    connect(buttonFichier, SIGNAL(clicked()), this, SLOT(selectImage()));
    connect(buttonArchive, SIGNAL(clicked()), this, SLOT(selectArchive()));
    connect(buttonResul, SIGNAL(clicked()), this, SLOT(selectResul()));
    connect(buttonExec, SIGNAL(clicked()), this, SLOT(execCopy()));
}

void compilClass::selectImage()
{
    lineFichier.setText(QFileDialog::getOpenFileName(this, "Sélectionnez une image", QDesktopServices::storageLocation(QDesktopServices::DesktopLocation), "Images (*.png *.jpg)"));
    lineResul.setText(lineFichier.text());
}

void compilClass::selectArchive()
{
    lineArchive.setText(QFileDialog::getOpenFileName(this, "Sélectionnez une archive", QDesktopServices::storageLocation(QDesktopServices::DesktopLocation), "Archives (*.zip *.rar)"));
}

void compilClass::selectResul()
{
    lineResul.setText(QFileDialog::getSaveFileName(this, "Enregistrez sous...", QDesktopServices::storageLocation(QDesktopServices::DesktopLocation), "Images (*.png *.jpg)"));
}

void compilClass::execCopy()
{
    if(lineFichier.text().isEmpty() || lineArchive.text().isEmpty() || lineResul.text().isEmpty())
    {
        QMessageBox::warning(this, "ATTENTION", "Veuillez compléter toutes les étapes.");
    }
    else
    {
        QString commande("copy /b \"" + lineFichier.text().replace("/", "\\") + "\" + \"" + lineArchive.text().replace("/", "\\") + "\" \"" + lineResul.text().replace("/", "\\") + "\"");
        system(commande.toStdString().c_str());
    }
}
