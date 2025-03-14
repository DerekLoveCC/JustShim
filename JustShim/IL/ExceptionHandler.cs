using System;
using System.Reflection;

namespace JustShim.IL
{
    internal class ExceptionHandler
    {
        public Type CatchType;

        public ExceptionHandlingClauseOptions Flags;

        public int TryStart;

        public int TryEnd;

        public int FilterStart;

        public int HandlerStart;

        public int HandlerEnd;
    }
}