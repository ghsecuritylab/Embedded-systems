#ifndef MENUBEWERKEN_H
#define MENUBEWERKEN_H

#include <QWidget>

namespace Ui {
class menuBewerken;
}

class menuBewerken : public QWidget
{
    Q_OBJECT

public:
    explicit menuBewerken(QWidget *parent = 0);
    ~menuBewerken();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::menuBewerken *ui;
    void updateMenu(void);
};

#endif // MENUBEWERKEN_H
