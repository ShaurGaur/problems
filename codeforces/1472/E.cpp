#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define usi unsigned short int
#define MOD 1000000007
using namespace std;

vector<int> solve(vector<int>& w, vector<int>& h) {
    int n = w.size();
    vector<int> ans(n, -1);
    if (n == 1) return ans;
    vector<vector<int>> pq;
    for (int i = 0; i < n; i++) pq.push_back({w[i], h[i], i+1});
    sort(pq.begin(), pq.end());

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < n && ans[i] == -1) {
            if (!(pq[j][1] < h[i] && pq[j][0] < w[i]) && !(pq[j][0] < h[i] && pq[j][1] < w[i])) j++;
            else ans[i] = pq[j][2];
        }
    }

    return ans;
}

int main() {
    int t, n;
    cin >> t;
    vector<vector<int>> ans;
    
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> w(n);
        vector<int> h(n);
        for (int j = 0; j < n; j++) cin >> w[j] >> h[j];
        ans.push_back(solve(w, h));
    }

    cout << endl;
    for (vector<int> v : ans) {
        for (int i : v) cout << i << " ";
        cout << endl;
    }

    return 0;
}