// Hunter Ellis 2023
// canvas_widget.cpp

#include "canvas_widget.hpp"

#include <iostream>
#include <QMouseEvent>
#include <QWidget>
#include <QGraphicsView>

Canvas::Canvas(QWidget * parent): QGraphicsView(parent){
}

void Canvas::mousePressEvent(QMouseEvent* event){

    if (event->button() == Qt::LeftButton){
        emit clicked(event->pos());
    }

    // need to ensure process is executed as it would without override
    QGraphicsView::mousePressEvent(event);
}

void Canvas::mouseReleaseEvent(QMouseEvent* event){
  if (event->button() == Qt::LeftButton){
    emit unclicked(event->pos());
  }  

  QGraphicsView::mouseReleaseEvent(event);
}

void Canvas::mouseMoveEvent(QMouseEvent* event){
    emit movement(event->pos());
    QGraphicsView::mouseMoveEvent(event);
}