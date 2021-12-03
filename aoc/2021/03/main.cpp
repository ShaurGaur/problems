#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<string> v;

ull parsenum(string s) {
    ull ans = 0;

    for (char c : s) {
        int x = c - '0';
        ans = ans * 2 + x;
    }

    return ans;
}

ull partOne() {
    ull g = 0, e = 0, n = v.size(), m = v[0].length();

    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;

        for (int j = 0; j < n; j++) {
            if (v[j][i] == '1') a++; 
            else b++;
        }

        if (a > b) {
            g = g * 2 + 1;
            e = e * 2;
        }
        else {
            e = e * 2 + 1;
            g = g * 2;
        }
    }

    return g * e;
}

void printvec(vector<string>& v) {
    for (string s : v) cout << s << " ";
    cout << endl;
}

ull partTwo() {
    ull oxygen = 0, carbon = 0;
    ull n = v.size(), m = v[0].length();
    vector<string> voxy = v, vcar = v;

    ull j = 0;
    while (voxy.size() > 1 && j < m) {
        ull one = 0, zero = 0;
        vector<string> ones = {}, zeros = {};

        for (string s : voxy) {
            if (s[j] == '1') {
                one++;
                ones.push_back(s);
            }
            else {
                zero++;
                zeros.push_back(s);
            }
        }

        if (one >= zero) voxy = ones;
        else voxy = zeros;
        j++;
    }

    j = 0;
    while (vcar.size() > 1 && j < m) {
        ull one = 0, zero = 0;
        vector<string> ones, zeros;

        for (string s : vcar) {
            if (s[j] == '1') {
                one++;
                ones.push_back(s);
            }
            else {
                zero++;
                zeros.push_back(s);
            }
        }

        if (one < zero) vcar = ones;
        else vcar = zeros;
        j++;
    }

    carbon = parsenum(voxy[0]);
    oxygen = parsenum(vcar[0]);
    return carbon * oxygen;
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
        v.push_back(x);
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}