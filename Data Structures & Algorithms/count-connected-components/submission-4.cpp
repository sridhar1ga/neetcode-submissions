class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        vector<int> vis(n, false);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) {
                q.push(i);
                ans++;
                while(!q.empty())
                {
                    int p = q.front(); q.pop();
                    if(vis[p]) continue;
                    vis[p] = true;
                    for(int j=0; j<adj[p].size(); j++)
                    {
                        if(!vis[adj[p][j]]) q.push(adj[p][j]);
                    }
                }
            }
        }

        return ans;
    }
};
