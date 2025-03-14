using System;

namespace JustShim
{
    public static class Is
    {
        public static T A<T>() => default(T);
    }
}