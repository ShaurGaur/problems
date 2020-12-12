#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int main() {
    ifstream fin("input.txt", ios::in);
    ll x = 0, y = 0, d = 0, v = 0, wx = 10, wy = 1;
    char c;

    while (!fin.eof()) {
        fin >> c >> v;

        // Part 1.
        // if (c == 'L') d = (d + v + 360) % 360;
        // else if (c == 'R') d = (d - v + 360) % 360;
        // if (c == 'F') {
        //     vector<char> dirs = {'E', 'N', 'W', 'S'};
        //     int degree = d / 90;
        //     c = dirs[d / 90];
        // }
        // if (c == 'N') y += v; 
        // else if (c == 'S') y -= v; 
        // else if (c == 'W') x -= v;
        // else if (c == 'E') x += v;

        // Part 2.
        if (c == 'F') {
            x += (v * wx);
            y += (v * wy);
        }
        else if (c == 'R') {
            ll times = v / 90;
            for (int i = 0; i < times; i++) {
                ll ox = wx, oy = wy;
                wx = oy, wy = (0 - ox);
            }
        }
        else if (c == 'L') {
            ll times = v / 90;
            for (int i = 0; i < times; i++) {
                ll ox = wx, oy = wy;
                wx = (0 - oy), wy = ox;
            }
        }
        else if (c == 'N') wy += v; 
        else if (c == 'S') wy -= v; 
        else if (c == 'W') wx -= v;
        else if (c == 'E') wx += v;
    }

    cout << "ans: " << abs(x) + abs(y) << endl;

    return 0;
}