#include "registrationwindow.h"
#include "ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(EchoClient *client, QWidget *parent) :
    client(client),
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    setFixedSize(this->size());
    ui->loginEdit->setFocus();
    ui->loginEdit->setTabOrder(ui->passwordEdit, ui->registrationButton);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::onRegistrationRequestAnswered(QString login, QString message)
{
    qDebug() << login;
    qDebug() << message;
}

void RegistrationWindow::on_registrationButton_clicked()
{
    ui->messageLabel->clear();
    QString login = ui->loginEdit->text();
    QString password = ui->passwordEdit->text();
    client->requestNewRegistration(login, password);
    connect(client, SIGNAL(registrationRequestAnswered(QString,QString)), this, SLOT(onRegistrationRequestAnswered(QString,QString)));
    QTimer::singleShot(10000, this, [this]() {
        disconnect(client, &EchoClient::registrationRequestAnswered, this, &RegistrationWindow::onRegistrationRequestAnswered);
        ui->messageLabel->setStyleSheet("color: red");
        ui->messageLabel->setText("Превышено время ожидания ответа от сервера, попробуйте ещё раз.");
    });
}
