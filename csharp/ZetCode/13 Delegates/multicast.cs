using System;


delegate void Mdelegate(int x, int y);


public class Oper {
	public static void Add(int x, int y) {
		Console.WriteLine("{0} + {1} = {2}", x, y, x + y);
	}

	public static void Sub(int x, int y) {
		Console.WriteLine("{0} - {1} = {2}", x, y, x - y);
	}
}


public class CSharpApp {
	static void Main() {
		Mdelegate del = new Mdelegate(Oper.Add);

		del += new Mdelegate(Oper.Sub);
		del(6, 4);
		// output:
		// 6 + 4 = 10
		// 6 - 4 = 2

		del -= new Mdelegate(Oper.Sub);
		del(2, 8);
		// output:
		// 2 + 8 = 10
	}
}
