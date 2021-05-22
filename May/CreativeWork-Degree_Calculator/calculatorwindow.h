#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QDebug>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorWindow; }
QT_END_NAMESPACE

enum CALC_MODE {
    MODE_NUMBER,
    MODE_GRAD,
    MODE_MINUTES,
    MODE_SECONDS
};

class GradNumber;

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

    void switchAlwaysOnTop();
    bool alwaysOnTop = false;
    bool historyWindow = false;
private slots:
    void digitClicked();
    void backspaceClicked();
    void changeSignClicked();
    void changeModeClicked();
    void operatorClicked();
    void equalClicked();
    void toNumberClicked();

    void trigonometryClicked();

    void C();
    void CE();
    void showHistoryClicked();

    void switchMode(CALC_MODE m);


    // drag window on always on top
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

protected:
    virtual void paintEvent(QPaintEvent*) {};

private:
    void addToHistory(QString result);
    GradNumber* leftOperand = nullptr;
    GradNumber* rightOperand = nullptr;
    QString operation = "";
    QString operation_ = "";
    CALC_MODE mode = MODE_GRAD;
    bool wait = false;
    bool isAfterEq = false;
    bool isHistoryEmpty = true;
    Ui::CalculatorWindow *ui;

    QPoint current;
    int bW = 0; // width before entering always on top mode
    int bH = 0; // height before entring always on top mode
};
#endif // CALCULATORWINDOW_H
