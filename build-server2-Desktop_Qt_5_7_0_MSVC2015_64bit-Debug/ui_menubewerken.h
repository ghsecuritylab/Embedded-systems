/********************************************************************************
** Form generated from reading UI file 'menubewerken.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUBEWERKEN_H
#define UI_MENUBEWERKEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menuBewerken
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *hoofdMenuList;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *hoofdMenuInput;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *onderMenuList;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *onderMenuInput;
    QPushButton *pushButton_3;

    void setupUi(QWidget *menuBewerken)
    {
        if (menuBewerken->objectName().isEmpty())
            menuBewerken->setObjectName(QStringLiteral("menuBewerken"));
        menuBewerken->resize(1015, 490);
        horizontalLayout = new QHBoxLayout(menuBewerken);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(menuBewerken);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        hoofdMenuList = new QListWidget(groupBox);
        hoofdMenuList->setObjectName(QStringLiteral("hoofdMenuList"));

        verticalLayout->addWidget(hoofdMenuList);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        hoofdMenuInput = new QLineEdit(groupBox);
        hoofdMenuInput->setObjectName(QStringLiteral("hoofdMenuInput"));

        horizontalLayout_4->addWidget(hoofdMenuInput);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(menuBewerken);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        onderMenuList = new QListWidget(groupBox_2);
        onderMenuList->setObjectName(QStringLiteral("onderMenuList"));

        verticalLayout_2->addWidget(onderMenuList);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_2->addWidget(pushButton_5);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        onderMenuInput = new QLineEdit(groupBox_2);
        onderMenuInput->setObjectName(QStringLiteral("onderMenuInput"));

        horizontalLayout_2->addWidget(onderMenuInput);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton_5->raise();
        onderMenuList->raise();
        label_2->raise();

        horizontalLayout->addWidget(groupBox_2);


        retranslateUi(menuBewerken);

        QMetaObject::connectSlotsByName(menuBewerken);
    } // setupUi

    void retranslateUi(QWidget *menuBewerken)
    {
        menuBewerken->setWindowTitle(QApplication::translate("menuBewerken", "Form", 0));
        groupBox->setTitle(QApplication::translate("menuBewerken", "Hoofd menu", 0));
#ifndef QT_NO_TOOLTIP
        hoofdMenuList->setToolTip(QApplication::translate("menuBewerken", "<html><head/><body><p>id, naam</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("menuBewerken", "Verwijderen", 0));
        label->setText(QApplication::translate("menuBewerken", "id, naam", 0));
#ifndef QT_NO_TOOLTIP
        hoofdMenuInput->setToolTip(QApplication::translate("menuBewerken", "<html><head/><body><p>id, naam</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("menuBewerken", "Toevoegen", 0));
        groupBox_2->setTitle(QApplication::translate("menuBewerken", "Onder menu", 0));
        pushButton_5->setText(QApplication::translate("menuBewerken", "Verwijderen", 0));
        label_2->setText(QApplication::translate("menuBewerken", "id, hoofdmenuId, naam, prijs", 0));
        pushButton_3->setText(QApplication::translate("menuBewerken", "Toevoegen", 0));
    } // retranslateUi

};

namespace Ui {
    class menuBewerken: public Ui_menuBewerken {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUBEWERKEN_H
