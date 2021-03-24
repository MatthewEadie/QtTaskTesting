#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsPixmapItem>
#include "asmOpenCV.h"

#include "ui_SecondWindow.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    SecondWindow(QWidget* parent = Q_NULLPTR);

private slots:

private:
    Ui::MainWindow ui2;
};

