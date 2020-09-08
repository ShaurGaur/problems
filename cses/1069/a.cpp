#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    unsigned long long n = s.length(), cur = 1, ans = 1;
    char letter = s[0];

    if (n > 1) for (int i = 1; i < n; i++) {
        if (s[i] != letter) {
            cur = 1;
            letter = s[i];
        } 
        else {
            cur++;
            ans = max(cur, ans);
        }
    }

    cout << ans << endl;
    return 0;
}