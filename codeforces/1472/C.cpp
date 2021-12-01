#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define usi unsigned short int
#define MOD 1000000007
using namespace std;

ull solve(vector<ull>& v) {
    int n = v.size();
    vector<ull> dp(n, -1);

    for (int i = n-1; i >= 0; i--) {
        dp[i] = v[i];
        if (i + v[i] < n) dp[i] += dp[i + v[i]];
    }

    ull m = 0;
    for (ull i : dp) m = max(m, i);
    return m;
}

int main() {
    int t, n;
    cin >> t;
    vector<ull> ans;

    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<ull> v(n);
        for (int j = 0; j < n ; j++) cin >> v[j];
        cout << solve(v) << endl;
        // ans.push_back(solve(v));
    }

    // cout << endl;
    // for (ull i : ans) cout << i << endl;
    return 0;
}