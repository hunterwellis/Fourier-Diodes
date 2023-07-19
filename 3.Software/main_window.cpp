// Hunter Ellis 2023
// main_window.cpp

#include <QLayout>
#include <QtWidgets>

#include "main_window.hpp"

MainWindow::MainWindow(QWidget * parent): QWidget(parent){

    // widget initialization
    cp = new colorPalette;
    pl = new patternList;

    // grid layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(cp, 0, 0);
    layout->addWidget(pl, 1, 0);

    // widget connection
    QObject::connect(pl, &patternList::patternSelection, cp, &colorPalette::fourierModeStart);

    setStyleSheet("background-color:  #151515;");
    setLayout(layout);
    setWindowTitle("Fourier Diodes");
}
