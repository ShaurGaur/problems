/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

ull partOne(string file) {
    ifstream fin(file, ios::in);
    unordered_map<int, int> mask;
    string temp;
    vector<ull> mem(100000,0);

    while (!fin.eof()) {
        getline(fin, temp);
        if (temp[1] == 'a') {
            temp = temp.substr(7);
            mask.clear();
            for (int i = 0; i < 36; i++) 
                if (temp[i] != 'X')
                    mask[35-i] = temp[i] - '0';
        }
        else {
            size_t rb = temp.find(']');
            ull idx = stoul(temp.substr(4, rb-4), nullptr, 10);
            ull val = stoul(temp.substr(rb + 4), nullptr, 10);
            bitset<36> bits(val);
            for (pair<int, int> p : mask)
                bits[p.first] = p.second;
            mem[idx] = bits.to_ullong();
        }
    }
    
    ull sum = 0;
    for (ull i : mem) if (i != 0) sum += i;
    return sum;
}

ull partTwo(string file) {
    ifstream fin(file, ios::in);
    unordered_map<int, int> mask;
    vector<int> floats;
    vector<int> ones;
    string temp;
    unordered_map<ull, ull> mem;

    while (!fin.eof()) {
        getline(fin, temp);
        if (temp[1] == 'a') {
            temp = temp.substr(7);
            floats.clear();
            ones.clear();
            for (int i = 0; i < 36; i++) {
                if (temp[i] == 'X') floats.push_back(35-i);
                if (temp[i] == '1') ones.push_back(35-i);
            }
        }
        else {
            size_t rb = temp.find(']');
            ull idx = stoul(temp.substr(4, rb-4), nullptr, 10);
            ull val = stoul(temp.substr(rb + 4), nullptr, 10);
            bitset<36> bits(idx);
            for (int i : ones) bits[i] = 1;
            vector<bitset<36>> bitsets = {bits};
            
            for (int i : floats) {
                vector<bitset<36>> copy;
                for (bitset<36> b : bitsets) {
                    bitset<36> c = b;
                    bitset<36> d = b;
                    c[i] = 1;
                    d[i] = 0;
                    copy.push_back(c);
                    copy.push_back(d);
                }
                bitsets = copy;
            }
            
            for (auto b : bitsets)
                mem[b.to_ullong()] = val;
        }
    }
    
    ull sum = 0;
    for (auto p : mem) sum += p.second;
    return sum;    
}

int main() {
    string file = "input.txt";
    cout << "part 1: " << partOne(file) << endl;
    cout << "part 2: " << partTwo(file) << endl;
    return 0;
}