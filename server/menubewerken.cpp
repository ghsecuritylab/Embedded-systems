#include "menubewerken.h"
#include "ui_menubewerken.h"

menuBewerken::menuBewerken(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menuBewerken)
{
    ui->setupUi(this);
}

menuBewerken::~menuBewerken()
{
    delete ui;
}
