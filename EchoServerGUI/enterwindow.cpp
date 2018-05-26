#include "enterwindow.h"

EnterWindow::EnterWindow(EchoClient *client, QWidget *parent) :
    client(client),
    QDialog(parent),
    ui(new Ui::EnterWindow)
{
    ui->setupUi(this);
    setWindowTitle("Авторизация");
    setWindowFlags(Qt::WindowCloseButtonHint);
    setFixedSize(this->size());
}

EnterWindow::~EnterWindow()
{
    delete ui;
}

QString EnterWindow::getLogin()
{
    return ui->label->text();
}

void EnterWindow::on_pushButton_clicked()
{
    clickedOk = true;
    close();
}

void EnterWindow::on_pushButton_2_clicked()
{
    clickedOk = false;

    RegistrationWindow registrationWindow;
    window

    close();
}
