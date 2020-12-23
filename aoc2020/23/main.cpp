#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

struct cup {
    ull val;
    cup* next;
};

vector<int> cups;
unordered_map<int, cup*> ptrs;

string part1() {
    ull cur = 0;
    vector<int> c = cups;
    string ans = "";
    for (int t = 0; t < 100; t++) {
        vector<int> pickups;
        for (int i = 1; i <= 3; i++) {
            int idx = (cur + i) % 9;
            pickups.push_back(c[idx]);
        }
        for (int p : pickups)
            c.erase(find(c.begin(), c.end(), p));

        int curCup = c[cur], destCup = (c[cur] == 1) ? 9 : c[cur] - 1;
        while (find(pickups.begin(), pickups.end(), destCup) != pickups.end())
            destCup = (destCup == 1) ? 9 : destCup - 1;

        auto it = find(c.begin(), c.end(), destCup);
        c.insert(it+1, pickups.begin(), pickups.end());
        cur = -1;
        for (int i = 0; i < 9 && cur == -1; i++)
            if (c[i] == curCup) cur = i;
        cur = (cur + 1) % 9;
    }

    ull one = -1;
    for (int i = 0; i < 9 && one == -1; i++)
        if (c[i] == 1) one = i;

    for (int i = 1; i <= 8; i++) 
        ans.push_back((c[(one + i) % 9] + '0'));
    return ans;
}

// Special thanks to https://git.sr.ht/~williewillus/aoc_2020/tree/master/src/day23.c
// I based the steps in the loop on the above, but implemented my own conversion.
ull part2() {
    ull ans = 1, cupCount = 1000000;

    for (int i = 1; i <= cupCount; i++) {
        ptrs[i] = new cup;
        ptrs[i]->val = i;
        ptrs[i]->next = nullptr;
    }

    for (int i = 0; i < 8; i++) 
        ptrs[cups[i]]->next = ptrs[cups[i+1]];
    ptrs[cups[8]]->next = ptrs[10];
    for (int i = 10; i < cupCount; i++)
        ptrs[i]->next = ptrs[i+1];
    ptrs[cupCount]->next = ptrs[cups[0]];

    cup* cur = ptrs[cups[0]];
    for (int t = 0; t < 10000000; t++) {
        cup* pickup = cur->next;
        unordered_set<ull> s;
        cup* temp = pickup;

        for (int i = 0; i < 3; i++) {
            s.insert(temp->val);
            temp = temp->next;
        }
        cur->next = temp;

        ull dest = (cur->val == 1) ? cupCount : cur->val - 1;
        while (s.find(dest) != s.end())
            dest = (dest == 1) ? cupCount : dest - 1;

        cup* dc = ptrs[dest];
        cup* dcn = dc->next;
        dc->next = pickup;
        pickup->next->next->next = dcn;
        cur = cur->next;
    }

    return ptrs[1]->next->val * ptrs[1]->next->next->val;
}

int main() {
    cout << "File: ";
    string temp;
    cin >> temp;
    ifstream fin(temp, ios::in);

    while (!fin.eof()) {
        fin >> temp;
        for (char c : temp)
            cups.push_back(c - '0');
    }
    fin.close();

    cout << "part 1: " << part1() << endl;
    cout << "part 2: " << part2() << endl;

    return 0;
}