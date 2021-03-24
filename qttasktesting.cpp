#include "qttasktesting.h"

//Github merging test
//More github testing
//This will be the branch to merge into master.

QtTaskTesting::QtTaskTesting(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.btnLockUnlock, &QPushButton::clicked, this, &QtTaskTesting::lockunlock);
    connect(ui.btnLockUnlock, &QPushButton::clicked, this, &QtTaskTesting::setSlideValue);
    //connect(ui.btnSetValue, SIGNAL(clicked()), this, SLOT(setSlideValue()));

    connect(ui.verticalSlider_Hue, &QSlider::valueChanged, this, &QtTaskTesting::updateColourMap);
    connect(ui.spinBox_Value, QOverload<int>::of(&QSpinBox::valueChanged), this, &QtTaskTesting::updateColourMap);
}

void QtTaskTesting::updateColourMap(int hue) {

    /*int hue_Value = ui.verticalSlider_Hue->tickPosition();
    int lightness_Value = ui.verticalSlider_Lightness->tickPosition();
    int saturation_Value = ui.verticalSlider_Saturation->tickPosition();*/

    int width = 50;

    cv::Mat hls_map, BGRcolourmap;
    std::vector<cv::Mat> HLSchannels;

    cv::Mat H = cv::Mat(256, width, CV_8U);
    cv::Mat L = cv::Mat(256, width, CV_8U);
    cv::Mat S = cv::Mat(256, width, CV_8U);

    for (int c = 0; c < width; c++)
    {
        for (int i = 0; i < 256; i++)
        {
            H.at<uchar>(i, c) = hue;
            L.at<uchar>(i, c) = i;
            S.at<uchar>(i, c) = 255;
        }
    }

    HLSchannels.push_back(H);
    HLSchannels.push_back(L);
    HLSchannels.push_back(S);

    cv::merge(HLSchannels, hls_map);
    cv::cvtColor(hls_map, BGRcolourmap, cv::COLOR_HLS2BGR);

    QGraphicsScene* scene = new QGraphicsScene;
    graphic = scene->addPixmap(ASM::cvMatToQPixmap(BGRcolourmap));
    graphic->setY(5);
    ui.graphicsView->setScene(scene);
    ui.graphicsView->show();

    ui.spinBox_Value->setValue(hue);
    ui.verticalSlider_Hue->setValue(hue);
}

void QtTaskTesting::lockunlock() {
    if (ui.btnLockUnlock->isChecked())
    {
        //lock buttons
        ui.verticalSlider->setEnabled(false);
        //ui.numValueBox->setEnabled(false);
        //set button to "Unlock"
        ui.btnLockUnlock->setText("Unlock");

    }
    else {
        //unlock buttons
        ui.verticalSlider->setEnabled(true);
        //ui.numValueBox->setEnabled(true);
        //set button to "Lock"
        ui.btnLockUnlock->setText("Lock");
    }
}

void QtTaskTesting::setSlideValue() {
    //int value = ui.numValueBox->value();
    //ui.verticalSlider->setValue(value);
}