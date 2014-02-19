using System;


delegate void Mdelegate();


public class Anonymous {
	static void Main() {
		Mdelegate del = delegate {
			Console.WriteLine("Anonymous method");
		}
	}
}
