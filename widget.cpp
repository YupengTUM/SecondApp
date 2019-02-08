#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList title;

    setWindowTitle("Employers");
    title << "name" << "age" << "salary";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(title);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    Dialog pd(this);
    QString name;
    int res, age,rCount;
    double salary;

    pd.setWindowTitle("personal inforamtion");
    res = pd.exec();
    if(res == QDialog::Rejected){
        return;
    }
    name = pd.name();
    age = pd.age();
    salary = pd.salary();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    rCount = ui->tableWidget->rowCount()-1;
    ui->tableWidget->setItem(rCount, NAME , new QTableWidgetItem(name));
    ui->tableWidget->setItem(rCount,AGE,new QTableWidgetItem(QString::number(age)));
    ui->tableWidget->setItem(rCount,SALARY,new QTableWidgetItem(QString::number(salary)));


}
