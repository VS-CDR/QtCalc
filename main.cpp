#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Calculator w;
    w.setWindowTitle("Калькулятор");
    w.show();
    return a.exec();
}
