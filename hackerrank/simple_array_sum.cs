using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution {

    static int simpleArraySum(int[] ar)
        => ar.Sum();

    static void Main(string[] args) {
        var textWriter = new StreamWriter("aaa", true);

        int.Parse(Console.ReadLine());
        var ar = Array.ConvertAll(Console.ReadLine().Split(' '), arTemp => int.Parse(arTemp));
        var result = simpleArraySum(ar);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
