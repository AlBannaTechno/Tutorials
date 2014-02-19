using System;


public class CSharpApp {
    static void Main() {
        Action<string> act = ShowMessage;
        act("C# Language");
    }

    static void ShowMessage(string message) {
        Console.WriteLine(message);
    }
}
