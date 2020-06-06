#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull solve(int x, int y, int a, int b) {
    ull lo = min(x, y);
    ull hi = max(x, y);

    ull method1 = ((hi - lo) * a) + (lo * b);
    ull method2 = (hi + lo) * a;

    // cout << "M1: " << method1 << ", M2: " << method2 << ", Min: " << min(method1, method2) << ", ";

    return min(method1, method2);
}

int main() {
    int t, x, y, a, b;
    cin >> t;
    vector<ull> answers;

    for (int i = 0; i < t; i++) {
        cin >> x >> y >> a >> b;
        cout << solve(x, y, a, b) << endl;
        // answers.push_back(solve(x, y, a, b));
    }
    // cout << endl;
    // for (int s : answers) cout << s << endl;

    return 0;
}