// Hunter Ellis 2023
// pattern_list.cpp

#include "pattern_list.hpp"

#include <iostream>
#include <QLayout>
#include <QtWidgets>
#include <QObject>
#include <QMenu>

patternList::patternList(QWidget * parent): QWidget(parent){
    
    list = new QListWidget(this);
    QGridLayout *layout = new QGridLayout;


    new QListWidgetItem(tr("Frequency Modulated"), list);
    new QListWidgetItem(tr("Flowing"), list);
    new QListWidgetItem(tr("Visual Waveform"), list);
    new QListWidgetItem(tr("Pulsing"), list);
    new QListWidgetItem(tr("Slow"), list);
    new QListWidgetItem(tr("Pink and White"), list);
    new QListWidgetItem(tr("Grand"), list);
    new QListWidgetItem(tr("Slow Dancing"), list);
    new QListWidgetItem(tr("White"), list);
    new QListWidgetItem(tr("Ocean Blue"), list);
    new QListWidgetItem(tr("Waves"), list);
    new QListWidgetItem(tr("Sun"), list);
    new QListWidgetItem(tr("Circular"), list);
    new QListWidgetItem(tr("Alarm"), list);

    layout->addWidget(list, 0, 0);

    QObject::connect(list, &QListWidget::itemSelectionChanged, this, &patternList::selection);

    setStyleSheet("background-color: #151515;");
    list->setStyleSheet("QListWidget {background-color : #2a2a2a; border-radius : 10px; color : #dddddd; font-weight : bold;}");
    setLayout(layout);
}

// selection slot
void patternList::selection(){
        QList<QListWidgetItem *> selectedItems = list->selectedItems();
        if (!selectedItems.isEmpty())
        {
            QListWidgetItem *selectedItem = selectedItems.first();
            std::cout << selectedItem->text().toStdString() << std::endl;
            emit patternSelection(selectedItem);
        }
}