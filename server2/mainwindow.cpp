#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menubewerken.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Bestelsysteem");
    m_bestelServer = new bestelServer;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionMenu_bewerken_triggered()
{
    menuBewerken *menu = new menuBewerken;
    menu->show();
}

void MainWindow::on_actionAbout_triggered()
{
    about *over = new about;
    over->show();
}
