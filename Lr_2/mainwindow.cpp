#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
    ui->radioButton_5->setChecked(true);
    if(ui->radioButton->isChecked())   ui->label_2->setStyleSheet("image: url(:/img/img/Dance.png);");
    if(ui->radioButton_5->isChecked()) ui->label_3->setStyleSheet("background-image: url(:/img/img/pexels-madison-inouye-1831234.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_clicked(bool checked)
{
    if(checked){
        ui->label_2->setStyleSheet("image: url(:/img/img/Dance.png);");
    }
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(checked){
        ui->label_2->setStyleSheet("image: url(:/img/img/Shop.png);");
    }
}


void MainWindow::on_radioButton_3_clicked(bool checked)
{
    if(checked){
        ui->label_2->setStyleSheet("image: url(:/img/img/Ice-skate.png);");
    }
}


void MainWindow::on_radioButton_4_clicked(bool checked)
{
    if(checked){
        ui->label_2->setStyleSheet("image: url(:/img/img/Call.png);");
    }
}


void MainWindow::on_radioButton_5_clicked(bool checked)
{
    if(checked){
        ui->label_3->setStyleSheet("background-image: url(:/img/img/pexels-madison-inouye-1831234.jpg);");
    }
}


void MainWindow::on_radioButton_6_clicked(bool checked)
{
    if(checked){
        ui->label_3->setStyleSheet(" ");
    }
}




void MainWindow::on_radioButton_4_clicked()
{
    Dialog window;
    window.setModal(true);
    window.exec();

}
