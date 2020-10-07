using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;

class Result
{
    public static IEnumerable<int> gradingStudents(List<int> grades)
        => grades.Select((n) => (n >= 38 && n % 5 >= 3) ? n + (5 - (n % 5)) : n);
}

class Solution
{
    public static void Main()
    {
        var textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        var gradesCount = int.Parse(Console.ReadLine().Trim());

        var grades = new List<int>();
        for (int i = 0; i < gradesCount; i++) {
            var gradesItem = int.Parse(Console.ReadLine().Trim());
            grades.Add(gradesItem);
        }

        var result = Result.gradingStudents(grades);

        textWriter.WriteLine(String.Join("\n", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
