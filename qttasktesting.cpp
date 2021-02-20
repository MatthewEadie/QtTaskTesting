#include "qttasktesting.h"

//Github merging

QtTaskTesting::QtTaskTesting(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.btnLockUnlock, &QPushButton::clicked, this, &QtTaskTesting::lockunlock);
    connect(ui.btnLockUnlock, SIGNAL(clicked()), this, SLOT(setSlideValue()));
    //connect(ui.btnSetValue, SIGNAL(clicked()), this, SLOT(setSlideValue()));

    connect(ui.btnLock2, &QPushButton::clicked, this, &QtTaskTesting::toggleLock);
    connect(ui.btnLock3, &QPushButton::clicked, this, &QtTaskTesting::toggleLock);

}

void QtTaskTesting::toggleLock() {

}


void QtTaskTesting::lockunlock() {
    if (ui.btnLockUnlock->isChecked())
    {
        //lock buttons
        ui.verticalSlider->setEnabled(false);
        ui.numValueBox->setEnabled(false);
        //set button to "Unlock"
        ui.btnLockUnlock->setText("Unlock");
    }
    else {
        //unlock buttons
        ui.verticalSlider->setEnabled(true);
        ui.numValueBox->setEnabled(true);
        //set button to "Lock"
        ui.btnLockUnlock->setText("Lock");
    }
}

void QtTaskTesting::setSlideValue() {
    int value = ui.numValueBox->value();
    ui.verticalSlider->setValue(value);
}