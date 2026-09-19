class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, vector<int>& visited, int u, int parent)
    {
        if(visited[u]>0) return false;
        visited[u] = 1;
        for(int v: adj[u])
        {
            if(v==parent) continue;
            if(visited[v]==1) return true;
            else if(visited[v]==0 and hasCycle(adj, visited, v, u)) return true;
        }
        visited[u] = 2;
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for(vector<int> edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int components = 0;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                // cout << i << " " << hasCycle(adj, visited, i, -1) << endl;
                if(hasCycle(adj, visited, i, -1)) return false;
                components++;
            }
        }

        if(components>1) return false;
        return true;
    }
};
