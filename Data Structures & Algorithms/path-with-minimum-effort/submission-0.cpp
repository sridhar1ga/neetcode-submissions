class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<int> rdirs = {0, 0, 1, -1};
        vector<int> cdirs = {1, -1, 0, 0};

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<>> pq;

        pq.push({0, 0, 0});

        

        while(!pq.empty())
        {
            auto [eff, r, c] = pq.top(); pq.pop();
            if(visited[r][c]) continue;
            visited[r][c] = true;

            if(r==rows-1 and c==cols-1) return eff;

            for(int i=0; i<4; i++)
            {
                int nr = r + rdirs[i];
                int nc = c + cdirs[i];

                if(nr>=0 and nc>=0 and nr<rows and nc<cols and !visited[nr][nc])
                {
                    int n_eff = max(eff, abs(heights[r][c]-heights[nr][nc]));
                    pq.push({n_eff ,nr, nc});
                }
            }
        }

        return -1;
    }
};