#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qttasktesting.h"

class QtTaskTesting : public QMainWindow
{
    Q_OBJECT

public:
    QtTaskTesting(QWidget *parent = Q_NULLPTR);

private slots:
    void lockunlock();
    void setSlideValue();
    void toggleLock();

private:
    Ui::QtTaskTestingClass ui;

};
