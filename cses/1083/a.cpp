#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<bool> v(n+1, true);

    for (int i = 1; i < n; i++) {
        cin >> x;
        v[x] = false;
    }
    
    int i = 1;
    while (!v[i]) i++;
    cout << i << endl;

    return 0;
}