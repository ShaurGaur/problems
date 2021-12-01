#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define usi unsigned short int
#define MOD 1000000007
using namespace std;

bool mult_equal(string s, string t, int cs, int ct) {
    if (s.length() * cs != t.length() * ct) return false;

    for (int i = 0; i < s.length() * cs; i++) {
        if (s[i % s.length()] != t[i % t.length()]) 
            return false;
    }
    
    return true;
}

string solve(string s, string t) {
    int ls = s.length(), lt = t.length(), cs = 1, ct = 1;
    if (ls == lt) return (s != t) ? "-1" : s;

    while (ls != lt) {
        if (ls < lt) {
            cs++;
            ls += s.length();
        }
        else {
            ct++;
            lt += t.length();
        }
    }

    if (mult_equal(s, t, cs, ct)) {
        string ans = "";
        for (int i = 0; i < min(cs, ct); i++) 
            ans += (cs < ct) ? s : t;
        
        return ans;
    }
    else return "-1";
}

int main() {
    int q;
    cin >> q;
    string s, t;
    vector<string> ans;

    for (int i = 0; i < q; i++) {
        cin >> s >> t;
        cout << solve(s, t) << endl;
        // ans.push_back(solve(s, t));
    }

    // cout << endl;
    // for (string a : ans) cout << a << endl;

    return 0;
}