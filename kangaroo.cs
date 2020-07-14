using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;

class Solution {
    static string kangaroo(int x1, int v1, int x2, int v2) {
        var p1 = x1;
        var p2 = x2;

        while (p1 <= p2) {
            if (p1 == p2)
                return "YES";
            
            p1 += v1;
            p2 += v2;
        }

        return "NO";
    }

    static void Main() {
        var textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        var x1V1X2V2 = Console.ReadLine().Split(' ');
        var x1 = int.Parse(x1V1X2V2[0]);
        var v1 = int.Parse(x1V1X2V2[1]);
        var x2 = int.Parse(x1V1X2V2[2]);
        var v2 = int.Parse(x1V1X2V2[3]);

        var result = kangaroo(x1, v1, x2, v2);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
