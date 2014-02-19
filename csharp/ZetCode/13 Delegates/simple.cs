using System;


delegate void Mdelegate();


public class SimpleDelegate {
	static void Main() {
		Mdelegate del = new Mdelegate(Callback);
		del();
	}

	static void Callback() {
		Console.WriteLine("Calling callback");
	}
}
