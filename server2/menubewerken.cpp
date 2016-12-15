#include "menubewerken.h"
#include "ui_menubewerken.h"
#include <QMessageBox>
#include <QFile>
#include "QDebug"
#include <QString>
#include <QList>

menuBewerken::menuBewerken(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menuBewerken)
{
    ui->setupUi(this);
    this->setWindowTitle("Menu bewerken");
    updateMenu();
}

menuBewerken::~menuBewerken()
{
    delete ui;
}

void menuBewerken::updateMenu()
{
    QString buffer;
    QFile file("hoofdMenu.txt");
    QFile onderFile("onderMenu.txt");

    //lijst leegmaken
    this->ui->hoofdMenuList->clear();
    this->ui->onderMenuList->clear();

    //Hoofdmenu file openen
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0, "Error!", "Kon hoofdmenu file niet openen!");
    }

    //Ondermenu file openen
    if(!onderFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0, "Error!", "Kon ondermenu file niet openen!");
    }

    QTextStream in(&file);
    QTextStream inOnder(&onderFile);

    //Hoofdmenu inlezen en wegschrijven naar lijst.
    while(!in.atEnd())
    {
        buffer = in.readLine();
        if(buffer!="")
        {
            this->ui->hoofdMenuList->addItem(buffer);
        }
    }

    //Ondermenu inlezen en wegschrijven naar lijst
    while(!inOnder.atEnd())
    {
        buffer = inOnder.readLine();
        if(buffer!="")
        {
            this->ui->onderMenuList->addItem(buffer);
        }
    }

    //Files sluiten
    file.close();
    onderFile.close();
}

void menuBewerken::on_pushButton_2_clicked()
{
    QString buffer = this->ui->hoofdMenuInput->text();
    this->ui->hoofdMenuInput->clear();
    QFile file("hoofdMenu.txt");

    if(!file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QMessageBox::warning(0, "Error!", "Kon file niet openen");
    }

    QTextStream out(&file);
    out << "\n";
    out << buffer;

    file.close();
    updateMenu();
}

void menuBewerken::on_pushButton_clicked()
{
    QMessageBox::warning(0, "Error!", "Deze functie is nog niet gemaakt!");
}

void menuBewerken::on_pushButton_3_clicked()
{
    QString buffer = this->ui->onderMenuInput->text();
    this->ui->onderMenuInput->clear();
    QFile file("onderMenu.txt");

    if(!file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QMessageBox::warning(0, "Error!", "Kon file niet openen");
    }

    QTextStream out(&file);
    out << "\n";
    out << buffer;

    file.close();
    updateMenu();
}
