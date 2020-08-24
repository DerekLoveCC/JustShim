#include "pch.h"
#include "JustShimClrProfiler.h"

JustShimClrProfiler::JustShimClrProfiler() {
}

JustShimClrProfiler::~JustShimClrProfiler() {
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::QueryInterface(REFIID riid, void** ppvObject)
{
    return E_NOTIMPL;
}

ULONG STDMETHODCALLTYPE JustShimClrProfiler::AddRef(void)
{
    return 0;
}

ULONG STDMETHODCALLTYPE JustShimClrProfiler::Release(void)
{
    return 0;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::Initialize(IUnknown* pICorProfilerInfoUnk)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::Shutdown(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::AppDomainCreationStarted(AppDomainID appDomainId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::AppDomainCreationFinished(AppDomainID appDomainId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::AppDomainShutdownStarted(AppDomainID appDomainId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::AppDomainShutdownFinished(AppDomainID appDomainId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::AssemblyLoadStarted(AssemblyID assemblyId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::AssemblyLoadFinished(AssemblyID assemblyId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::AssemblyUnloadStarted(AssemblyID assemblyId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::AssemblyUnloadFinished(AssemblyID assemblyId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ModuleLoadStarted(ModuleID moduleId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ModuleLoadFinished(ModuleID moduleId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ModuleUnloadStarted(ModuleID moduleId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ModuleUnloadFinished(ModuleID moduleId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ModuleAttachedToAssembly(ModuleID moduleId, AssemblyID AssemblyId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ClassLoadStarted(ClassID classId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ClassLoadFinished(ClassID classId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ClassUnloadStarted(ClassID classId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ClassUnloadFinished(ClassID classId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::FunctionUnloadStarted(FunctionID functionId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::JITCompilationStarted(FunctionID functionId, BOOL fIsSafeToBlock)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::JITCompilationFinished(FunctionID functionId, HRESULT hrStatus, BOOL fIsSafeToBlock)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::JITCachedFunctionSearchStarted(FunctionID functionId, BOOL* pbUseCachedFunction)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::JITCachedFunctionSearchFinished(FunctionID functionId, COR_PRF_JIT_CACHE result)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::JITFunctionPitched(FunctionID functionId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::JITInlining(FunctionID callerId, FunctionID calleeId, BOOL* pfShouldInline)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ThreadCreated(ThreadID threadId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ThreadDestroyed(ThreadID threadId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ThreadAssignedToOSThread(ThreadID managedThreadId, DWORD osThreadId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RemotingClientInvocationStarted(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RemotingClientSendingMessage(GUID* pCookie, BOOL fIsAsync)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RemotingClientReceivingReply(GUID* pCookie, BOOL fIsAsync)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RemotingClientInvocationFinished(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RemotingServerReceivingMessage(GUID* pCookie, BOOL fIsAsync)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RemotingServerInvocationStarted(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RemotingServerInvocationReturned(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RemotingServerSendingReply(GUID* pCookie, BOOL fIsAsync)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::UnmanagedToManagedTransition(FunctionID functionId, COR_PRF_TRANSITION_REASON reason)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ManagedToUnmanagedTransition(FunctionID functionId, COR_PRF_TRANSITION_REASON reason)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RuntimeSuspendStarted(COR_PRF_SUSPEND_REASON suspendReason)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RuntimeSuspendFinished(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RuntimeSuspendAborted(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RuntimeResumeStarted(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RuntimeResumeFinished(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RuntimeThreadSuspended(ThreadID threadId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RuntimeThreadResumed(ThreadID threadId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::MovedReferences(ULONG cMovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ObjectAllocated(ObjectID objectId, ClassID classId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ObjectsAllocatedByClass(ULONG cClassCount, ClassID classIds[], ULONG cObjects[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ObjectReferences(ObjectID objectId, ClassID classId, ULONG cObjectRefs, ObjectID objectRefIds[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RootReferences(ULONG cRootRefs, ObjectID rootRefIds[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionThrown(ObjectID thrownObjectId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionSearchFunctionEnter(FunctionID functionId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionSearchFunctionLeave(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionSearchFilterEnter(FunctionID functionId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionSearchFilterLeave(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionSearchCatcherFound(FunctionID functionId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionOSHandlerEnter(UINT_PTR __unused)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionOSHandlerLeave(UINT_PTR __unused)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionUnwindFunctionEnter(FunctionID functionId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionUnwindFunctionLeave(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionUnwindFinallyEnter(FunctionID functionId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionUnwindFinallyLeave(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionCatcherEnter(FunctionID functionId, ObjectID objectId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionCatcherLeave(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::COMClassicVTableCreated(ClassID wrappedClassId, REFGUID implementedIID, void* pVTable, ULONG cSlots)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::COMClassicVTableDestroyed(ClassID wrappedClassId, REFGUID implementedIID, void* pVTable)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionCLRCatcherFound(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ExceptionCLRCatcherExecute(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ThreadNameChanged(ThreadID threadId, ULONG cchName, WCHAR name[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::GarbageCollectionStarted(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::SurvivingReferences(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::GarbageCollectionFinished(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::FinalizeableObjectQueued(DWORD finalizerFlags, ObjectID objectID)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::RootReferences2(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::HandleCreated(GCHandleID handleId, ObjectID initialObjectId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::HandleDestroyed(GCHandleID handleId)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::InitializeForAttach(IUnknown* pCorProfilerInfoUnk, void* pvClientData, UINT cbClientData)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ProfilerAttachComplete(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ProfilerDetachSucceeded(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ReJITCompilationStarted(FunctionID functionId, ReJITID rejitId, BOOL fIsSafeToBlock)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::GetReJITParameters(ModuleID moduleId, mdMethodDef methodId, ICorProfilerFunctionControl* pFunctionControl)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ReJITCompilationFinished(FunctionID functionId, ReJITID rejitId, HRESULT hrStatus, BOOL fIsSafeToBlock)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ReJITError(ModuleID moduleId, mdMethodDef methodId, FunctionID functionId, HRESULT hrStatus)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::MovedReferences2(ULONG cMovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], SIZE_T cObjectIDRangeLength[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::SurvivingReferences2(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], SIZE_T cObjectIDRangeLength[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::ConditionalWeakTableElementReferences(ULONG cRootRefs, ObjectID keyRefIds[], ObjectID valueRefIds[], GCHandleID rootIds[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JustShimClrProfiler::GetAssemblyReferences(const WCHAR* wszAssemblyPath, ICorProfilerAssemblyReferenceProvider* pAsmRefProvider)
{
    return E_NOTIMPL;
}