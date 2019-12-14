class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temps;
        int n = grid.size();
        int m = grid[0].size();

        if (k % (n * m) != 0) {
            k = k % (n * m);
            for (int i = 0; i < k; i++) {
                vector<int> g_pos = gridPos((n * m) - 1 - i, n, m);
                temps.push_back(grid[g_pos[0]][g_pos[1]]);
            }

            for (int i = (n * m) - 1; i >= k; i--) {
                vector<int> g_pos_i = gridPos(i, n, m);
                vector<int> g_pos_f = gridPos(i - k, n, m);
                grid[g_pos_i[0]][g_pos_i[1]] = grid[g_pos_f[0]][g_pos_f[1]];
            }

            for (int i = 0; i < k; i++) {
                vector<int> g_pos = gridPos(i, n, m);
                grid[g_pos[0]][g_pos[1]] = temps[k - 1 - i];
            }
        }
        
        return grid;
    }
    
    inline vector<int> gridPos(int p, int r, int c) {
        vector<int> pos (2, 0);
        pos[0] = p / c;
        pos[1] = p % c;
        return pos;
    }
};