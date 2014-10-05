class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int sum = grid[0][0];
        for (int i = 1;i < grid.size();i++)
        {
            grid[i][0] = sum + grid[i][0];
            sum = grid[i][0];
        }
        sum = grid[0][0];
        for (int i = 1;i < grid[0].size();i++)
        {
            grid[0][i] = sum + grid[0][i];
            sum = grid[0][i];
        }
        
        for (int i = 1;i < grid.size();i++)
            for (int j = 1;j < grid[0].size();j++)
                grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j];
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
    int min(int a,int b)
    {
        return a < b ? a : b;
    }
};