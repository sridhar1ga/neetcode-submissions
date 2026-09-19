class Solution {
public:
    int find_parent(int x, vector<int>& connection)
    {
        if(x==connection[x])
        {
            return x;
        }
        return connection[x] = find_parent(connection[x], connection);
    }
    bool addEdge(vector<int>& connection, int x, int y)
    {
        int parent_x = find_parent(x, connection);
        int parent_y = find_parent(y, connection);

        if(parent_x!=parent_y)
        {
            if(parent_x<parent_y)
            {
                connection[parent_y] = parent_x;
            }
            else
            {
                connection[parent_x] = parent_y;
            }
            return true;
        }

        return false;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> connection(n,0);
        int ans = n;
        for(int i=0; i<n; i++)
        {
            connection[i] = i;
        }

        for(auto edge: edges)
        {
            if(addEdge(connection, edge[0], edge[1])) ans--;
        }

        return ans;
    }
};
