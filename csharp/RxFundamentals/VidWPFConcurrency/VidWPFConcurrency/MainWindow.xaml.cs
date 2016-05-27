using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Concurrency;
using System.Reactive.Linq;
using System.Threading;
using System.Windows;

namespace VidWPFConcurrency
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private static string StringWait(string input)
        {
            Thread.Sleep(TimeSpan.FromSeconds(0.25));
            return input;
        }

        private void ImDone()
        {
            uiResultsTxt.AppendText("I'm done!\n");
        }

        private void uiStartBtn_OnClick(object sender, RoutedEventArgs e)
        {
            IEnumerable<string> query = Enumerable
                .Range(1, 25).Select(n => StringWait(n.ToString()));

            IObservable<string> obsQuery = query.ToObservable(Scheduler.Default);
            // Helper method for ObserveOn(DispatcherScheduler.Current)
            obsQuery.ObserveOnDispatcher()
                    .Subscribe(n => uiResultsTxt.AppendText($"{n}\n"), ImDone);
        }
    }
}
