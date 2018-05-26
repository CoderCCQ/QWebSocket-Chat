#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "echoclient.h"

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(EchoClient *client = 0, QWidget *parent = 0);
    ~RegistrationWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegistrationWindow *ui;
    EchoClient *client;
};

#endif // REGISTRATIONWINDOW_H
