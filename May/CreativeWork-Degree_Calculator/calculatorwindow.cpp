#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include <string>
#include <QPushButton>
#include <QDebug>
#include <QSizeGrip>
#include <QSound>
#include "GradNumber.h"
#include <QHBoxLayout>
#include <math.h>

#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0°");

    // numbers
    connect(ui->button0, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button1, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button2, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button3, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button4, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button5, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button6, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button7, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button8, SIGNAL(released()), this, SLOT(digitClicked()));
    connect(ui->button9, SIGNAL(released()), this, SLOT(digitClicked()));
    //
    connect(ui->buttonPlus, SIGNAL(released()), this, SLOT(operatorClicked()));
    connect(ui->buttonSub, SIGNAL(released()), this, SLOT(operatorClicked()));
    connect(ui->buttonMul, SIGNAL(released()), this, SLOT(operatorClicked()));
    connect(ui->buttonDiv, SIGNAL(released()), this, SLOT(operatorClicked()));
    //
    connect(ui->buttonDel, SIGNAL(released()), this, SLOT(backspaceClicked()));
    connect(ui->buttonSign, SIGNAL(released()), this, SLOT(changeSignClicked()));
    connect(ui->buttonGrad, SIGNAL(released()), this, SLOT(changeModeClicked()));
    connect(ui->buttonEq, SIGNAL(released()), this, SLOT(equalClicked()));

    connect(ui->buttonCE, SIGNAL(released()), this, SLOT(CE()));
    connect(ui->buttonC, SIGNAL(released()), this, SLOT(C()));
    connect(ui->buttonChangeMode, SIGNAL(released()), this, SLOT(toNumberClicked()));

    connect(ui->buttonHistory, SIGNAL(released()), this, SLOT(showHistoryClicked()));
    //
    connect(ui->buttonSin, SIGNAL(released()), this, SLOT(trigonometryClicked()));
    connect(ui->buttonCos, SIGNAL(released()), this, SLOT(trigonometryClicked()));
    connect(ui->buttonTan, SIGNAL(released()), this, SLOT(trigonometryClicked()));
    connect(ui->buttonCtg, SIGNAL(released()), this, SLOT(trigonometryClicked()));

    connect(ui->buttonArcSin, SIGNAL(released()), this, SLOT(trigonometryClicked()));
    connect(ui->buttonArcCos, SIGNAL(released()), this, SLOT(trigonometryClicked()));
    connect(ui->buttonArcTan, SIGNAL(released()), this, SLOT(trigonometryClicked()));
    connect(ui->buttonArcCtg, SIGNAL(released()), this, SLOT(trigonometryClicked()));

    this->isHistoryEmpty = true;
    QListWidgetItem* lwi = new QListWidgetItem("There is no history yet!");
    lwi->setTextAlignment(Qt::AlignCenter);
    lwi->setTextColor(QColor("white"));
    ui->listWidget->insertItem(0, lwi);
    ui->listWidget->setVisible(historyWindow);
}

void CalculatorWindow::addToHistory(QString result) {
    if (isHistoryEmpty) {
        ui->listWidget->clear();
        isHistoryEmpty = false;
    }
    QStringList items;

    QListWidgetItem* lwi = new QListWidgetItem(result);
    lwi->setTextAlignment(Qt::AlignRight);
    lwi->setTextColor(QColor("white"));
    ui->listWidget->insertItem(0, lwi);
}

void CalculatorWindow::showHistoryClicked() {
    historyWindow = !historyWindow;

    QGraphicsOpacityEffect* fade_effect = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(fade_effect);
    QPropertyAnimation *animation = new QPropertyAnimation(fade_effect, "opacity");
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->setDuration(200);
    animation->setStartValue(0.01);
    animation->setEndValue(1.0);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    ui->listWidget->setVisible(historyWindow);
}

