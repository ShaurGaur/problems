#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define usi unsigned short int
#define MOD 1000000007
using namespace std;

string solve(vector<int>& a, int d) {
    sort(a.begin(), a.end());
    if (a.back() <= d) return "YES";
    if (a.front() > d) return "NO";
    return (a[0] + a[1] <= d) ? "YES" : "NO";
}

int main() {
    int t, n, d;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> d;
        vector<int> a(n);
        for (int j = 0; j < n; j++) cin >> a[j];
        cout << solve(a, d) << endl;
    }
    return 0;
}