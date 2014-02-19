using System;


public delegate void OnFiveHandler(object sender, EventArgs e);


class FEvent {
	public event OnFiveHandler FiveEvent;

	public void OnFiveEvent() {
		if (FiveEvent != null)
			FiveEvent(this, EventArgs.Empty);
	}
}


public class SimpleEvent {
	static void Main() {
		FEvent fe = new FEvent();
		fe.FiveEvent += new OnFiveHandler(Callback);

		Random random = new Random();

		for (int i = 0; i < 10; ++i) {
			int rn = random.Next(6);
			Console.WriteLine(rn);

			if (rn == 5)
				fe.OnFiveEvent();
		}
	}

	public static void Callback(object sender, EventArgs e) {
		Console.WriteLine("Five Event Occurred");
	}
}