void CalculatorWindow::switchAlwaysOnTop() {
    hide();
    ui->buttonHistory->setDisabled(!alwaysOnTop);
    ui->listWidget->setVisible(!alwaysOnTop ? false : historyWindow);
    if (alwaysOnTop) {
        this->setWindowFlags(this->windowFlags() & ~(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint));
        alwaysOnTop = false;
        this->resize(bW, bH);
    } else {
        this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
        alwaysOnTop = true;
        bW = this->width();
        bH = this->height();
        this->resize(365, 365);
    }
    show();
}

void CalculatorWindow::mousePressEvent(QMouseEvent *event){
    if (!alwaysOnTop) return;
    current = event->pos();
}

void CalculatorWindow::mouseMoveEvent(QMouseEvent *event){
    if (!alwaysOnTop) return;
    QWidget* w = window();
    QPoint delta = event->pos() - current;
    w->move(w->pos() + delta);
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

void CalculatorWindow::toNumberClicked() {
    CE();
    if (mode == MODE_NUMBER) {
        switchMode(MODE_GRAD);
    } else {
        switchMode(MODE_NUMBER);
    }
}

void CalculatorWindow::trigonometryClicked() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    QString text = clickedButton->text();
    GradNumber num(ui->lineEdit->text(), this->mode);
    double value = num.getInNumber();

    if (num.getMode() != MODE_NUMBER) {
        // convert degrees to radians
        value = num.getInNumber() * (3.14159265358979323846 / 180);
    } else {
        value = num.getInNumber();
    }
    ui->label->setText(text + "(" + ui->lineEdit->text() + ")");

    double result;
    if (text.startsWith("a")) {
        // обратные
        if (text.indexOf("sin") != -1) {
            result = asin(value);
        } else if (text.indexOf("cos") != -1) {
            result = acos(value);
        } else if (text.indexOf("tan") != -1) {
            result = atan(value);
        } else if (text.indexOf("ctg") != -1) {
            result = atan(1 / value);
        }
    } else {
        // обычные
        if (text.indexOf("sin") != -1) {
            result = sin(value);
        } else if (text.indexOf("cos") != -1) {
            result = cos(value);
        } else if (text.indexOf("tan") != -1) {
            result = tan(value);
        } else if (text.indexOf("ctg") != -1) {
            result = 1 / tan(value);
        }
    }
    this->isAfterEq = true;
    switchMode(MODE_NUMBER);
    addToHistory(ui->label->text() + "\n" + QString::number(result));
    ui->lineEdit->setText(QString::number(result));
}

void CalculatorWindow::C() {
    if (mode == MODE_NUMBER) {
        ui->lineEdit->setText("0");
        switchMode(MODE_NUMBER);
    } else {
        ui->lineEdit->setText("0°");
        switchMode(MODE_GRAD);
    }
}

void CalculatorWindow::CE() {
    if (leftOperand != nullptr) {
        delete leftOperand;
        leftOperand = nullptr;
    }
    ui->buttonChangeMode->setDisabled(false);
    ui->label->setText("");
    C();
}

void CalculatorWindow::digitClicked() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    int digitValue = clickedButton->text().toInt();
    QString lineText = ui->lineEdit->text();
    if (this->wait || this->isAfterEq) {
        if (isAfterEq) {
            CE();
        }
        this->wait = false;
        this->isAfterEq = false;
        lineText = "0";
        switchMode(this->mode == MODE_NUMBER ? MODE_NUMBER : MODE_GRAD);
    }
    GradNumber num(lineText, this->mode);
    num.append(QString::number(digitValue));
    ui->lineEdit->setText(num.to_str());
}

void CalculatorWindow::backspaceClicked() {
    QString text = ui->lineEdit->text();
    GradNumber num(text, this->mode);
    if (num.get() == "") {
        if (mode == MODE_MINUTES) {
            mode = MODE_GRAD;
            ui->buttonGrad->setText("'");
        }
        if (mode == MODE_SECONDS) {
            mode = MODE_MINUTES;
            ui->buttonGrad->setDisabled(false);
        }
        num.setMode(mode);
    } else {
        num.removeLast();
    }
    ui->lineEdit->setText(num.to_str());
}

