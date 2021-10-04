//
// Created by seawave on 2021/10/3.
//

#ifndef GCALC_SIMPLECALCULATORSTATUS_H
#define GCALC_SIMPLECALCULATORSTATUS_H

#include <QString>

class SimpleCalculatorStatus {
public:
    SimpleCalculatorStatus();

    bool isEmpty();

    void reciprocal();

public:
    void addNumber(unsigned int number);
    void addPoint();
    void changeSign();

    void backspace();
    void clearError();
    void clear();

    void add();
    void subtract();
    void multiply();
    void divide();
    void sqrt();
    void percent();

    void calculate();

    QString getCurrentText() const;
    bool isDecimal() const;

private:
    QString currentText;
    bool negative;
    bool decimal;
    bool clearing;

    char operation;
    double leftOperand;
};


#endif //GCALC_SIMPLECALCULATORSTATUS_H
