class Solution {
public:

    int find_parent(int u, vector<int>& parent)
    {
        if(u==parent[u]) return u;

        return parent[u]=find_parent(parent[u], parent);
    }

    bool add_edge(int u, int v, vector<int>& parent)
    {
        int parent_u = find_parent(u, parent);
        int parent_v = find_parent(v, parent);

        if(parent_u!=parent_v)
        {
            if(parent_u<parent_v)
            {
                parent[parent_v] = parent_u;
            }
            else
            {
                parent[parent_u] = parent_v;
            }

            return true;
        }

        return false;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i=0; i<n; i++) parent[i] = i;
        int ans = n;
        for(int i=0; i<edges.size(); i++)
        {
            if(add_edge(edges[i][0], edges[i][1], parent)) ans--;
        }
        return ans;
    }
};
