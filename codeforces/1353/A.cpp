#include <iostream>
using namespace std;

int solve(int n, int m) {
    if (n == 1) return 0;
    if (n == 2) return m;
    else return m * 2; 
}


int main() {
    int t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> m;
        cout << solve(n, m) << endl;
    }

    return 0;
}