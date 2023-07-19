// Hunter Ellis 2023
// audio.hpp

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <Windows.h>
#include <mmdeviceapi.h>
#include <Audioclient.h>
#include <endpointvolume.h>
#include <iostream>

class StereoMixCapture {
public:
    StereoMixCapture();
    ~StereoMixCapture();

    bool Initialize();
    void StartCapture();
    void StopCapture();
    
    IAudioCaptureClient* GetCaptureClient(); // New function declaration

private:
    IMMDeviceEnumerator* pEnumerator;
    IMMDevice* pDevice;
    IAudioClient* pAudioClient;
    IAudioCaptureClient* pCaptureClient;
    WAVEFORMATEX* pWaveFormat;
    LPWSTR pDeviceId;
    bool capturing;
};


#endif