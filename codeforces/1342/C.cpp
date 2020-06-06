#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull part(int a, int b, ull x) {
    ull ans = x + 1;
    int p = a * b;

    ull quotient = ans / p;
    ull remainder = ans % p;

    ans -= (quotient * b);
    ans -= min((ull) b, remainder);

    return ans;
}

ull solve(int a, int b, ull l, ull r) {
    if (b % a == 0) return 0;
    return part(a, b, r) - part(a, b, l-1);
}

int main() {
    int t, a, b, q;
    ull l, r;
    cin >> t;

    vector<string> ans;

    for (int i = 0; i < t; i++) {
        cin >> a >> b >> q;
        for (int i = 0; i < q; i++) {
            cin >> l >> r;
            ans.push_back(to_string(solve(min(a, b), max(a, b), l, r)));
        }
        for (string s : ans) cout << s << " ";
        cout << endl;
        ans.clear();
    }

    return 0;
}