using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;

class Solution {
    static void miniMaxSum(long[] arr) {
        var min = arr[0];
        var max = arr[0];
        var sum = arr[0];
        for (var i = 1; i < arr.Length; i++) {
            sum += arr[i];
            if (arr[i] > max)
                max = arr[i];
            else if (arr[i] < min)
                min = arr[i];
        }

        Console.WriteLine($"{sum - max} {sum - min}");
    }

    static void Main() {
        var arr = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        miniMaxSum(arr);
    }
}
