#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int period(string s) {
    int n = s.length();
    bool p1 = true;
    bool p2 = true;

    for (int i = 0; i < n - 2; i++) {
        if (s[i] != s[i+1]) p1 = false;
        if (s[i] != s[i+2]) p2 = false;
    }
    if (s[n-2] != s[n-1]) p1 = false;

    if (p1) return 1;
    if (p2) return 2;
    else return 3;
}

string solve(string s) {
    if (period(s) < 3) return s;

    string t;
    for (int i = 0; i < s.length(); i++) {
        t.append("10");
    }
    
    return t;
}


int main() {
    int n;
    cin >> n;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}