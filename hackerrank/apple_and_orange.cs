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

    static void countApplesAndOranges(int s, int t, int a, int b, int[] apples, int[] oranges) {
        var x = 0;
        var y = 0;

        foreach (var i in apples)
            if (a + i >= s && a + i <= t)
                x++;

        foreach (var i in oranges) {
            if (b + i >= s && b + i <= t)
                y++;
        }

        Console.WriteLine(x);
        Console.WriteLine(y);

    }

    static void Main() {
        var st = Console.ReadLine().Split(' ');
        var s = int.Parse(st[0]);
        var t = int.Parse(st[1]);

        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);

        var mn = Console.ReadLine().Split(' ');
        var m = int.Parse(mn[0]);
        var n = int.Parse(mn[1]);

        var apples = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        var oranges = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

        countApplesAndOranges(s, t, a, b, apples, oranges);
    }
}
