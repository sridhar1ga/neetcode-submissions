class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1) return -1;
        if(grid[n-1][n-1]==1) return -1;

        vector<vector<int>> shortest(n, vector<int>(n,-1));
        shortest[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty())
        {
            auto curr = q.front(); q.pop();


            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    int x = curr.first + i;
                    int y = curr.second + j;
                    if(x>=0 and x<n and y>=0 and y<n and grid[x][y]!=1 and shortest[x][y]==-1)
                    {
                    // cout << x << " " << y << endl;
                        shortest[x][y] = shortest[curr.first][curr.second] + 1;
                        q.push({x,y});
                        if(x==n-1 and y==n-1) return shortest[x][y];
                    }  
                }
            }

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cout << shortest[i][j] << " ";
                }
                cout << endl;
            }
        }

        return shortest[n-1][n-1];
    }
};