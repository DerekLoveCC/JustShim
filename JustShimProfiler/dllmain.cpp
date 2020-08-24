// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "JustShimClrProfiler.h"
#include "JustShimProfilerFactory.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" HRESULT STDMETHODCALLTYPE DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID * ppv)
{

    if (ppv == nullptr || rclsid != IID_JustShimProfilerFactory)
    {
        return E_FAIL;
    }

    auto factory = new JustShimProfilerFactory();
    if (factory == nullptr)
    {
        return E_FAIL;
    }

    return factory->QueryInterface(riid, ppv);
}

extern "C" HRESULT STDMETHODCALLTYPE DllCanUnloadNow()
{
    return S_OK;
}