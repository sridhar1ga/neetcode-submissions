class Solution {
public:
    int findParent(int u, vector<int>& parent)
    {
        if(parent[u]==u) return u;

        return parent[u] = findParent(parent[u], parent);
    }

    bool merge(int u, int v, vector<int>& parent)
    {
        int parent_u = findParent(u, parent);
        int parent_v = findParent(v, parent);

        if(parent_u==parent_v) return true;
        else{
            if(parent_u<parent_v)
            {
                parent[parent_v] = parent_u;
            }
            else
            {
                parent[parent_u] = parent_v;
            }
        }

        return false;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()<n-1) return false;

        vector<int> parent(n);
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<edges.size(); i++)
        {
            if(merge(edges[i][0], edges[i][1], parent)) return false;
        }

        return true;
    }
};
