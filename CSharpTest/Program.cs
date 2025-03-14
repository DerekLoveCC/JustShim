using JustShim;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpTest
{
    class Program
    {
        static void Main(string[] args)
        {
            TestShim();

            Console.WriteLine("this is main program");
            Console.Read();
        }

        private static void TestShim()
        {
            Shim dateTimeShim = Shim.Replace(() => DateTime.Now).With(() => new DateTime(2004, 4, 4));
            DateTime? s = null;
            // This block executes immediately
            PoseContext.Isolate(() =>
            {
                // Outputs "4/4/04 12:00:00 AM"
                s = DateTime.Now;

            }, dateTimeShim);

            Console.WriteLine(s);
        }
    }
}
