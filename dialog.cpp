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

void Dialog::on_buttonBox_accepted()
{
   accept();
}

void Dialog::on_buttonBox_rejected()
{
   reject();
}

QString Dialog::name() const{
    return ui->name->text();
}

int Dialog::age() const{

    return ui->age->value();
}

double Dialog::salary() const{

    return ui->salary->value();
}
