#include <QPushButton>
#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::Calculator) {
  ui_->setupUi(this);
  connect(ui_->Null, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->one, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->two, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->three, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->four, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->five, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->six, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->seven, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->eight, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->nine, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->add, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui_->sub, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui_->div, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui_->mul, SIGNAL(clicked()), this, SLOT(math_operations()));
  ui_->add->setCheckable(true);
  ui_->sub->setCheckable(true);
  ui_->div->setCheckable(true);
  ui_->mul->setCheckable(true);
}

Calculator::~Calculator() {
  delete ui_;
}

void Calculator::digits_numbers() {
  auto const* button = dynamic_cast<QPushButton*>(sender());
  double all_numbers;
  QString new_label;
  if (ui_->Expression->text().contains('.') && button->text() == "0") {
    new_label = ui_->Expression->text() + button->text();
  } else {
    all_numbers = (ui_->Expression->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 14);
  }
  ui_->Expression->setText(new_label);
}

void Calculator::on_floating_point_clicked() {
  if (!ui_->Expression->text().contains('.')) {
    ui_->Expression->setText(ui_->Expression->text() + ".");
  }
}

void Calculator::on_erase_clicked() {
  ui_->add->setChecked(false);
  ui_->sub->setChecked(false);
  ui_->div->setChecked(false);
  ui_->mul->setChecked(false);
  lhs = 0;
  rhs = 0;
  ui_->Expression->setText("0");
}

void Calculator::on_sqrt_clicked() {
  ui_->Expression->setText(
      QString::number(sqrt(ui_->Expression->text().toDouble()), 'g', 14)
  );
}

void Calculator::on_percent_clicked() {
  if (fabs(lhs) < 1e-9) {
    ui_->Expression->setText(QString::number(
        ui_->Expression->text().toDouble() * 0.01, 'g', 14));
  } else {
    ui_->Expression->setText(QString::number(
        ui_->Expression->text().toDouble() * 0.01 * lhs, 'g', 14));
  }
}

void Calculator::on_get_res_clicked() {
  double lable_num;
  QString new_label;
  rhs = ui_->Expression->text().toDouble();
  if (ui_->add->isChecked()) {
    lable_num = lhs + rhs;
    new_label = QString::number(lable_num, 'g', 14);
    ui_->Expression->setText(new_label);
    ui_->add->setChecked(false);
  } else if (ui_->sub->isChecked()) {
    lable_num = lhs - rhs;
    new_label = QString::number(lable_num, 'g', 14);
    ui_->Expression->setText(new_label);
    ui_->sub->setChecked(false);
  } else if (ui_->div->isChecked()) {
    if (fabs(rhs) < 1e-9) {
      ui_->Expression->setText("0");
    } else {
      lable_num = lhs / rhs;
      new_label = QString::number(lable_num, 'g', 14);
      ui_->Expression->setText(new_label);
    }
    ui_->div->setChecked(false);
  } else {
    lable_num = lhs * rhs;
    new_label = QString::number(lable_num, 'g', 14);
    ui_->Expression->setText(new_label);
    ui_->mul->setChecked(false);
  }
  lhs = 0;
  rhs = 0;
}

void Calculator::math_operations() {
  auto* button = dynamic_cast<QPushButton*>(sender());
  lhs = ui_->Expression->text().toDouble();
  ui_->Expression->setText("");
  button->setChecked(true);
}

