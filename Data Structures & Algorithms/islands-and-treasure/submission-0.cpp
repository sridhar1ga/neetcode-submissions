class Solution {
public:
    void traverse(vector<vector<int>>& grid, int i, int j, int dist)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]<1) return;

        if(grid[i][j]>dist)
        {
            grid[i][j] = dist;
            traverse(grid, i+1, j, dist+1);
            traverse(grid, i-1, j, dist+1);
            traverse(grid, i, j+1, dist+1);
            traverse(grid, i, j-1, dist+1);
        }

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==0)
                {
                    traverse(grid, i+1, j, 1);
                    traverse(grid, i-1, j, 1);
                    traverse(grid, i, j+1, 1);
                    traverse(grid, i, j-1, 1);
                }
            }
        }
    }
};
