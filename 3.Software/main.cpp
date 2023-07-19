// Hunter Ellis 2023
// main.cpp

#include <QApplication>
#include <QDebug>

#define MILL 1000000

#include "main_window.hpp"

int main(int argc, char * argv[]){
    QApplication app(argc, argv);

    MainWindow w;
    w.resize(450, 675);
    w.setFixedSize(w.size());
    w.show();

    return app.exec();
}


// #include <iostream>
// #include <limits>
// #include "audio.hpp"
// #include <chrono>

// int main() {
//     StereoMixCapture capture;

//     if (!capture.Initialize()) {
//         std::cout << "Failed to initialize audio capture." << std::endl;
//         return 1;
//     }

//     capture.StartCapture();

//     std::cout << "Streaming audio..." << std::endl;

//     auto start = std::chrono::high_resolution_clock::now();
//     long long former = 0;

//     // Continuously stream audio data to the terminal
//     while (true) {
//         // Capture and process audio data here
//         BYTE* pData;
//         UINT32 numFramesAvailable;
//         DWORD flags;

//         HRESULT hr = capture.GetCaptureClient()->GetBuffer(&pData, &numFramesAvailable, &flags, NULL, NULL);
//         if (FAILED(hr))
//             continue;

//         // Process captured audio data
//         for (UINT32 i = 0; i < numFramesAvailable; i++) {
//             // Assume 16-bit signed integer audio format
//             short audioSample = *(reinterpret_cast<short*>(pData + (i * sizeof(short))));
            
//             // Convert the duration to seconds as a floating-point value
//             auto stop = std::chrono::high_resolution_clock::now();
//             auto micro = std::chrono::duration_cast<std::chrono::microseconds>(stop -start).count();
//             if (micro > (former + 1000)){
//                 std::cout << micro << ", "<< audioSample << "\n";
//                 former = micro;
//             }
//         }

//         capture.GetCaptureClient()->ReleaseBuffer(numFramesAvailable);
//     }

//     // Stop the audio capture (unreachable in this example)
//     capture.StopCapture();

//     return 0;
// }