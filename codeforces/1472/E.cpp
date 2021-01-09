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

    // for (int i = 0; i < n; i++) {
    //     bool found = false;
    //     for (int j = 0; j < n && !found; j++) {
    //         if ((h[j] < h[i] && w[j] < w[i]) || (w[j] < h[i] && h[j] < w[i])) {
    //             found = true;
    //             ans[i] = j+1;
    //         }
    //     }
    // }

    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    for (int i = 0; i < n; i++) {
        pq.push({w[i], h[i], i});
    }

    vector<vector<int>> temp;

    for (int i = 0; i < n; i++) {
        vector<int> f = pq.top();
        while (!pq.empty() && !(f[1] < h[i] && f[0] < w[i]) && !(f[0] < h[i] && f[1] < w[i])) {
            temp.push_back(f);
            pq.pop();
            if (!pq.empty()) f = pq.top();
        }

        if (!pq.empty()) ans[i] = f[2] + 1;

        while (!temp.empty()) {
            pq.push(temp.back());
            temp.pop_back();
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