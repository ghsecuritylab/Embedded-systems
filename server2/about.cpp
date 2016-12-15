#include "about.h"
#include "ui_about.h"
#include "QDebug"
#include "QDateTime"
#include "QString"

about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{    
    QString buffer;
    QDateTime huidigeTijd = QDateTime::currentDateTime();
    ui->setupUi(this);
    this->setWindowTitle("About");

    buffer = "Compile time: ";
    buffer += huidigeTijd.toString();

    this->ui->compileTime->setText(buffer);
}

about::~about()
{
    delete ui;
}

void about::on_pushButton_clicked()
{
    this->destroy();
}
