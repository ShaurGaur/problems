#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<vector<ull>> v;
ull n;

ull partOne() {
    vector<vector<ull>> dp(n, vector<ull>(n, ULLONG_MAX));
    
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = v[i][0] + dp[i-1][0];
        dp[0][i] = v[0][i] + dp[0][i-1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + v[i][j];
        }
    }

    return dp[n-1][n-1];
}

ull partTwo() {
    for (int i = 0; i < (4 * n); i++) {
        for (int j = 0; j < n; j++) {
            ull x = v[j][v[j].size() - n] + 1;
            if (x > 9) x = 1;
            v[j].push_back(x);
        }
    }

    for (int i = 0; i < (4 * n); i++) {
        v.push_back({});
        for (ull j : v[v.size() - 1 - n]) {
            ull x = ((j + 1) > 9) ? 1 : j + 1;
            v[v.size() - 1].push_back(x);
        }
    }

    n *= 5;
    return partOne();
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
    n = v.size();

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}