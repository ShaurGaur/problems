#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<ull, ull> v;

ull partOne() {
    ull ans = ULLONG_MAX;

    for (auto p : v) {
        ull cand = 0;
        for (auto q : v) {
            cand += q.second * (max(p.first, q.first) - min(p.first, q.first));
        }
        ans = min(ans, cand);
    }

    return ans;
}

ull partTwo() {
    ull ans = ULLONG_MAX;

    for (auto p : v) {
        ull cand = 0;
        for (auto q : v) {
            ull dist = max(p.first, q.first) - min(p.first, q.first);
            cand += q.second * ((dist * (dist + 1)) / 2);
        }
        ans = min(ans, cand);
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
    
    ull x;
    while (!fin.eof()) {
        fin >> x;
        v[x]++;
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}