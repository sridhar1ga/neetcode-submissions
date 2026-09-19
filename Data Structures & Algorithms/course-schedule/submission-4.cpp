class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if( prerequisites.size()==0) return true;
        vector<vector<int>> adj(numCourses+1, vector<int>());
        vector<int> infix(numCourses+1, 0);

        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            infix[prerequisites[i][0]]++;
        }

        vector<int> visited(numCourses+1, 0);

        queue<int> q;

        for(int i=0; i<=numCourses; i++)
        {
            if(infix[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            if(visited[curr]==1) continue;
            visited[curr]=1;
            for(int i=0; i<adj[curr].size(); i++)
            {
                int v = adj[curr][i];

                infix[v]--;
                if(infix[v]==0) q.push(v);
            }
        }

        for(int i=0; i<=numCourses; i++)
        {
            if(visited[i]!=1) return false;
        }

        return true;
    }
};
