using System;


public delegate void NameDelegate(string msg);


public class Person {
	public string firstName;
	public string secondName;

	public Person(string firstName, string secondName) {
		this.firstName = firstName;
		this.secondName = secondName;
	}

	public void ShowFirstName(string msg) {
		Console.WriteLine(msg + this.firstName);
	}

	public void ShowSecondName(string msg) {
		Console.WriteLine(msg + this.secondName);
	}
}

public class CSharpApp {
	public static void Main() {
		Person per = new Person("Fabius", "Maximus");

		NameDelegate nDelegate = new NameDelegate(per.ShowFirstName);
		nDelegate("Call 1: ");

		nDelegate = new NameDelegate(per.ShowSecondName);
		nDelegate("Call 2: ");
	}
}
