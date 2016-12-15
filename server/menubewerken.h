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

private:
    Ui::menuBewerken *ui;
};

#endif // MENUBEWERKEN_H
