using System;


public class ActionDelegate {
    static void Main() {
        Action act = ShowMessage;
        act();
    }

    static void ShowMessage() {
        Console.WriteLine("C# Language");
    }
}
