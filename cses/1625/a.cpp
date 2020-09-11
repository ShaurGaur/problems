#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

unordered_map<char, pair<int, int>> dir;
vector<vector<bool>> visited;
string input;
ull ans;

void dfs(char last, int row, int col, int idx, int left)
{
    if (idx == 48 && visited[6][0])
    {
        ans++;
        return;
    }

    else if (idx == 48 || visited[6][0])
        return;

    if (last == 'L' && (col == 0 || visited[row][col - 1]) && row > 0 && row < 6 && !visited[row - 1][col] && !visited[row + 1][col])
        return;
    if (last == 'R' && (col == 6 || visited[row][col + 1]) && row > 0 && row < 6 && !visited[row - 1][col] && !visited[row + 1][col])
        return;
    if (last == 'U' && (row == 0 || visited[row - 1][col]) && col > 0 && col < 6 && !visited[row][col - 1] && !visited[row][col + 1])
        return;
    if (last == 'D' && (row == 6 || visited[row + 1][col]) && col > 0 && col < 6 && !visited[row][col - 1] && !visited[row][col + 1])
        return;

    if (input[idx] == '?')
        for (auto it = dir.begin(); it != dir.end(); ++it)
        {
            char c = it->first;
            int newRow = row + it->second.first;
            int newCol = col + it->second.second;
            if (newRow < 0 || newRow > 6 || newCol < 0 || newCol > 6 || visited[newRow][newCol])
                continue;
            visited[newRow][newCol] = true;
            dfs(c, newRow, newCol, idx + 1, left);
            visited[newRow][newCol] = false;
        }
    else
    {
        char c = input[idx];
        int newRow = row + dir[c].first;
        int newCol = col + dir[c].second;
        if (newRow < 0 || newRow > 6 || newCol < 0 || newCol > 6 || visited[newRow][newCol])
            return;
        visited[newRow][newCol] = true;
        dfs(c, newRow, newCol, idx + 1, left);
        visited[newRow][newCol] = false;
    }

    return;
}

int main()
{
    ans = 0;
    int left = 0;

    cin >> input;

    for (char c : input)
        if (c != '?')
            left++;

    dir['D'] = {1, 0};
    dir['U'] = {-1, 0};
    dir['L'] = {0, -1};
    dir['R'] = {0, 1};

    visited = vector<vector<bool>>(7, vector<bool>(7, false));
    visited[0][0] = true;

    dfs('0', 0, 0, 0, left);
    cout << ans << endl;
    return 0;
}