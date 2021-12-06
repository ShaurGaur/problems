#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<ull, ull> v;

ull run(ull days) {
    for (int i = 0; i < days; i++) {
        unordered_map<ull, ull> w;

        // for (int x : v) {
        //     if (x == 0) {
        //         w.push_back(6);
        //         w.push_back(8);
        //     } 
        //     else w.push_back(--x);
        // }

        for (auto p : v) {
            if (p.first == 0) {
                w[6] += p.second;
                w[8] += p.second;
            }
            else w[p.first - 1] += p.second;
        }

        v = w;
    }

    ull ans = 0;
    for (auto p : v) {
        ans += p.second;
    }

    return ans;
}

ull partOne() {
    return run(80);
}

ull partTwo() {
    return run(256 - 80);
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