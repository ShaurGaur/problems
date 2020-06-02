#include <bits/stdc++.h>
using namespace std;

unsigned long long solve(vector<int>& v) {
    unsigned long long s = 0;
    for (int i = v[0] + v[1]; i <= v[1] + v[2]; i++) {
        int k = 
        printf("i: %d, k: %d \n", i, k);
        s += max(0, k);
    }
    return s;
}

int main() {
    vector<int> v(4);
    cin >> v[0] >> v[1] >> v[2] >> v[3];

    cout << solve(v) << endl;
    return 0;
}