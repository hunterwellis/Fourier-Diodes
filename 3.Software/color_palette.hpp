// Hunter Ellis 2023
// color_palette.hpp

#ifndef COLOR_PALETTE_HPP
#define COLOR_PALETTE_HPP

#include "canvas_widget.hpp"
#include <QWidget>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QListWidgetItem>
#include <QImage>
#include <sstream>
#include <iomanip>

class colorPalette: public QWidget{
    Q_OBJECT

public:
    colorPalette(QWidget * parent = nullptr);

signals:
    void updateSolidColor(QString entry);

private slots:
    void updateCanvas(const QPointF& pos);
    void breakFourier(const QPointF& pos);
    void fourierMode();

public slots:
    void fourierModeStart(QListWidgetItem *item);

protected:
    void clearPalette();
    void drawPalette();

private:
    void mapPalette(const QPointF& pos);
    std::string decToHex(int decimal);
    std::string rgbToHex(int red, int green, int blue);
    QGraphicsScene *scene;
    Canvas *view;
    QGraphicsEllipseItem *indicator;
    QImage palette;
    QLabel *hexHash;
    bool paletteMode;
    
};

#endif
