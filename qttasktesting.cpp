#include "qttasktesting.h"
#include "SecondWindow.h"

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

    connect(ui.pushButton_SecondWindow, &QPushButton::clicked, this, &QtTaskTesting::openSecondWindow);

    connect(ui.pushButton_Plot, &QPushButton::clicked, this, &QtTaskTesting::drawPlot);
}

void QtTaskTesting::drawPlot() {
    QLine line;
    QPen pen(Qt::green, 3);
    //QColor penColour = QColorDialog::getColor();


    /*pen.setColor(penColour);
    pen.setWidth(1);*/

    //QPoint p1, p2;
    //p1.setX(1.0);
    //p1.setY(2.0);
    //p2.setX(2.0);
    //p2.setY(5.0);

    line.setP1(QPoint(1, 1));
    line.setP2(QPoint(50, 50));
    //linePlot->setLine(QLine(line));
    //linePlot->setLine(1.0, 2.0, 2.0, 5.0);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addLine(line,pen);
    ui.graphicsView_Plot->setScene(scene);
    ui.graphicsView_Plot->show();
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

    cv::Mat opencvColourmap;

    cv::merge(HLSchannels, hls_map);
    cv::cvtColor(hls_map, BGRcolourmap, cv::COLOR_HLS2BGR);
    cv::applyColorMap(BGRcolourmap, opencvColourmap, cv::COLORMAP_RAINBOW);
    

    QGraphicsScene* scene = new QGraphicsScene;
    graphic = scene->addPixmap(ASM::cvMatToQPixmap(opencvColourmap));
    graphic->setY(5);
    ui.graphicsView->setScene(scene);
    ui.graphicsView->show();

    ui.spinBox_Value->setValue(hue);
    ui.verticalSlider_Hue->setValue(hue);
}

void QtTaskTesting::openSecondWindow() {
    ui2.setupUi(this);

    //ui.setupUi(this);
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