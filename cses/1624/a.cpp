#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

bool check(vector<string> &board, int row, int col)
{
    if (board[row][col] == '*')
        return false;
    for (int d = 1; d <= col; d++)
        if (board[row][col - d] == 'Q')
            return false;
    for (int x = 1; row - x >= 0 && col - x >= 0; x++)
        if (board[row - x][col - x] == 'Q')
            return false;
    for (int x = 1; row + x < 8 && col - x >= 0; x++)
        if (board[row + x][col - x] == 'Q')
            return false;
    return true;
}

void backtrack(ull &ans, vector<string> &board, int col)
{
    if (col == 8)
    {
        ans++;
        return;
    }

    for (int row = 0; row < 8; row++)
        if (check(board, row, col))
        {
            board[row][col] = 'Q';
            backtrack(ans, board, col + 1);
            board[row][col] = '.';
        }
}

int main()
{
    ull ans = 0;
    vector<string> board(8, "");
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    backtrack(ans, board, 0);
    cout << ans << endl;
    return 0;
}