#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
    ull n = 0, x = 0, ans = 0, threshold = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > threshold) threshold = x;
        if (x < threshold) ans += (threshold - x);
    }

    cout << ans << endl;
    return 0;
}