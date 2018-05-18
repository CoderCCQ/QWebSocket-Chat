#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    client = new EchoClient(QUrl("ws://localhost:129"), true);
    QString clientName = QInputDialog::getText(nullptr, "Авторизация", "Введите имя");
    client = new EchoClient(QUrl("ws://185.22.152.2:129"), true, clientName);
    connect(client, &EchoClient::newTextMessage, this, [this](QString message){
        ui->textEdit->insertPlainText(message + "\n");
    });

    ui->lineEdit->setTabOrder(ui->lineEdit, ui->pushButton);
    ui->textEdit->setFocusPolicy(Qt::ClickFocus); // no tab focus
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &on_pushButton_clicked); // on Enter key press while typing in lineEdit call clicked slot
    connect(client, &EchoClient::gotCurrentUsers, this, [this](QList<QString> users) {
        ui->listWidget->clear();
        foreach (auto k, users)
            ui->listWidget->addItem(k);
    });
    connect(client, &EchoClient::gotHistory, this, [this](QList<QString> history) {
        QFont font;
        font.setBold(true);
        ui->textEdit->setCurrentFont(font);
        ui->textEdit->insertPlainText("История переписки:\n");
        font.setBold(false);
        ui->textEdit->setCurrentFont(font);
        foreach(auto k, history)
            ui->textEdit->insertPlainText(k + "\n");
    });
}

MainWindow::~MainWindow()
{
    client->deleteLater();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->text().at(0) == '/')
    {
        if (ui->lineEdit->text() == "/clr" || ui->lineEdit->text() == "/cls" || ui->lineEdit->text() == "/clear")
            ui->textEdit->clear();
        else if (ui->lineEdit->text() == "/log" || ui->lineEdit->text() == "/history")
            client->requestChatHistory();
    }
    else
        client->sendTextMessage(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    client->requestCurrentUsers();
}
