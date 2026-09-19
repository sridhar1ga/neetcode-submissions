class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int parent, int u)
    {
        // if(!vis[u]) return;

        vis[u] = true;
        for(auto v: adj[u])
        {
            if(v!=parent and !vis[v]) dfs(adj, vis, u, v);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int comps=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) 
            {
                vis[i] = true;
                dfs(adj, vis, -1, i);
                comps++;
            }
        }
        return comps;
    }
};
