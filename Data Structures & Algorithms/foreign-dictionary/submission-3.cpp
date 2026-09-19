class Solution {
public:
    void getEdge(string a, string b, vector<vector<int>>& adj, vector<int>& in)
    {
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26, vector<int>());
        vector<int> in(26, -1);
        int vocabSize=0;
        for(auto word: words)
        {
            for(auto ch: word) {
                if(in[ch-'a']==-1) vocabSize++;
                in[ch-'a'] = 0;
            }
        }
        for(int i=1; i<words.size(); i++)
        {
            string a = words[i-1];
            string b = words[i];
            int it=0;
            int n=min(a.size(), b.size());
            while(it<n and a[it]==b[it]) it++;

            if(it==n)
            {
                if(a.size()>b.size()) return "";
                else continue;
            }
            int first = a[it]-'a';
            int second = b[it]-'a';
            adj[first].push_back(second);

            in[second]++;
        }
        string ans="";
        queue<int> q;
        for(int i=0; i<26; i++)
        {
            if(in[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            ans += 'a' + curr;
            for(int j: adj[curr])
            {
                in[j]--;
                if(in[j]==0) q.push(j);
            }
        }

        return ans.size()==vocabSize ? ans: "";
    }
};
