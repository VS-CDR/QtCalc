#include "calculator.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication q_application(argc, argv);
    Calculator calc_window;
    calc_window.setWindowTitle("Калькулятор");
    calc_window.show();
    return QApplication::exec();
}
