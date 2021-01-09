#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define usi unsigned short int
#define MOD 1000000007
using namespace std;

string solve(ui w, ui h, int n) {
    ui m = 1;

    while (w && !(w % 2)) {
        m *= 2;
        w /= 2;
    }
    while (h && !(h % 2)) {
        m *= 2;
        h /= 2;
    }

    return (m >= n) ? "YES" : "NO";
}

int main() {
    ui t, w, h, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> w >> h >> n;
        cout << solve(w, h, n) << endl;
    }

    return 0;
}