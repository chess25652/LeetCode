class Solution {
    bool rotIfPresent(vector<vector<int>>& grid, int row, int col, int minute, queue<vector<int>> &justRotten) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1)
            return false;
        else {
            grid[row][col] = 2;
            justRotten.push({row, col, minute});
            return true;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numFresh = 0;

        // Each vector [row, cell, minute] is an orange located at grid[row][cell] that has rotten at minute,
        // and has not yet passed the rottenness onto its neighbors.
        queue<vector<int>> justRotten;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == 1) {
                    ++numFresh;
                }
                else if (grid[row][col] == 2) {
                    justRotten.push({row, col, 0});
                }
            }
        }
        
        // Pass on rottenness until there are no fresh oranges, or there are no more newly rotten oranges.
        int curMinute = 0;
        while (!justRotten.empty()) {
            vector<int> rotten = justRotten.front();
            justRotten.pop();
            int row = rotten[0], col = rotten[1];
            curMinute = rotten[2];
            
            if (rotIfPresent(grid, row, col-1, curMinute+1, justRotten))
                --numFresh;
            if (rotIfPresent(grid, row, col+1, curMinute+1, justRotten))
                --numFresh;
            if (rotIfPresent(grid, row-1, col, curMinute+1, justRotten))
                --numFresh;
            if (rotIfPresent(grid, row+1, col, curMinute+1, justRotten))
                --numFresh;
        }
        
        if (numFresh > 0)
            return -1;
        
        return curMinute;
    }
};
