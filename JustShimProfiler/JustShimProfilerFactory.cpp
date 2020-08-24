#include "pch.h"
#include "JustShimProfilerFactory.h"
#include "JustShimClrProfiler.h"

JustShimProfilerFactory::JustShimProfilerFactory() : refCount(0)
{
}
JustShimProfilerFactory::~JustShimProfilerFactory()
{
}

const IID IID_IJustShimProfilerFactory = { 0xe0ef3012, 0x876a, 0x4d06, { 0x98, 0xce, 0xb7, 0x3a, 0xd, 0x1, 0xbe, 0xe3 } };

HRESULT STDMETHODCALLTYPE JustShimProfilerFactory::QueryInterface(REFIID riid, void** ppvObject)
{
    if (riid == IID_IUnknown || riid == IID_IJustShimProfilerFactory)
    {
        *ppvObject = this;
        this->AddRef();
        return S_OK;
    }

    *ppvObject = nullptr;
    return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE JustShimProfilerFactory::AddRef()
{
    return std::atomic_fetch_add(&this->refCount, 1) + 1;
}

ULONG STDMETHODCALLTYPE JustShimProfilerFactory::Release()
{
    int count = std::atomic_fetch_sub(&this->refCount, 1) - 1;
    if (count <= 0)
    {
        delete this;
    }

    return count;
}

HRESULT STDMETHODCALLTYPE JustShimProfilerFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject)
{
    if (pUnkOuter != nullptr)
    {
        *ppvObject = nullptr;
        return CLASS_E_NOAGGREGATION;
    }

    JustShimClrProfiler* profiler = new JustShimClrProfiler();
    if (profiler == nullptr)
    {
        return E_FAIL;
    }

    return profiler->QueryInterface(riid, ppvObject);
}

HRESULT STDMETHODCALLTYPE JustShimProfilerFactory::LockServer(BOOL fLock)
{
    return S_OK;
}