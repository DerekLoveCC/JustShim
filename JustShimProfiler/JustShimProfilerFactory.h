#pragma once
#include "pch.h"

extern const IID IID_JustShimProfilerFactory;

class JustShimProfilerFactory : public IClassFactory
{
private:
    std::atomic<int> refCount;
public:
    JustShimProfilerFactory();
    virtual ~JustShimProfilerFactory();

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) override;
    ULONG   STDMETHODCALLTYPE AddRef(void) override;
    ULONG   STDMETHODCALLTYPE Release(void) override;
    HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) override;
    HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock) override;
};

