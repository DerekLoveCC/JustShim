#include "pch.h"
#include "JustShimProfilerFactory.h"
#include "JustShimClrProfiler.h"

JustShimProfilerFactory::JustShimProfilerFactory() : refCount(0)
{
}
JustShimProfilerFactory::~JustShimProfilerFactory()
{
}

const IID IID_JustShimProfilerFactory = { 0x3f2b361, 0xa89d, 0x463a, { 0xaa, 0x65, 0xdb, 0x71, 0x1d, 0x44, 0x48, 0xa0 } };//{03F2B361-A89D-463A-AA65-DB711D4448A0}

HRESULT STDMETHODCALLTYPE JustShimProfilerFactory::QueryInterface(REFIID riid, void** ppvObject)
{
    if (riid == IID_IUnknown || riid == IID_IClassFactory)
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