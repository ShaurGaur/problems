#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool descending (int a, int b) {return a > b;}

unsigned long long solve(int n, int k, vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), descending);

    unsigned long long s = 0;
    for (int i = 0; i < n; i++) {
        if (k > 0) {
            s += max(a[i], b[i]);
            k--;
        }
        else s += a[i];
    }
    return s;
}

int main() {
    int t, n, k;
    vector<int> a, b;
    // vector<unsigned long long> solves;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> k;

        a.resize(n);
        b.resize(n);
        
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        // solves.push_back(solve(n, k, a, b));
        cout << solve(n, k, a, b) << endl;
    }

    // for (auto s : solves) cout << s << endl;

    return 0;
}