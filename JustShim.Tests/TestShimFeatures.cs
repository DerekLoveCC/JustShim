namespace JustShim.Tests
{
    [TestClass]
    public sealed class TestShimFeatures
    {
        [TestMethod]
        public void TestStaticMethod()
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
        public void TestStaticPropertyGetter()
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
        public void TestStaticPropertySetter()
        {
            Console.Title = "this is console title";
            Shim setterShim = Shim.Replace(() => Console.Title, true).With((string title) => Console.Title = "My Title");
            string title = string.Empty;
            PoseContext.Isolate(() =>
            {

                title = Console.Title;
            }, setterShim);

            Assert.AreEqual(title, "My Title");
            Assert.AreNotEqual(Console.Title, "this is console title");
        }

        [TestMethod]
        public void TestClassPropertyGetter()
        {
            Shim classPropShim = Shim.Replace(() => Is.A<MyClass>().MyProperty).With((MyClass @this) => 100);
            MyClass myClass = new MyClass();
            int myProperty = 0;
            PoseContext.Isolate(() =>
            {
                myProperty = myClass.MyProperty;
            }, classPropShim);


            Assert.AreEqual(100, myProperty);
            Assert.AreEqual(0, myClass.MyProperty);
        }

        [TestMethod]
        public void TestClassPropertySetter()
        {
            Shim classPropShim1 = Shim.Replace(() => Is.A<MyClass>().MyProperty, true).With((MyClass @this, int prop) => { @this.MyProperty = prop * 10; });
            var myClass = new MyClass();
            PoseContext.Isolate(() =>
            {
                myClass.MyProperty = 5;

            }, classPropShim1);

            Assert.AreEqual(50, myClass.MyProperty);
        }

        [TestMethod]
        public void TestClassCtor()
        {
            Shim ctorShim = Shim.Replace(() => new MyClass()).With(() => new MyClass() { MyProperty = 10 });

            MyClass myClass = new MyClass();
            MyClass isolatedmyClass = null;
            PoseContext.Isolate(() =>
            {
                isolatedmyClass = new MyClass();

            }, ctorShim);

            Assert.AreEqual(10, isolatedmyClass?.MyProperty);
            Assert.AreEqual(0, myClass.MyProperty);
        }


        [TestMethod]
        public void TestClassMethod()
        {
            Shim classShim = Shim.Replace(() => Is.A<MyClass>().DoSomething()).With((MyClass @this) => Console.WriteLine("doing someting shimmed"));
            MyClass myClass = new MyClass();
            PoseContext.Isolate(() =>
            {
                myClass.DoSomething();
                MyClass myClass1 = new MyClass();
                myClass1.DoSomething();

            }, classShim);
        }

        [TestMethod]
        public void TestClassInstanceMethod()
        {
            MyClass myClass = new MyClass();
            Shim myClassShim = Shim.Replace(() => myClass.DoSomething()).With((MyClass @this) => Console.WriteLine("doing someting shimmed for instance"));
            PoseContext.Isolate(() =>
            {
                myClass.DoSomething();
                MyClass myClass1 = new MyClass();
                myClass1.DoSomething();

            }, myClassShim);
        }


        [TestMethod]
        public void TestStructMethod()
        {
            Shim structShim = Shim.Replace(() => Is.A<MyStruct>().DoSomething()).With((ref MyStruct @this) => Console.WriteLine("doing someting shimmed for struct"));
            // This block executes immediately
            PoseContext.Isolate(() =>
            {
                new MyStruct().DoSomething();

            }, structShim);
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
