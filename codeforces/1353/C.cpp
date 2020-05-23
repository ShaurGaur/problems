#include <iostream>
#include <string>
using namespace std;

unsigned long long solve(int n) {
    unsigned long long s = 0;
    for (unsigned long long i = 1; i <= n / 2; i++)
        s += i * i;
    return s * 8;
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}