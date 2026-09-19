class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order = {};
        vector<int> indegree(numCourses, 0);
        vector<bool> visited(numCourses, false);

        vector<vector<int>> adj(numCourses, vector<int>());
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int u = q.front(); q.pop();
            if(visited[u]) continue;
            visited[u] = true;
            order.push_back(u);

            for(int i=0; i<adj[u].size(); i++)
            {
                int v = adj[u][i];
                indegree[v]--;
                if(indegree[v]==0 and !visited[v]) q.push(v);
            }
        }

        if(order.size()==numCourses) return order;

        return {};
    }
};
