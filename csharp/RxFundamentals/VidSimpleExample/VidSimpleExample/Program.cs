using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive;
using System.Reactive.Concurrency;
using System.Reactive.Linq;
using System.Threading;


namespace VidSimpleExample
{
    public class Program
    {
        private static void Main(string[] args)
        {
            Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}");

            Console.WriteLine("Basic");
            List<int> query = Enumerable.Range(1, 5).ToList();
            foreach (int num in query)
                Console.WriteLine(num);
            ImDone();

            Console.WriteLine("Using an Observer");
            IObservable<int> obsQuery = query.ToObservable();
            obsQuery.Subscribe(Console.WriteLine, ImDone);

            // Force the observable to run on a new thread, updated for 2.0 changes
            obsQuery = query.ToObservable(NewThreadScheduler.Default);
            // Note: moving the ImDone call out to after will make it be called immediately, as
            // the subscribe callbacks are handled on another thread due to the above setting.
            obsQuery.Subscribe(ProcessNumber, ImDone);

            // Turn any method into an observer
            IObserver<int> observer = Observer.Create<int>(ProcessNumber);
            obsQuery.Subscribe(observer);

            // Force the program to wait for input before closing
            Console.ReadKey();
        }

        private static void ProcessNumber(int num)
        {
            Console.WriteLine($"{num} Thread {Thread.CurrentThread.ManagedThreadId}");
        }

        private static void ImDone()
        {
            Console.WriteLine("I'm Done!\n");
        }
    }
}
