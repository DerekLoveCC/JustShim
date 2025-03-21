using System;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection;
using System.Reflection.Emit;

using JustShim.Extensions;

namespace JustShim.Helpers
{
    internal static class StubHelper
    {
        public static IntPtr GetMethodPointer(MethodBase methodBase)
        {
            if (methodBase is DynamicMethod)
            {
                var methodDescriptior = typeof(DynamicMethod).GetMethod("GetMethodDescriptor", BindingFlags.Instance | BindingFlags.NonPublic);
                return ((RuntimeMethodHandle)methodDescriptior.Invoke(methodBase as DynamicMethod, null)).GetFunctionPointer();
            }

            return methodBase.MethodHandle.GetFunctionPointer();
        }

        public static object GetShimDelegateTarget(int index)
            => PoseContext.Shims[index].Replacement.Target;

        public static MethodInfo GetShimReplacementMethod(int index)
            => PoseContext.Shims[index].Replacement.Method;

        public static int GetIndexOfMatchingShim(MethodBase methodBase, Type type, object obj)
        {
            if (methodBase.IsStatic || obj == null)
                return Array.FindIndex(PoseContext.Shims, s => s.Original == methodBase);

            int index = Array.FindIndex(PoseContext.Shims,
                s => Object.ReferenceEquals(obj, s.Instance) && s.Original == methodBase);

            if (index == -1)
                return Array.FindIndex(PoseContext.Shims,
                            s => SignatureEquals(s, type, methodBase) && s.Instance == null);

            return index;
        }

        public static int GetIndexOfMatchingShim(MethodBase methodBase, object obj)
            => GetIndexOfMatchingShim(methodBase, methodBase.DeclaringType, obj);

        public static MethodInfo GetRuntimeMethodForVirtual(Type type, MethodInfo methodInfo)
        {
            BindingFlags bindingFlags = BindingFlags.Instance | (methodInfo.IsPublic ? BindingFlags.Public : BindingFlags.NonPublic);
            Type[] types = methodInfo.GetParameters().Select(p => p.ParameterType).ToArray();
            return type.GetMethod(methodInfo.Name, bindingFlags, null, types, null);
        }

        public static Module GetOwningModule() => typeof(StubHelper).Module;

        private static bool SignatureEquals(Shim shim, Type type, MethodBase method)
        {
            if (shim.Type == null || type == shim.Type)
                return $"{shim.Type}::{shim.Original.ToString()}" == $"{type}::{method.ToString()}";

            if (type.IsSubclassOf(shim.Type))
            {
                if ((shim.Original.IsAbstract || !shim.Original.IsVirtual)
                        || (shim.Original.IsVirtual && !method.IsOverride()))
                {
                    return $"{shim.Original.ToString()}" == $"{method.ToString()}";
                }
            }

            return false;
        }
    }
}