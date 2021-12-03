#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

ull partOne(vector<ull>& v) {
    ull increases = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) increases++;
    }
    return increases;
}

ull partTwo(vector<ull>& v) {
    ull store = v[0] + v[1] + v[2];
    ull ans = 0;

    for (int i = 3; i < v.size(); i++) {
        ull x = v[i] + v[i-1] + v[i-2];
        if (x > store) ans++;
        store = x;
    }

    return ans;
}

int main(int argc, char **argv) {
    ifstream fin("input.txt", ios::in);
    vector<ull> v;
    
    while (!fin.eof()) {
        int x;
        fin >> x;
        v.push_back(x);
    }

    cout << "Part 1: " << partOne(v) << endl;
    cout << "Part 2: " << partTwo(v) << endl;
    return 0;
}