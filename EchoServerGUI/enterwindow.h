#ifndef ENTERWINDOW_H
#define ENTERWINDOW_H

#include <QDialog>
#include "ui_enterwindow.h"
#include "echoclient.h"
#include "registrationwindow.h"

namespace Ui {
class EnterWindow;
}

class EnterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterWindow(EchoClient *client = 0, QWidget *parent = 0);
    ~EnterWindow();
    QString getLogin();

    bool clickedOk = false;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    EchoClient *client;
    Ui::EnterWindow *ui;
};

#endif // ENTERWINDOW_H
