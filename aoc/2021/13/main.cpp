#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<vector<bool>> v(2000, vector<bool>(2000, false));
queue<pair<char, ull>> q;

void printGrid() {
    cout << endl;
    for (vector<bool> w : v) {
        for (bool b : w) {
            cout << ((b) ? '#' : '.');
        }
        cout << endl;
    }
    cout << endl;
}

ull fold() {
    auto p = q.front();
    char dir = p.first;
    int idx = (int) p.second;
    ull n = v.size(), m = v[0].size();
    q.pop();

    if (dir == 'y') {
        for (int i = 1; (i + idx) < n && (idx - i) >= 0; i++) {
            for (int j = 0; j < m; j++) {
                v[idx-i][j] = v[idx-i][j] || v[idx+i][j];
            }
        }
        v.resize(idx);
    }
    else if (dir == 'x') {
        for (int i = 0; i < n; i++) {
            for (int j = 1; (j + idx) < m && (idx - j) >= 0; j++) {
                v[i][idx-j] = v[i][idx-j] || v[i][idx+j];
            }
            v[i].resize(idx);
        }        
    }

    ull ans = 0;
    for (vector<bool> w : v) for (bool b : w) if (b) ans++;
    return ans;
}

ull partOne() {
    return fold();
}

ull partTwo() {
    ull ans = 0;
    while (!q.empty()) fold();
    printGrid();
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
    
    string s;
    bool foldalong = false;
    while (!fin.eof()) {
        getline(fin, s);
        if (s[0] == 'f') foldalong = true;
        if (s.length() == 1) continue;

        if (foldalong) {
            size_t equal = s.find('=');
            char dir = s[equal - 1];
            ull value = stoull(s.substr(equal + 1));
            q.push({dir, value});
        }
        else {
            size_t comma = s.find(',');
            // cout << s.substr(0, comma) << endl;
            ull i = stoull(s.substr(0, comma));
            ull j = stoull(s.substr(comma + 1));
            v[j][i] = true;
        }
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}