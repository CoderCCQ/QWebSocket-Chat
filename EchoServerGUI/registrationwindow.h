#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "echoclient.h"
#include <QTimer>

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
    void onRegistrationRequestAnswered(QString login, QString message);

    void on_registrationButton_clicked();

private:
    EchoClient *client;
    Ui::RegistrationWindow *ui;
};

#endif // REGISTRATIONWINDOW_H
