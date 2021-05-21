#include "calculatorwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	system("chcp 1251>nul");
    QApplication a(argc, argv);
    CalculatorWindow w;
    w.show();
    return a.exec();
}
