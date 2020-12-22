#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

queue<ull> p1;
queue<ull> p2;
set<pair<queue<ull>, queue<ull>>> rounds;

ull detScore(queue<ull> q) {
    ull sum = 0;
    while (!q.empty()) {
        sum += (q.size() * q.front());
        q.pop();
    }
    return sum;
}

ull part1() {
    queue<ull> t1 = p1;
    queue<ull> t2 = p2;
    while (!t1.empty() && !t2.empty()) {
        ull x1 = t1.front(), x2 = t2.front();
        t1.pop(); t2.pop();
        if (x1 > x2) {
            t1.push(x1);
            t1.push(x2);
        }
        else if (x2 > x1) {
            t2.push(x2);
            t2.push(x1);
        }
    }

    queue<ull> q;
    if (!t1.empty()) q = t1;
    else q = t2;

    return detScore(q);
}

ull war(queue<ull>& q1, queue<ull>& q2) {
    set<pair<queue<ull>, queue<ull>>> rounds;
    while (!q1.empty() && !q2.empty()) {
        if (rounds.find({q1, q2}) != rounds.end()) return 1;
        queue<ull> t1 = q1;
        queue<ull> t2 = q2;
        rounds.insert({t1, t2});

        ull x1 = q1.front(), x2 = q2.front(), w;
        q1.pop(); q2.pop();
        if (q1.size() >= x1 && q2.size() >= x2) {
            queue<ull> r1, r2, m1 = q1, m2 = q2;
            for (int i = 0; i < x1; i++) {
                r1.push(m1.front());
                m1.pop();
            }
            for (int i = 0; i < x2; i++) {
                r2.push(m2.front());
                m2.pop();
            }
            w = war(r1, r2);
        }
        else w = (x2 > x1) + 1;

        if (w == 1) {
            q1.push(x1);
            q1.push(x2);
        }
        else {
            q2.push(x2);
            q2.push(x1);
        }
    }

    if (q1.empty()) return 2;
    else return 1;
}

ull part2() {
    queue<ull> t1 = p1;
    queue<ull> t2 = p2;
    ull w = war(t1, t2);

    queue<ull> q;
    if (w == 1) q = t1;
    else q = t2;

    return detScore(q);
}

int main() {
    string temp;
    cin >> temp;
    ifstream fin(temp, ios::in);

    int player = 0;

    while (!fin.eof()) {
        fin >> temp;
        if (temp[0] == 'P') {
            player++;
            fin >> temp >> temp;
        }
        ull x = stoll(temp, nullptr, 10);
        if (player == 1)
            p1.push(x);
        else if (player == 2)
            p2.push(x);
    }
    fin.close();

    cout << "part 1: " << part1() << endl;
    cout << "part 2: " << part2() << endl;

    return 0;
}