void CalculatorWindow::changeSignClicked() {
    QString text = ui->lineEdit->text();
    GradNumber num(text, this->mode);
    num.setNegative(!num.isNegagive());
    ui->lineEdit->setText(num.to_str());
}

void CalculatorWindow::changeModeClicked() {
    if (mode == MODE_GRAD) {
        mode = MODE_MINUTES;
        ui->lineEdit->setText(ui->lineEdit->text() + " 0'");
        ui->buttonGrad->setText("''");
    } else if (mode == MODE_MINUTES) {
        mode = MODE_SECONDS;
        ui->lineEdit->setText(ui->lineEdit->text() + " 0''");
        ui->buttonGrad->setDisabled(true);
    } else if (mode == MODE_NUMBER) {
        ui->lineEdit->setText(ui->lineEdit->text() + ".");
        ui->buttonGrad->setDisabled(true);
    }
    ui->buttonGrad->setShortcut(Qt::Key_Apostrophe);
    ui->buttonGrad->setShortcut(Qt::Key_Comma);
}

void CalculatorWindow::operatorClicked() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    QString text = clickedButton->text();
    GradNumber* op = new GradNumber(ui->lineEdit->text(), this->mode);
    this->wait = true;
    this->isAfterEq = false;
    this->leftOperand = op;
    ui->label->setText(op->to_str() + " " + text);
    this->operation_ = text;
    if (text == "+")
        this->operation = "+";
    if (text == "-")
        this->operation = "-";
    if (text == "×") {
        this->operation = "*";
        switchMode(MODE_NUMBER);
        ui->buttonChangeMode->setDisabled(true);
    }

    if (text == "÷")
        this->operation = "/";
}

void CalculatorWindow::equalClicked() {
    try {
        if (this->leftOperand != nullptr) {
            if (!isAfterEq || rightOperand == nullptr) {
                rightOperand = new GradNumber(ui->lineEdit->text(), this->mode);
            } else {
                delete leftOperand;
                leftOperand = new GradNumber(ui->lineEdit->text(), this->mode);
            }

            GradNumber result;
            if (this->operation == "+") {
                result = *this->leftOperand + *rightOperand;
            } else if (this->operation == "-") {
                result = *this->leftOperand - *rightOperand;
            } else if (this->operation == "*") {
                result = *this->leftOperand * *rightOperand;
            } else if (this->operation == "/") {
                result = *this->leftOperand / *rightOperand;
            }
            this->isAfterEq = true;
            switchMode(result.getMode());
            ui->buttonChangeMode->setDisabled(false);
            ui->label->setText(this->leftOperand->to_str() + " " + this->operation_ + " " + rightOperand->to_str() + " =");
            if (result.error == false)
                addToHistory(leftOperand->to_str() + " " + operation_ + " " + rightOperand->to_str() + " =\n" + result.to_str());
            ui->lineEdit->setText(result.to_str());
        }
    } catch (QString err) {
        qDebug() << err;
    }
}

void CalculatorWindow::switchMode(CALC_MODE newMode) {
    if (newMode == MODE_NUMBER) {
        ui->buttonChangeMode->setText("RAD");
        ui->lineEdit->setText("0");
        ui->buttonGrad->setText(".");
        ui->buttonGrad->setDisabled(false);
    }
    if (newMode == MODE_GRAD) {
        ui->buttonChangeMode->setText("DEG");
        if (mode == MODE_NUMBER) {
            ui->lineEdit->setText("0°");
        }
        ui->buttonGrad->setText("'");
    }
    if (newMode == MODE_MINUTES) {
        ui->lineEdit->setText(ui->lineEdit->text() + " 0''");
        ui->buttonGrad->setText("'");
    }
    mode = newMode;
    ui->buttonGrad->setShortcutEnabled(true);
    ui->buttonGrad->setShortcut(Qt::Key_Apostrophe);
    ui->buttonGrad->setShortcut(Qt::Key_Comma);
}
