using System;
using System.Collections.Generic;


public class PredicateDelegate {
    static void Main() {
        List<int> list = new List<int> { 4, 2, 3, 0, 6, 7, 1, 9 };
        Predicate<int> predicate = greaterThanThree;
        List<int> list2 = list.FindAll(predicate);

        foreach (int i in list2)
            Console.WriteLine(i);
        // output:
        // true, false, false, false, true, true, false, true
    }

    static bool greaterThanThree(int x) {
        return x > 3;
    }
}
