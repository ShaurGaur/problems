#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

int findMinW(int &Ar, int &As, int &Ap, int &Br, int &Bs, int &Bp)
{
    vector<pair<int &, int &>> pairs = {{Ar, Br}, {As, Bs}, {Ap, Bp}, {Bs, Ap}, {Br, As}, {Bp, Ar}};
    int maxD = min(Ar, Br);
    vector<int> maxI = {0};

    for (int i = 1; i < 6; i++)
    {
        if (min(pairs[i].first, pairs[i].second) == maxD)
            maxI.push_back(i);
        if (min(pairs[i].first, pairs[i].second) > maxD)
            maxI = {i};
        maxD = max(maxD, min(pairs[i].first, pairs[i].second));
    }

    if (maxD == 0)
        return min(Ar, Bs) + min(As, Bp) + min(Ap, Br);

    int ans = INT_MAX;
    for (int i : maxI)
    {
        pairs[i].first -= maxD;
        pairs[i].second -= maxD;
        ans = min(ans, findMinW(Ar, As, Ap, Br, Bs, Bp));
        pairs[i].first += maxD;
        pairs[i].second += maxD;
    }

    return ans;
}

int main()
{
    int n, Ar, As, Ap, Br, Bs, Bp, maxW, minW, maxI, maxD = MOD;
    cin >> n >> Ar >> As >> Ap >> Br >> Bs >> Bp;
    maxW = min(Ar, Bs) + min(As, Bp) + min(Ap, Br);
    minW = findMinW(Ar, As, Ap, Br, Bs, Bp);
    cout << minW << " " << maxW << endl;
    return 0;
}