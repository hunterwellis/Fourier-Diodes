// Hunter Ellis
// fourier_colors.hpp

#ifndef FOURIER_COLORS_HPP
#define FOURIER_COLORS_HPP

#include <QWidget>
#include <QListWidget>

class fourierColors: public QWidget{
  Q_OBJECT

public:
  fourierColors(QWidget * parent = nullptr);

private:


public slots:
    void selectedPattern(QListWidgetItem *item);
    void audioInput();

signals:
    void mappedColor(QRgb color);

};

#endif
