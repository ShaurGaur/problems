#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<pair<string, ull>> v;

ull partOne() {
    int x = 0, y = 0;

    for (auto p : v) {
        if (p.first == "forward") x += p.second;
        if (p.first == "down") y += p.second;
        if (p.first == "up") y -= p.second;
    }

    return x * y;
}

ull partTwo() {
    int x = 0, y = 0, a = 0;

    for (auto p : v) {
        if (p.first == "forward") {
            x += p.second;
            y += a * p.second;
        }
        if (p.first == "down") a += p.second;
        if (p.first == "up") a -= p.second;
    }

    return x * y;
}

int main(int argc, char **argv) {
    string input_txt = "";
    if (argc < 2) {
        cout << "file: ";
        cin >> input_txt;
    }
    else input_txt = string(argv[1]);
    ifstream fin(input_txt.c_str(), ios::in);
    
    while (!fin.eof()) {
        string dir;
        int x;
        fin >> dir >> x;
        v.push_back({dir, x});
    }

    cout << partOne() << endl;
    cout << partTwo() << endl;
    return 0;
}