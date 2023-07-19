// Hunter Ellis 2023
// main_window.hpp

#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <string>

#include <QWidget>

#include "color_palette.hpp"
#include "pattern_list.hpp"

class MainWindow: public QWidget{
  Q_OBJECT

public:
  MainWindow(QWidget * parent = nullptr);

private:
    colorPalette *cp;
    patternList *pl;
};

#endif
