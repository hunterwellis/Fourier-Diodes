// Hunter Ellis 2023
// color_palette.cpp

#include "color_palette.hpp"

#include <iostream>
#include <QLayout>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

colorPalette::colorPalette(QWidget * parent): QWidget(parent){
    
    hexHash = new QLabel();

    scene = new QGraphicsScene(this);
    view = new Canvas;
    view->setScene(scene);

    clearPalette();
    drawPalette();
    // setting up indicator
    indicator = new QGraphicsEllipseItem(0, 0, 15, 15);
    QColor gray("#dddddd");
    QBrush brush(gray);
    indicator->setBrush(brush);
    indicator->setPos(200, 200);
    scene->addItem(indicator);

    hexHash->setAlignment(Qt::AlignCenter);

    view->setDragMode(QGraphicsView::NoDrag);
    view->setInteractive(false);
    view->setFrameShape(QFrame::NoFrame);
    view->resize(400, 400);
    view->setFixedSize(view->size());

    QPen pen(Qt::black);

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(hexHash, 1, 0);
    layout->addWidget(view, 0, 0);
    
    QObject::connect(view, &Canvas::clicked, this, &colorPalette::breakFourier);
    QObject::connect(view, &Canvas::movement, this, &colorPalette::updateCanvas);

    setStyleSheet("background-color:  #151515;");
    view->setStyleSheet("QGraphicsView { background-color : #2a2a2a ; border-radius : 10px;}");
    hexHash->setStyleSheet("QLabel { background-color : #151515; color : #dddddd; font-weight : bold;}");
    setLayout(layout);
}

void colorPalette::breakFourier(const QPointF& pos){
    if (!paletteMode){
        clearPalette();
        drawPalette();
        // std::cout << "broken" << std::endl;
        indicator = new QGraphicsEllipseItem(0, 0, 15, 15);
        QColor gray("#dddddd");
        QBrush brush(gray);
        indicator->setBrush(brush);
        indicator->setPos(200, 200);
        scene->addItem(indicator);
    }
    updateCanvas(pos);
}

void colorPalette::updateCanvas(const QPointF& pos){
    //TODO: update Canvas marker with new hex Value
    //TODO: update hex value

    // boundary conditions and position update
    qreal x = pos.x();
    qreal y = pos.y();
    // if ((x < 15 || y < 15) || (x > 385 || y > 385)){
    //     return;
    // }
    double distance = std::sqrt(std::pow(x-202, 2) + std::pow(y-202, 2));
    if (distance > 145){
        return;
    }
    else {
        indicator->setPos(x-5, y-5);
        //std::cout << "x: " << x << " | y: " << y << std::endl;
    }
    mapPalette(pos);

}

void colorPalette::clearPalette(){
    scene->clear();
    // std::cout << "passed" << std::endl;
    // set the refernce boudaries for the new graphics
    QGraphicsEllipseItem *arc = new QGraphicsEllipseItem(0, 0, 4, 4);
    QColor gray("#2a2a2a");
    QBrush brush(gray);
    arc->setBrush(brush);
    arc->setPos(5, 5);
    arc->setPen(Qt::NoPen);
    scene->addItem(arc);
    QGraphicsEllipseItem *arc2 = new QGraphicsEllipseItem(0, 0, 4, 4);
    arc2->setPos(395, 395);
    arc2->setPen(Qt::NoPen);
    scene->addItem(arc2);
    hexHash->setText("#------");

}

void colorPalette::drawPalette(){
    QPixmap pixmap("C:/Users/ellis/OneDrive/Desktop/Projects/Fourier-Diodes/3.Software/images/colorwheel.png"); // Need to update to store in executable
    QPixmap scaledPixmap = pixmap.scaled(300, 300);
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(scaledPixmap);  
    palette = pixmapItem->pixmap().toImage();
    pixmapItem->setPos(55, 55);
    scene->addItem(pixmapItem);
    paletteMode = true;
}

void colorPalette::mapPalette(const QPointF& pos){

    QRgb pixelColor = palette.pixel(pos.x()-55, pos.y()-55);
    int red = qRed(pixelColor);
    int green = qGreen(pixelColor);
    int blue = qBlue(pixelColor);

    //std::cout << red << "|" << green << "|" << blue << std::endl;
    hexHash->setText(QString::fromStdString(rgbToHex(red, green, blue)).toUpper());
}

void colorPalette::fourierMode(){
    clearPalette();
}

void colorPalette::fourierModeStart(QListWidgetItem *item){
    clearPalette();
    paletteMode = false;
}

// Function to convert decimal to hexadecimal
std::string colorPalette::decToHex(int decimal) {
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(2) << std::hex << decimal;
    return stream.str();
}

// Function to convert RGB to RGB hex
std::string colorPalette::rgbToHex(int red, int green, int blue) {
    // Convert each RGB component to hexadecimal
    std::string hexRed = decToHex(red);
    std::string hexGreen = decToHex(green);
    std::string hexBlue = decToHex(blue);

    // Concatenate the three hexadecimal values
    std::string hexValue = "#" + hexRed + hexGreen + hexBlue;

    return hexValue;
}