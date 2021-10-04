//
// Created by seawave on 2021/10/3.
//

#ifndef GCALC_MAINWINDOW_H
#define GCALC_MAINWINDOW_H

#include <QMainWindow>

#include "SimpleCalculatorStatus.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    SimpleCalculatorStatus status;

    void bindEvent();
    void render();
};


#endif //GCALC_MAINWINDOW_H
