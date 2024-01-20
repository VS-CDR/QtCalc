#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->Null,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->one,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->two,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->three,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->four,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->five,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->six,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->seven,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->eight,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->nine,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->add,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->sub,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->div,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->mul,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->add->setCheckable(true);
    ui->sub->setCheckable(true);
    ui->div->setCheckable(true);
    ui->mul->setCheckable(true);
}

Calculator::~Calculator(){
    delete ui;
}

void Calculator::digits_numbers(){
    QPushButton *button = static_cast<QPushButton*>(sender());
    double all_numbers;
    QString new_label;
    if(ui->Expression->text().contains('.') && button->text() == "0"){
        new_label=ui->Expression->text()+button->text();
    }else{
        all_numbers=(ui->Expression->text()+button->text()).toDouble();
        new_label=QString::number(all_numbers,'g',14);
    }
    ui->Expression->setText(new_label);
}

void Calculator::on_floating_point_clicked(){
    if(!ui->Expression->text().contains('.')) ui->Expression->setText(ui->Expression->text() + ".");
}


void Calculator::on_erase_clicked(){
    ui->add->setChecked(false);
    ui->sub->setChecked(false);
    ui->div->setChecked(false);
    ui->mul->setChecked(false);
    arg1=0;
    arg2=0;
    ui->Expression->setText("0");
}


void Calculator::on_sqrt_clicked(){
    ui->Expression->setText(QString::number(sqrt(ui->Expression->text().toDouble()),'g',14));
}


void Calculator::on_percent_clicked(){
    if(fabs(arg1)<1e-9){
        ui->Expression->setText(QString::number(ui->Expression->text().toDouble()*0.01,'g',14));
    }else{
        ui->Expression->setText(QString::number(ui->Expression->text().toDouble()*0.01*arg1,'g',14));
    }
}


void Calculator::on_get_res_clicked(){
    double LableNum;
    QString new_label;
    arg2=ui->Expression->text().toDouble();
    if(ui->add->isChecked()){
        LableNum=arg1+arg2;
        new_label=QString::number(LableNum,'g',14);
        ui->Expression->setText(new_label);
        ui->add->setChecked(false);
    }else if(ui->sub->isChecked()){
        LableNum=arg1-arg2;
        new_label=QString::number(LableNum,'g',14);
        ui->Expression->setText(new_label);
        ui->sub->setChecked(false);
    }
    else if(ui->div->isChecked()){
        if(fabs(arg2)<1e-9){ui->Expression->setText("0");}
        else{
            LableNum=arg1/arg2;
            new_label=QString::number(LableNum,'g',14);
            ui->Expression->setText(new_label);
        }
        ui->div->setChecked(false);
    }else{
        LableNum=arg1*arg2;
        new_label=QString::number(LableNum,'g',14);
        ui->Expression->setText(new_label);
        ui->mul->setChecked(false);
    }
    arg1=0;
    arg2=0;
}

void Calculator::math_operations(){
    QPushButton *button = static_cast<QPushButton*>(sender());
    arg1=ui->Expression->text().toDouble();
    ui->Expression->setText("");
    button->setChecked(true);
}

