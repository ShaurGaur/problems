#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define usi unsigned short int
#define MOD 1000000007
using namespace std;

string solve(int uno, int dos) {
    if (uno % 2) return "NO";
    if (dos % 2 && uno < 2) return "NO";
    return "YES";
}

int main() {
    int t, n, uno, dos, x;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        uno = 0, dos = 0;
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1) uno++;
            if (x == 2) dos++;
        }
        cout << solve(uno, dos) << endl;
    }

    return 0;
}