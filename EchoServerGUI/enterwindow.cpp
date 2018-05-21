#include "enterwindow.h"

EnterWindow::EnterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterWindow)
{
    ui->setupUi(this);
    setWindowTitle("Авторизация");
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
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
    close();
}
