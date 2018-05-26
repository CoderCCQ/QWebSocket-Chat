/********************************************************************************
** Form generated from reading UI file 'enterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERWINDOW_H
#define UI_ENTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnterWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *EnterWindow)
    {
        if (EnterWindow->objectName().isEmpty())
            EnterWindow->setObjectName(QStringLiteral("EnterWindow"));
        EnterWindow->resize(270, 216);
        pushButton = new QPushButton(EnterWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 140, 191, 23));
        pushButton_2 = new QPushButton(EnterWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 170, 191, 23));
        lineEdit = new QLineEdit(EnterWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 40, 191, 20));
        lineEdit_2 = new QLineEdit(EnterWindow);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 100, 191, 20));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label = new QLabel(EnterWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 47, 13));
        label_2 = new QLabel(EnterWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 47, 13));

        retranslateUi(EnterWindow);

        QMetaObject::connectSlotsByName(EnterWindow);
    } // setupUi

    void retranslateUi(QDialog *EnterWindow)
    {
        EnterWindow->setWindowTitle(QApplication::translate("EnterWindow", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("EnterWindow", "\320\222\320\276\320\271\321\202\320\270", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("EnterWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", Q_NULLPTR));
        label->setText(QApplication::translate("EnterWindow", "\320\230\320\274\321\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("EnterWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EnterWindow: public Ui_EnterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERWINDOW_H
