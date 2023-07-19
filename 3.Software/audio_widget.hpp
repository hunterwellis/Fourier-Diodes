// Hunter Ellis 2023
// audio_widget.hpp

#ifndef AUDIO_WIDGET_HPP
#define AUDIO_WIDGET_HPP

#include <QWidget>
#include <QLabel>
#include <QGraphicsView>
#include "audio.hpp"


class audioWidget: public QGraphicsView{
    Q_OBJECT

public:
    audioWidget(QWidget * parent = nullptr);

public slots:
    void startTimer();
    void stopTimer();

private slots:
    void timerStamp();

signals:
    void audioStream(double time, short amplitude);

private:
    QTimer *timer;
    StereoMixCapture capture;
    BYTE* pData;
    UINT32 numFramesAvailable;
    DWORD flags;
    double timeStamp;

};

#endif