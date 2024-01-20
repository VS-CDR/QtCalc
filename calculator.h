#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow {
 Q_OBJECT

 public:
  Calculator(QWidget* parent = nullptr);
  ~Calculator();

 private:
  Ui::Calculator* ui_;
  double lhs{};
  double rhs{};
 private slots:
  void digits_numbers();
  void on_floating_point_clicked();
  void on_erase_clicked();
  void on_sqrt_clicked();
  void on_percent_clicked();
  void on_get_res_clicked();
  void math_operations();
};
#endif // CALCULATOR_H
