namespace JustShim.Tests
{
    [TestClass]
    public sealed class Test1
    {
        [TestMethod]
        public void TestShimStaticMethod()
        {
            Shim consoleShim = Shim.Replace(() => Console.WriteLine(Is.A<string>())).With((string s) => Console.WriteLine("Hijacked: {0}", s));
            // This block executes immediately
            PoseContext.Isolate(() =>
            {
                // Outputs "Hijacked: Hello World!"
                Console.WriteLine("Hello World!");
            }, consoleShim);
        }

        [TestMethod]
        public void TestShimStaticProperty()
        {
            Shim dateTimeShim = Shim.Replace(() => DateTime.Now).With(() => new DateTime(2004, 4, 4));
            DateTime? s = null;
            // This block executes immediately
            PoseContext.Isolate(() =>
            {
                // Outputs "4/4/04 12:00:00 AM"
                s = DateTime.Now;

            }, dateTimeShim);

            Assert.AreEqual(s, new DateTime(2004, 4, 4));
        }

        [TestMethod]
        public void TestMethod1()
        {
            Shim consoleShim = Shim.Replace(() => Console.WriteLine(Is.A<string>())).With((string s) => Console.WriteLine("Hijacked: {0}", s));

            Shim dateTimeShim = Shim.Replace(() => DateTime.Now).With(() => new DateTime(2004, 4, 4));
            Shim setterShim = Shim.Replace(() => Console.Title, true).With((string title) => Console.Title = "My Title");
            Shim classPropShim = Shim.Replace(() => Is.A<MyClass>().MyProperty).With((MyClass @this) => 100);

            Shim classPropShim1 = Shim.Replace(() => Is.A<MyClass>().MyProperty, true).With((MyClass @this, int prop) => { @this.MyProperty = prop * 10; });
            Shim ctorShim = Shim.Replace(() => new MyClass()).With(() => new MyClass() { MyProperty = 10 });
            Shim classShim = Shim.Replace(() => Is.A<MyClass>().DoSomething()).With((MyClass @this) => Console.WriteLine("doing someting else"));

            MyClass myClass = new MyClass();
            Shim myClassShim = Shim.Replace(() => myClass.DoSomething()).With((MyClass @this) => Console.WriteLine("doing someting else with myClass"));

            Shim structShim = Shim.Replace(() => Is.A<MyStruct>().DoSomething()).With((ref MyStruct @this) => Console.WriteLine("doing someting else"));


            // This block executes immediately
            PoseContext.Isolate(() =>
            {
                // All code that executes within this block
                // is isolated and shimmed methods are replaced

                // Outputs "Hijacked: Hello World!"
                Console.WriteLine("Hello World!");

                // Outputs "4/4/04 12:00:00 AM"
                Console.WriteLine(DateTime.Now);

                // Outputs "doing someting else"
                new MyClass().DoSomething();

                // Outputs "doing someting else with myClass"
                myClass.DoSomething();

            }, consoleShim, dateTimeShim, classPropShim, classShim, myClassShim, structShim);
        }
    }

    class MyClass
    {
        public int MyProperty { get; set; }
        public void DoSomething() => Console.WriteLine("doing someting");
    }

    struct MyStruct
    {
        public void DoSomething() => Console.WriteLine("doing someting");

    }
}
