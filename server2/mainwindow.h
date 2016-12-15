#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bestelserver.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionMenu_bewerken_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    bestelServer *m_bestelServer;
};

#endif // MAINWINDOW_H
