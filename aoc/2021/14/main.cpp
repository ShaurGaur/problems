#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<char, unordered_map<char, char>> m;
string s;

ull score() {
    unordered_map<char, ull> freqs;
    for (char c : s) freqs[c]++;

    ull maxScore = 0, minScore = ULLONG_MAX;
    for (auto p : freqs) {
        if (p.second > maxScore) maxScore = p.second;
        if (p.second < minScore) minScore = p.second;
    }

    return maxScore - minScore;
}

void step() {
    string t = "";
    t.push_back(s[0]);

    for (int i = 1; i < s.length(); i++) {
        t.push_back(m[s[i-1]][s[i]]);
        t.push_back(s[i]);
    }

    s = t;
}

ull partOne() {
    for (int i = 0; i < 10; i++) step();
    return score();
}

ull partTwo() {
    for (int i = 10; i < 40; i++) step();
    return score();
}

int main(int argc, char **argv) {
    string input_txt = "";
    if (argc < 2) {
        cout << "file: ";
        cin >> input_txt;
    }
    else input_txt = string(argv[1]);
    ifstream fin(input_txt.c_str(), ios::in);
    
    fin >> s;

    string x, y;
    while (!fin.eof()) {
        fin >> x >> y >> y;
        m[x[0]][x[1]] = y[0];
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}