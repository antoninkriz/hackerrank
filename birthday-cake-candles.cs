using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;

class Solution {
    static int birthdayCakeCandles(int[] ar) {
        var max = 0;
        var count = 0;

        foreach (var i in ar) {
            if (i > max) {
                max = i;
                count = 1;
            } else if (i == max) {
                count++;
            }
        }

        return count;
    }

    static void Main() {
        var textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int.Parse(Console.ReadLine());

        var ar = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        var result = birthdayCakeCandles(ar);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
