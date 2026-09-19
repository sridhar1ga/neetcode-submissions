class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& visited)
    {
        visited[u] = 1;
        bool has_cycle = false;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(visited[v]==1) has_cycle = true;
            if(visited[v]==0) has_cycle = has_cycle || dfs(v, adj, visited);
        }

        visited[u] = 2;

        return has_cycle;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if( prerequisites.size()==0) return true;
        vector<vector<int>> adj(numCourses+1, vector<int>());

        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses+1, 0);

        for(int i=0; i<=numCourses; i++)
        {
            if(visited[i]==0){
                if(dfs(i, adj, visited)) return false;
            }
        }

        for(int i=0; i<visited.size(); i++)
        {
            if(visited[i]!=2) return false;
        }

        return true;
    }
};
