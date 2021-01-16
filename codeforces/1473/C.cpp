#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define usi unsigned short int
#define MOD 1000000007
using namespace std;

vector<int> solve(int n, int k) {
    vector<int> p(k, 0);
    for (int i = 1; i <= k; i++) p[i-1] = i;

    if (n > k) {
        int d = 2*k - n;
        for (int i = d; i <= k; i++) {
            p[i-1] = k - (i-d);
        }
    }
    
    return p;
}

int main() {
    int t, n, k;
    cin >> t;
    vector<vector<int>> ans;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        // ans.push_back(solve(n, k));
        vector<int> v = solve(n, k);
        for (int i : v) cout << i << " ";
        cout << endl;
    }

    // for (vector<int> v : ans) {
    //     for (int i : v) cout << i << " ";
    //     cout << endl;
    // }

    return 0;
}