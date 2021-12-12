#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<vector<ull>> v;
ull n = 10;
int flash_index = -1;

ull step() {
    ull flashes = 0;
    vector<vector<bool>> flashed(n, vector<bool>(n, false));
    queue<pair<ull, ull>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j]++;
            if (v[i][j] > 9) q.push({i, j});
        }
    }

    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (flashed[i][j]) continue;
        flashed[i][j] = true;
        flashes++;

        vector<pair<ull, ull>> neighbors = {
            {i-1, j-1}, {i-1, j}, {i-1,j+1},
            {i, j-1}, {i,j+1},
            {i+1, j-1}, {i+1, j}, {i+1,j+1},
        };

        for (auto p : neighbors) {
            if (p.first >= 0 && p.first < n && p.second >= 0 && p.second < n) {
                v[p.first][p.second]++;
                if (v[p.first][p.second] > 9) q.push(p);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flashed[i][j]) v[i][j] = 0;
        }
    }

    return flashes;
}

ull partOne() {
    ull ans = 0;
    for (int i = 1; i <= 100; i++) {
        ull score = step();
        if (score == n * n) flash_index = i;
        ans += score;
    }
    return ans;
}

ull partTwo() {
    ull ans = (flash_index < 0) ? 101 : flash_index;
    if (flash_index >= 0) return flash_index;

    while (true) {
        ull score = step();
        if (score == n * n) return ans;
        ans++;
    }

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
        for (char c : x) v.back().push_back(c - '0');
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}