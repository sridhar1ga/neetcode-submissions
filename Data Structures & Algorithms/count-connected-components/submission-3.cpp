class Solution {
public:

    void dfs(vector<vector<int>>& adj, int curr, vector<int>& vis)
    {
        vis[curr] = 1;

        for(int i=0; i<adj[curr].size(); i++)
        {
            if(vis[adj[curr][i]]==0) dfs(adj, adj[curr][i], vis);
        }

        vis[curr] = 2;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n, 0);
        int cc=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]){
                dfs(adj, i, vis); 
                cc++;
            }
        }

        return cc;
    }
};
