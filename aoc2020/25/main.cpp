#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

ull card, door;

ull loopSize(ull key) {
    ull div = 20201227, cur = 1, idx = 0, sub = 7;
    while (cur != key) {
        cur *= sub;
        cur %= div;
        idx++;
    }
    return idx;
}

ull decrypt(ull sub, ull idx) {
    ull cur = 1, div = 20201227;
    while (idx > 0) {
        cur *= sub;
        cur %= div;
        idx--;        
    }
    return cur;
}

ull part1() {
    ull cs = loopSize(card), ds = loopSize(door);
    ull ans = decrypt(card, ds);
    return ans;
}

int main() {
    cout << "File: ";
    string temp;
    cin >> temp;
    ifstream fin(temp, ios::in);
    fin >> card >> door;
    fin.close();
    cout << "part 1: " << part1() << endl;
    return 0;
}