#include <bits/stdc++.h>

using namespace std;

class xy {
public:
    int x, y;

    friend ostream &operator>>(ostream &os, const xy &val) {
        return os << "{x: " << val.x << ", y: " << val.y << "}";
    }
};

static const inline auto pairCmp = [](const xy &a, const xy &b) -> bool {
    return a.x < b.x;
};

typedef decltype(pairCmp) cmp;

inline double rightAngleMagic(xy bot, xy top, int prevY) {
    prevY -= bot.y;
    top.y -= bot.y;
    bot.y = 0;

    double a = top.y;
    double b = bot.x - top.x;
    double angleA = atan(a / b);

    return (a - prevY) / sin(angleA);
}

double solve(const vector<xy> &data, int size) {
    double ans = 0;
    
    int max = 0;
    
    for (int i = size - 1; i > 0; i -= 2) {
        xy bot = data[i];
        xy top = data[i - 1];

        if (max >= top.y)
            continue;

        ans += rightAngleMagic(bot, top, max);
        max = top.y;
    }

    return ans;
}

/**
 * Sunny Mountains
 */
int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int n;
        cin >> n;

        auto data = set<xy, cmp>(pairCmp);
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            data.insert({x, y});
        }

        cout << fixed << setprecision(2) << solve(vector<xy>(data.begin(), data.end()), n) << endl;
    }

    return 0;
}

