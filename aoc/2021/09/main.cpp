#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<vector<ull>> v;
int n, m;

vector<pair<ull, ull>> lows;
vector<vector<bool>> visited;

ull partOne() {
    ull ans = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        vector<pair<ull, ull>> neighbors = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
        bool lowest = true;

        for (auto p : neighbors) {
            if (p.first >= 0 & p.first < n && p.second >= 0 & p.second < m) {
                if (v[p.first][p.second] <= v[i][j]) lowest = false;
            }
        }

        if (lowest) {
            ans += (v[i][j] + 1);
            lows.push_back({i, j});
        }
    }    

    return ans;
}

ull dfs(ull i, ull j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (v[i][j] == 9) return 0;
    if (visited[i][j]) return 0;

    ull ans = 1;
    visited[i][j] = true;
    vector<pair<ull, ull>> neighbors = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
    for (auto p : neighbors) ans += dfs(p.first, p.second);

    return ans;
}

ull partTwo() {
    ull ans = 0;
    visited.resize(n, vector<bool>(m, false));
    vector<ull> sizes;

    for (auto p : lows)
        sizes.push_back(dfs(p.first, p.second));
    sort(sizes.rbegin(), sizes.rend());

    ans = sizes[0] * sizes[1] * sizes[2];
    return ans;
}

int main(int argc, char **argv) {
    string input_txt = "";
    if (argc < 2) {
        cout << "file: ";
        cin >> input_txt;
    }
    else input_txt = string(argv[1]);
    ifstream fin(input_txt.c_str(), ios::in);
    
    string x;
    while (!fin.eof()) {
        fin >> x;
        v.push_back({});
        for (char c : x) {
            v.back().push_back(c - '0');
        }
    }
    n = v.size();
    m = v[0].size();

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}