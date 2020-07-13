using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {
    static void staircase(int n) {
        var s = new StringBuilder();
        for (int i = 0; i < n; i++)
            s.Append(' ', n - i - 1)
             .Append('#', i + 1)
             .Append(Environment.NewLine);

        Console.WriteLine(s);
    }

    static void Main() {
        var n = int.Parse(Console.ReadLine());
        staircase(n);
    }
}
