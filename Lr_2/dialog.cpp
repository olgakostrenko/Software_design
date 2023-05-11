#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
class Cartesian_coordinates
{
private:
    int x;
    int y;
    int z;

public:
    Cartesian_coordinates(int x, int y, int z){

        this->x = x;
        this->y = y;
        this->z = z;

    }

    int getX(){
        return this->x;
    }

    int getY(){
        return this->y;
    }

    int getZ(){
        return this->z;
    }

    double Length(){


        return sqrt(x * x + y * y + z * z);

    }

};


void Dialog::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text(), text1=ui->lineEdit_2->text(), text2=ui->lineEdit_3->text(), value=ui->lineEdit_4->text();
    int a = text.toInt(), b = text1.toInt(), c = text2.toInt();

    Cartesian_coordinates carCor(a,b,c);
    ui->lineEdit_4->setText(QString::number(carCor.Length()));

}

