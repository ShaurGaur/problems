#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

int main() {
    int n, t;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout << 0 << endl;
        return 0;
    }
    t = n * (n+1) / 4;
    vector<int> dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;


    return 0;
}