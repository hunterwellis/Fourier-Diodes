// Hunter Ellis
// audio.cpp

#include "audio.hpp"

StereoMixCapture::StereoMixCapture() : pEnumerator(nullptr), pDevice(nullptr), pAudioClient(nullptr),
                                       pCaptureClient(nullptr), pWaveFormat(nullptr), pDeviceId(nullptr), capturing(false) {}

StereoMixCapture::~StereoMixCapture() {
    StopCapture();

    if (pDeviceId != nullptr)
        CoTaskMemFree(pDeviceId);

    if (pWaveFormat != nullptr)
        CoTaskMemFree(pWaveFormat);

    if (pCaptureClient != nullptr)
        pCaptureClient->Release();

    if (pAudioClient != nullptr)
        pAudioClient->Release();

    if (pDevice != nullptr)
        pDevice->Release();

    if (pEnumerator != nullptr)
        pEnumerator->Release();

    CoUninitialize();
}

bool StereoMixCapture::Initialize() {
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hr))
        return false;

    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL,
                          __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
    if (FAILED(hr))
        return false;

    hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
    if (FAILED(hr))
        return false;

    hr = pDevice->GetId(&pDeviceId);
    if (FAILED(hr))
        return false;

    hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
    if (FAILED(hr))
        return false;

    hr = pAudioClient->GetMixFormat(&pWaveFormat);
    if (FAILED(hr))
        return false;

    hr = pAudioClient->Initialize(AUDCLNT_SHAREMODE_SHARED, AUDCLNT_STREAMFLAGS_LOOPBACK,
                                  0, 0, pWaveFormat, NULL);
    if (FAILED(hr))
        return false;

    hr = pAudioClient->GetService(__uuidof(IAudioCaptureClient), (void**)&pCaptureClient);
    if (FAILED(hr))
        return false;

    return true;
}

void StereoMixCapture::StartCapture() {
    capturing = true;

    pAudioClient->Start();

    // // Continuously capture audio data
    // while (capturing) {
    //     BYTE* pData;
    //     UINT32 numFramesAvailable;
    //     DWORD flags;

    //     HRESULT hr = pCaptureClient->GetBuffer(&pData, &numFramesAvailable, &flags, NULL, NULL);
    //     if (FAILED(hr))
    //         continue;

    //     // Process captured audio data (pData)
         
    //     pCaptureClient->ReleaseBuffer(numFramesAvailable);
    // }
}

void StereoMixCapture::StopCapture() {
    capturing = false;
    pAudioClient->Stop();
}

IAudioCaptureClient* StereoMixCapture::GetCaptureClient() {
    return pCaptureClient;
}
