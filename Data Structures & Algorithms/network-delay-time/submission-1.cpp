class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
        for(int i=0; i<times.size(); i++)
        {
            int u = times[i][0]-1;
            int v = times[i][1]-1;
            int t = times[i][2];
            adj[u].push_back({v,t});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> shortest(n, INT_MAX);

        pq.push({0, k-1});
        shortest[k-1] = 0;

        while(!pq.empty())
        {
            auto [dist, curr] = pq.top(); pq.pop();

            for(int i=0; i<adj[curr].size(); i++)
            {
                int v = adj[curr][i].first;
                int t = adj[curr][i].second;

                if(shortest[v]>shortest[curr]+t)
                {
                    shortest[v] = shortest[curr]+t;
                    pq.push({shortest[v], v});
                }
            }
        }
        int ans = 0;
        for(int i=0; i<shortest.size(); i++)
        {
            ans = max(ans, shortest[i]);
        }

        return ans==INT_MAX ? -1 : ans;
    }
};
