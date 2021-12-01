#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define usi unsigned short int
#define MOD 1000000007
using namespace std;

string solve(vector<int>& v) {
    sort(v.begin(), v.end());
    ull a = 0, b = 0, t = 1;

    for (int i = v.size() - 1; i >= 0; i--) {
        if (t && !(v[i] % 2)) a += v[i];
        if (!t && (v[i] % 2)) b += v[i]; 
        t = (t + 1) % 2;
    }

    if (a > b) return "Alice";
    if (a < b) return "Bob";
    else return "Tie";
}

int main() {
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) cin >> v[j];
        cout << solve(v) << endl;
    }

    return 0;
}