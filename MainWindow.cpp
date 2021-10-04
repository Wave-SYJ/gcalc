//
// Created by seawave on 2021/10/3.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    bindEvent();
    render();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::bindEvent() {
    connect(ui->zeroButton, &QPushButton::clicked, [this] {
        status.addNumber(0);
        render();
    });
    connect(ui->oneButton, &QPushButton::clicked, [this] {
        status.addNumber(1);
        render();
    });
    connect(ui->twoButton, &QPushButton::clicked, [this] {
        status.addNumber(2);
        render();
    });
    connect(ui->threeButton, &QPushButton::clicked, [this] {
        status.addNumber(3);
        render();
    });
    connect(ui->fourButton, &QPushButton::clicked, [this] {
        status.addNumber(4);
        render();
    });
    connect(ui->fiveButton, &QPushButton::clicked, [this] {
        status.addNumber(5);
        render();
    });
    connect(ui->sixButton, &QPushButton::clicked, [this] {
        status.addNumber(6);
        render();
    });
    connect(ui->sevenButton, &QPushButton::clicked, [this] {
        status.addNumber(7);
        render();
    });
    connect(ui->eightButton, &QPushButton::clicked, [this] {
        status.addNumber(8);
        render();
    });
    connect(ui->nineButton, &QPushButton::clicked, [this] {
        status.addNumber(9);
        render();
    });
    connect(ui->pointButton, &QPushButton::clicked, [this] {
        status.addPoint();
        render();
    });

    connect(ui->backspaceButton, &QPushButton::clicked, [this] {
        status.backspace();
        render();
    });
    connect(ui->clearErrorButton, &QPushButton::clicked, [this] {
        status.clearError();
        render();
    });
    connect(ui->clearButton, &QPushButton::clicked, [this] {
        status.clear();
        render();
    });
    connect(ui->signButton, &QPushButton::clicked, [this] {
        status.changeSign();
        render();
    });
    connect(ui->addButton, &QPushButton::clicked, [this] {
        status.add();
        render();
    });
    connect(ui->subButton, &QPushButton::clicked, [this] {
        status.subtract();
        render();
    });
    connect(ui->multiplyButton, &QPushButton::clicked, [this] {
        status.multiply();
        render();
    });
    connect(ui->devideButton, &QPushButton::clicked, [this] {
        status.divide();
        render();
    });
    connect(ui->equalButton, &QPushButton::clicked, [this] {
        status.calculate();
        render();
    });
    connect(ui->sqrtButton, &QPushButton::clicked, [this] {
        status.sqrt();
        render();
    });
    connect(ui->percentButton, &QPushButton::clicked, [this] {
        status.percent();
        render();
    });
    connect(ui->reciprocalButton, &QPushButton::clicked, [this] {
        status.reciprocal();
        render();
    });
}

void MainWindow::render() {
    ui->textEdit->setText(status.getCurrentText());
    ui->pointButton->setEnabled(!status.isDecimal());
}

