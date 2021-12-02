#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    vector<int> L;
    vector<int> R;
    vector<char> C;
    vector<string> S;
    ifstream fin("input.txt", ios::in);

    while (!fin.eof())
    {
        string temp;
        fin >> temp;
        size_t dash = temp.find('-');
        L.push_back(stoi(temp.substr(0, dash)));
        R.push_back(stoi(temp.substr(dash + 1)));

        fin >> temp;
        C.push_back(temp[0]);
        fin >> temp;
        S.push_back(temp);
    }

    int n = L.size(), a = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (char c : S[i])
            if (c == C[i])
                count++;
        if (count >= L[i] && count <= R[i])
            a++;
    }

    cout << a << " ";

    a = 0;
    for (int i = 0; i < n; i++)
    {
        if (S[i].length() >= R[i] && ((S[i][L[i] - 1] == C[i]) != (S[i][R[i] - 1] == C[i])))
            a++;
        else if (S[i].length() < R[i] && S[i][L[i] - 1] == C[i])
            a++;
    }

    cout << a << endl;

    return 0;
}