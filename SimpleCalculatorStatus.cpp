//
// Created by seawave on 2021/10/3.
//
#include <cmath>

#include "SimpleCalculatorStatus.h"

SimpleCalculatorStatus::SimpleCalculatorStatus() : currentText("0"), negative(false), decimal(false), operation(0),
                                                   leftOperand(0.0), clearing(false) {}

void SimpleCalculatorStatus::addNumber(unsigned int number) {
    if (isEmpty() || clearing)
        currentText = QChar(number + '0');
    else
        currentText += QChar(number + '0');
    if (negative && currentText[0] != '-' && !isEmpty())
        currentText = '-' + currentText;
    clearing = false;
}

bool SimpleCalculatorStatus::isEmpty() {
    return currentText == "" || currentText == "0";
}

QString SimpleCalculatorStatus::getCurrentText() const {
    return currentText;
}

void SimpleCalculatorStatus::backspace() {
    if (clearing) {
        currentText = "0";
        clearing = false;
        return;
    }
    if (isEmpty() && negative)
        negative = false;
    if (currentText[currentText.length() - 1] == '.')
        decimal = false;
    currentText.remove(currentText.length() - 1, 1);
    if (isEmpty())
        currentText = "0";
}

void SimpleCalculatorStatus::clearError() {
    currentText = "0";
    negative = false;
    decimal = false;
    clearing = false;
}

void SimpleCalculatorStatus::clear() {
    clearError();
    operation = 0;
    leftOperand = 0.0;
}

void SimpleCalculatorStatus::addPoint() {
    if (isEmpty() || clearing)
        currentText = "0.";
    else
        currentText += ".";
    decimal = true;
    clearing = false;
}

void SimpleCalculatorStatus::changeSign() {
    negative = !negative;
    if (isEmpty())
        currentText = "0";
    else {
        if (negative && currentText[0] != '-')
            currentText = '-' + currentText;
        else if (!negative && currentText[0] == '-')
            currentText.remove(0, 1);
    }
}

bool SimpleCalculatorStatus::isDecimal() const {
    return decimal;
}

void SimpleCalculatorStatus::add() {
    if (operation)
        calculate();

    leftOperand = currentText.toDouble();
    operation = '+';
    clearing = true;
}

void SimpleCalculatorStatus::calculate() {
    double rightOperand = currentText.toDouble();

    switch (operation) {
        case '+':
            currentText.setNum(leftOperand + rightOperand);
            break;
        case '-':
            currentText.setNum(leftOperand - rightOperand);
            break;
        case '*':
            currentText.setNum(leftOperand * rightOperand);
            break;
        case '/':
            currentText.setNum(leftOperand / rightOperand);
            break;
    }

    leftOperand = 0.0;
    operation = 0;
    clearing = true;
}

void SimpleCalculatorStatus::subtract() {
    if (operation)
        calculate();

    leftOperand = currentText.toDouble();
    operation = '-';
    clearing = true;
}

void SimpleCalculatorStatus::multiply() {
    if (operation)
        calculate();

    leftOperand = currentText.toDouble();
    operation = '*';
    clearing = true;
}

void SimpleCalculatorStatus::divide() {
    if (operation)
        calculate();

    leftOperand = currentText.toDouble();
    operation = '/';
    clearing = true;
}

void SimpleCalculatorStatus::sqrt() {
    currentText.setNum(std::sqrt(currentText.toDouble()));
    clearing = true;
}

void SimpleCalculatorStatus::percent() {
    currentText.setNum(currentText.toDouble() / 100.0);
    clearing = true;
}

void SimpleCalculatorStatus::reciprocal() {
    currentText.setNum(1.0 / currentText.toDouble());
    clearing = true;
}
