#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<string> eqs;

ull findClosePar(string s, ull i) {
    ull fronts = 1, backs = 0, j = 1;
    while (backs < fronts) {
        if (s[i+j] == '(') fronts++;
        else if (s[i+j] == ')') backs++;
        if (backs != fronts) j++;
    }
    return j;
}

ull solve1(string s) {
    ull ans = 0, i = 0;
    bool mult = false;
    
    while (i < s.length()) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (mult) ans *= (s[i] - '0');
            else ans += (s[i] - '0');
        }
        else if (s[i] == '(') {
            ull j = findClosePar(s, i);
            ull x = solve1(s.substr(i+1, j-1));
            if (mult) ans *= x;
            else ans += x;
            i += j;            
        }
        else if (s[i] == '*') mult = true;
        else if (s[i] == '+') mult = false;
        i++;        
    }
    
    return ans;
}

ull solve2(string s) {
    ull ans = 0, i = 0;
    vector<ull> mults;

    while (i < s.length()) {
        if (s[i] == '*') {
            mults.push_back(ans);
            ans = 0;
        } else if (s[i] == '(') {
            ull j = findClosePar(s, i);
            ans += solve2(s.substr(i+1, j-1));
            i += j;            
        } else if (s[i] >= '0' && s[i] <= '9')
            ans += (s[i] - '0');
        i++;        
    }

    for (ull i : mults) ans *= i; 
    return ans;   
}

ull part1() {
    ull sum = 0;
    for (string s : eqs)
        sum += solve1(s);
    return sum;
}

ull part2() {
    ull sum = 0;
    for (string s : eqs) 
        sum += solve2(s);
    return sum;
}

int main() {
    string temp;
    cin >> temp;
    ifstream fin(temp, ios::in);
    ull sum = 0;

    while (!fin.eof()) {
        getline(fin, temp);
        eqs.push_back(temp);
    }
    fin.close();

    cout << "part 1: " << part1() << endl;
    cout << "part 2: " << part2() << endl;

    return 0;
}