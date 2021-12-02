#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

// Sources for Chinese Remainder Theorem Implementation:
// https://rosettacode.org/wiki/Modular_inverse#Ruby
// https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
// https://en.wikipedia.org/wiki/Chinese_remainder_theorem


int64_t mul_inv(int64_t a, int64_t b) {
	int64_t b0 = b, t, q;
	int64_t x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int64_t crt(vector<ll>& v, vector<ll>& idx) {
    int64_t prod = 1, result = 0;
    for (ll i : v) prod *= i;
    for (int i = 0; i < v.size(); i++) {
        int64_t q = prod / v[i];
        result += idx[i] * mul_inv(q, v[i]) * q;
    }
    return result % prod;
}

int main() {
    ifstream fin("input.txt", ios::in);
    ll time, ind = 0;
    string temp;
    fin >> time >> temp;
    vector<ll> v;
    vector<ll> idx;

    while (temp.find(',') != string::npos) {
        size_t comma = temp.find(',');
        ll num = strtol(temp.substr(0, comma).c_str(), nullptr, 10);
        if (num) {
            v.push_back(num);
            idx.push_back(ind);
        }
        temp = temp.substr(comma + 1);
        ind++;
    }
    ll num = strtol(temp.c_str(), nullptr, 10);
    if (num) {
        v.push_back(num);
        idx.push_back(ind);
    }
    
    vector<ll> mods;
    for (int i : v) mods.push_back(i * (time / i + 1) - time);
    int id = 0;
    for (int i = 1; i < v.size(); i++)
        if (mods[i] < mods[id]) id = i;
    cout << "part 1: " << v[id] * mods[id] << endl;

    for (int i = 0; i < v.size(); i++)
        idx[i] = v[i] - idx[i];
    cout << "part 2: " << crt(v, idx) << endl;

    return 0;
}