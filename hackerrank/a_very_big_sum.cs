using System.IO;
using System.Linq;
using System.Text;
using System;

class Solution {
    static long aVeryBigSum(long[] ar)
        => ar.Sum();

    static void Main(string[] args) {
        var textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int.Parse(Console.ReadLine());
        var ar = Array.ConvertAll(Console.ReadLine().Split(' '), arTemp => long.Parse(arTemp));
        var result = aVeryBigSum(ar);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
