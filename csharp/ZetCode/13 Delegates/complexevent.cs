using System;


public delegate void OnFiveHandler(object sender, FiveEventArgs e);


public class FiveEventArgs : EventArgs {
    public int count;
    public DateTime time;

    public FiveEventArgs(int count, DateTime time) {
        this.count = count;
        this.time = time;
    }
}


public class FEvent {
    public event OnFiveHandler FiveEvent;

    public void OnFiveEvent(FiveEventArgs e) {
        FiveEvent(this, e);
    }
}


public class RandomEventGenerator {
    public void Generate() {
        int count = 0;
        FiveEventArgs args;

        FEvent fe = new FEvenet();
        fe.FiveEvent += new OnFiveHandler(Callback);

        Random random = new Random();

        for (int i = 0; i < 10; ++i) {
            int rn = random.Next(6);
            Console.WriteLine(rn);

            if (rn == 5) {
                count++;
                args = new FiveEventArgs(count, DateTime.Now);
                fe.OnFiveEvent(args);
            }
        }
    }

    public void Callback(object sender, FiveEventArgs e) {
        Console.WriteLine("Five event {0} occurred at {1}", e.count, e.time);
    }
}


public class ComplexEvent {
    static void Main() {
        RandomEventGenerator reg = new RandomEventGenerator();
        reg.Generate();
    }
}
