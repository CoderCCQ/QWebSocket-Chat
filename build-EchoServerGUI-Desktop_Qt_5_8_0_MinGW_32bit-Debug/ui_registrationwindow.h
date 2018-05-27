/********************************************************************************
** Form generated from reading UI file 'registrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

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

class Ui_RegistrationWindow
{
public:
    QPushButton *registrationButton;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *passwordEdit;
    QLineEdit *loginEdit;
    QLabel *messageLabel;

    void setupUi(QDialog *RegistrationWindow)
    {
        if (RegistrationWindow->objectName().isEmpty())
            RegistrationWindow->setObjectName(QStringLiteral("RegistrationWindow"));
        RegistrationWindow->resize(270, 216);
        registrationButton = new QPushButton(RegistrationWindow);
        registrationButton->setObjectName(QStringLiteral("registrationButton"));
        registrationButton->setGeometry(QRect(40, 140, 191, 23));
        label_2 = new QLabel(RegistrationWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 47, 13));
        label = new QLabel(RegistrationWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 47, 13));
        passwordEdit = new QLineEdit(RegistrationWindow);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setGeometry(QRect(40, 100, 191, 20));
        passwordEdit->setEchoMode(QLineEdit::Password);
        loginEdit = new QLineEdit(RegistrationWindow);
        loginEdit->setObjectName(QStringLiteral("loginEdit"));
        loginEdit->setGeometry(QRect(40, 40, 191, 20));
        messageLabel = new QLabel(RegistrationWindow);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setGeometry(QRect(10, 170, 251, 41));
        messageLabel->setScaledContents(true);
        messageLabel->setWordWrap(true);

        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QDialog *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QApplication::translate("RegistrationWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", Q_NULLPTR));
        registrationButton->setText(QApplication::translate("RegistrationWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegistrationWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("RegistrationWindow", "\320\233\320\276\320\263\320\270\320\275", Q_NULLPTR));
        messageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegistrationWindow: public Ui_RegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H
