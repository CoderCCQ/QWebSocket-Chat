#ifndef ENTERWINDOW_H
#define ENTERWINDOW_H

#include <QDialog>
#include "ui_enterwindow.h"

namespace Ui {
class EnterWindow;
}

class EnterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterWindow(QWidget *parent = 0);
    ~EnterWindow();
    QString getLogin();

    bool clickedOk;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EnterWindow *ui;
};

#endif // ENTERWINDOW_H
