using System;


public class Literals
{
    public static void Main()
    {
        bool sng = true;
        string name = "James";
        string job = null;
        double weight = 68.5;
        DateTime born = DateTime.Parse("November 12, 1987");

        Console.WriteLine("His name is {0}", name);

        if (sng)
            Console.WriteLine("He is single");
        else
            Console.WriteLine("He is in a relationship");

        Console.WriteLine("His job is {0}", job);
        Console.WriteLine("He weighs {0} kilograms", weight);
        Console.WriteLine("He was born in {0}", string.Format("{0:yyyy}", born));
    }
}