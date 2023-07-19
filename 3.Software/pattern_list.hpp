// Hunter Ellis 2023
// pattern_list.hpp

#ifndef PATTERN_LIST_HPP
#define PATTERN_LIST_HPP

#include <QWidget>
#include <QLabel>
#include <QListWidget>

class patternList: public QWidget{
    Q_OBJECT

public:
    patternList(QWidget * parent = nullptr);

signals:
    void patternSelection(QListWidgetItem *item);

private slots:
    void selection();
private:
    QListWidget *list;

};

#endif