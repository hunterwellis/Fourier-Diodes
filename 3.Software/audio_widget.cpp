// Hunter Ellis 2023
// audio_widget.cpp

#include "audio_widget.hpp"
#include <QTimer>
#include <QLayout>

audioWidget::audioWidget(QWidget * parent): QGraphicsView(parent){
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerStamp()));
}

void audioWidget::startTimer(){
    
    if (!capture.Initialize()) {
        std::cout << "Failed to initialize audio capture." << std::endl;
        return;
    }
    capture.StartCapture();
    timeStamp = 0;
    timer->start(10); // sample period of 0.01 seconds
}

void audioWidget::stopTimer(){
    capture.StopCapture();

    timer->stop();
}

void audioWidget::timerStamp(){
    // Capture and process audio data here
    HRESULT hr = capture.GetCaptureClient()->GetBuffer(&pData, &numFramesAvailable, &flags, NULL, NULL);
    if (FAILED(hr))
        return;

    // Process captured audio data
    short audioSample;
    for (UINT32 i = 0; i < numFramesAvailable; i++) {
        // Assume 16-bit signed integer audio format
        audioSample = *(reinterpret_cast<short*>(pData + (i * sizeof(short))));
        std::cout << timeStamp << ", "<< audioSample << "\n";
        
    }

    capture.GetCaptureClient()->ReleaseBuffer(numFramesAvailable);

    emit audioStream(timeStamp, audioSample);
    timeStamp += 0.01;
}

