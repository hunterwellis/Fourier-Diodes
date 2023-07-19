// Hunter Ellis 2023
// canvas_widget.hpp

#ifndef CANVAS_WIDGET_HPP
#define CANVAS_WIDGET_HPP

#include <QWidget>
#include <QLabel>
#include <QGraphicsView>


class Canvas: public QGraphicsView{
    Q_OBJECT

public:
    Canvas(QWidget * parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

signals:
    void clicked(const QPointF& pos);
    void unclicked(const QPointF& pos);
    void movement(const QPointF& pos);
};

#endif