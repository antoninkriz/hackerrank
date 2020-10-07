using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Linq;
using System;

class Solution
{
    public static int diagonalDifference(List<List<int>> arr)
    {
        var sumLeft = 0;
        var sumRight = 0;

        for (var i = 0; i < arr.Count; i++)
        {
            sumLeft += arr[i][i];
            sumRight += arr[i][arr[i].Count - i - 1];
        }

        return Math.Abs(sumLeft - sumRight);
    }
    
    public static void Main(string[] args)
    {
        var textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        var n = Convert.ToInt32(Console.ReadLine().Trim());
        var arr = new List<List<int>>();

        for (int i = 0; i < n; i++)
            arr.Add(Console.ReadLine().TrimEnd().Split(' ').Select(arrTemp => int.Parse(arrTemp)).ToList());

        var result = diagonalDifference(arr);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
