using System.IO;
using System.Text;
using System.Linq;
using System;

class Solution {
    static int[] compareTriplets(int[] a, int[] b) {
        var res = new int[] {0,0};
        for (var i = 0; i < a.Length; i++) {
            if (a[i] > b[i])
                res[0]++;
            else if (a[i] < b[i])
                res[1]++;
        }

        return res;
    }

    static void Main() {
        var textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        var a = Console.ReadLine().TrimEnd().Split(' ').Select(aTemp => int.Parse(aTemp)).ToArray();
        var b = Console.ReadLine().TrimEnd().Split(' ').Select(bTemp => int.Parse(bTemp)).ToArray();
        var result = compareTriplets(a, b);

        textWriter.WriteLine(string.Join(" ", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
