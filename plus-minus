using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;

class Solution {
    static string FormatDouble(double d)
        => string.Format("{0:0.00000}", d);

    static void plusMinus(int[] arr) {
        var res = arr.Aggregate((pos: 0.0, neg: 0.0, zer: 0.0), (r, n) => {
            if (n > 0)
                r.pos++;
            else if (n < 0)
                r.neg++;
            else
                r.zer++;

            return r;
        });

        Console.WriteLine(FormatDouble(res.pos / arr.Length));
        Console.WriteLine(FormatDouble(res.neg / arr.Length));
        Console.WriteLine(FormatDouble(res.zer / arr.Length));
    }

    static void Main(string[] args) {
        int.Parse(Console.ReadLine());
        var arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => int.Parse(arrTemp));
        plusMinus(arr);
    }
}
