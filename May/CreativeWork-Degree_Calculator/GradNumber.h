#ifndef GRADNUMBER_H
#define GRADNUMBER_H
#include "calculatorwindow.h"

class GradNumber {
    QString number = "";

    QString grad = "0";
    QString min = "";
    QString sec = "";
    bool negative = false;
    CALC_MODE mode = MODE_GRAD;
public:
    bool error = false;
    GradNumber() {};
    GradNumber(QString text, CALC_MODE m = MODE_GRAD) {
        mode = m;
        if (text[0] == "-") {
            negative = true;
        }
        if (m == MODE_NUMBER) {
            number = text.replace("-", "");
        } else {
            const QRegExp rx(QLatin1Literal("[^0-9]+"));
            const auto&& parts = text.split(rx, QString::SkipEmptyParts);
            grad = parts[0];
            if (parts.length() > 1) {
                min = parts[1];
            }
            if (parts.length() > 2) {
                sec = parts[2];
            }
            number = getInNumber();
        }
    }

    CALC_MODE getMode() {
        return mode;
    }
    void setMode(CALC_MODE m) {
        mode = m;
    }

    bool isNegagive() {
        return negative;
    }
    void setNegative(bool neg) {
        negative = neg;
    }

    QString to_str() {
        if (mode == MODE_NUMBER) return (negative ? "-" : "") + (number == "" ? "0" : number);
        QString result = (negative && grad != "0" & grad != "" ? "-" : "") + (grad == "" ? "0" : grad) + "°";
        if (mode >= MODE_MINUTES) {
            result += " " + min + "'";
        }
        if (mode == MODE_SECONDS) {
            result += " " + sec + "''";
        }
        return result;
    }

    QString get() {
        return get(mode);
    }
    QString get(CALC_MODE mode) {
        if (mode == MODE_NUMBER) return number;
        if (mode == MODE_GRAD) return grad;
        if (mode == MODE_MINUTES) return min;
        return sec;
    }

    void set(QString value) {
        set(value, mode);
    }
    void set(QString value, CALC_MODE m) {
        if (value.length() > 1 && value.startsWith("0")) value = value.remove(0, 1);
        if (m == MODE_NUMBER) number = value;
        if (m == MODE_GRAD) grad = value;
        if (m == MODE_MINUTES) min = value;
        if (m == MODE_SECONDS) sec = value;
    }

    void append(QString value) {
        append(value, mode);
    }
    void append(QString value, CALC_MODE m) {
        if (m == MODE_NUMBER) set(number + value, m);
        if (m == MODE_GRAD) set(grad + value, m);
        if (m == MODE_MINUTES) set(min + value, m);
        if (m == MODE_SECONDS) set(sec + value, m);
    }

    void removeLast() {
        return removeLast(mode);
    }
    void removeLast(CALC_MODE m) {
        if (m == MODE_NUMBER) number = number.left(number.length() -1 );
        if (m == MODE_GRAD) grad = grad.left(grad.length() - 1);
        if (m == MODE_MINUTES) min = min.left(min.length() - 1);
        if (m == MODE_SECONDS) sec = sec.left(sec.length() - 1);
    }

    double getInNumber() {
        if (mode != MODE_NUMBER) {
            return (grad.toDouble() + min.toDouble() / 60 + sec.toDouble() / 3600) * (negative ? -1 : 1);
        }
        return number.toDouble() * (negative ? -1 : 1);
    }

    double getInSeconds() {
        if (mode == MODE_NUMBER) throw QString("This is a number lol");
        double seconds = sec.toLongLong();
        return (seconds + min.toLongLong() * 60 + grad.toLongLong() * 60 * 60) * (negative ? -1 : 1);
    }

    void setFromSeconds(long long seconds) {
        if (seconds < 0) {
            this->negative = true;
            seconds *= -1;
        }
        int grads = 0;
        int mins = 0;
        while (seconds >= 3600) {
            seconds -= 3600;
            grads++;
        }
        while (seconds >= 60) {
            seconds -= 60;
            mins++;
        }
        this->grad = QString::number(grads);
        this->min = QString::number(mins);
        this->sec = QString::number(seconds);
        if (this->min != "0") {
            this->mode = MODE_MINUTES;
        }
        if (this->sec != "0") {
            this->mode = MODE_SECONDS;
        }
    }

    GradNumber operator +(GradNumber& other) {
        GradNumber copy;
        double left;
        double right;
        bool isNumber = mode == MODE_NUMBER && other.mode == MODE_NUMBER;
        if (mode == MODE_NUMBER) {
            left = getInNumber();
        } else {
            left = getInSeconds();
        }
        if (other.mode == MODE_NUMBER) {
            right = other.getInNumber();
        } else {
            right = other.getInSeconds();
        }
        if (isNumber) {
            copy.number = QString::number(abs(left + right));
            copy.setNegative(left + right < 0);
            copy.mode = MODE_NUMBER;
        } else {
            copy.setFromSeconds(left + right);
        }

        return copy;
    }
    GradNumber operator -(GradNumber& other) {
        GradNumber copy;
        double left;
        double right;
        bool isNumber = mode == MODE_NUMBER && other.mode == MODE_NUMBER;
        if (mode == MODE_NUMBER) {
            left = getInNumber();
        } else {
            left = getInSeconds();
        }
        if (other.mode == MODE_NUMBER) {
            right = other.getInNumber();
        } else {
            right = other.getInSeconds();
        }
        if (isNumber) {
            copy.number = QString::number(abs(left - right));
            copy.setNegative(left - right < 0);
            copy.mode = MODE_NUMBER;
        } else {
            copy.setFromSeconds(left - right);
        }
        return copy;
    }
    GradNumber operator *(GradNumber& other) {
        GradNumber copy;
        double left;
        double right = other.getInNumber();
        if (mode == MODE_NUMBER) {
            left = getInNumber();
        } else {
            left = getInSeconds();
        }
        if (mode == MODE_NUMBER) {
            copy.number = QString::number(abs(left * right));
            copy.setNegative(left * right < 0);
            copy.mode = MODE_NUMBER;
        } else {
            copy.setFromSeconds(left * right);
        }

        return copy;
    }
    GradNumber operator /(GradNumber& other) {
        GradNumber copy;
        double left;
        double right;
        if (mode == MODE_NUMBER) {
            left = getInNumber();
        } else {
            left = getInSeconds();
        }
        if (other.mode == MODE_NUMBER) {
            right = other.getInNumber();
        } else {
            right = other.getInSeconds();
        }
        if (right == 0.0) {
            copy.mode = MODE_NUMBER;
            copy.number = "Ошибка: деление на ноль";
            copy.error = true;
        } else {
            copy.number = QString::number(abs(left / right));
            copy.setNegative(left / right < 0);
            copy.mode = MODE_NUMBER;
        }
        return copy;
    }
};

#endif // GRADNUMBER_H
