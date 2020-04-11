#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void print(int r, int c, int& s) {
    cout << r << ' ' << c << endl;
    s++;
}

string bin(int d) {
    string b;
    for (int j = 29; j >= 0; j--) {
        int p = (int) pow(2.0, j * 1.0);
        b.append(to_string(d / p));
        d %= p;
    }
    return b;
}

void solve() {
    int s = 0;
    int n; cin >> n;
    if (n <= 500) {
        for (int i = 1; i <= n; i++) print(i , 1, s); 
        // cout << "s: " << s << endl;
        return;
    } else if (n <= 998) {
        for (int i = 1; i <= n/2; i++) print(i, 1, s);
        print((n/2)+1, 2, s);
        if (n % 2 == 1) print((n/2)+2, 1, s);
        // cout << "s: " << s << endl;
        return;  
    }
    
    string b = bin(n-30);
    // cout << b << endl;
    int l = b.length();
    int t = 0;
    
    int i = 1;
    while (i <= 30 && t < n) {
        if (b[l-i] == '0') {
            print(i, 1, s);
            t++;
        } else {
            for (int j = 1; j <= i; j++) print(i, j, s);
            t += pow(2.0, (i-1) * 1.0);
        }
        // cout << "total: " << t << endl;
        i++;        
    }
    int r = n - t;
    for (int i = 1; i <= r; i++) print(30 + i, 1, s);
    // cout << "s: " << s << endl;
    return;
}


int main() {
    int n_cases;
    cin >> n_cases;

    //int cases[n_cases];
    //for (int i = 0; i < n_cases; i++) cin >> cases[i];

    for (int i = 0; i < n_cases; i++) {
        cout << "Case #" << i+1 << ":" << endl;
        solve();
    }

    return 0;
}
