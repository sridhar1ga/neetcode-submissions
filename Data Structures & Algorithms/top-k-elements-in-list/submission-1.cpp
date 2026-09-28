class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> lookup;
        int it=0;
        for(pair<int,int> p: freq)
        {
            if(it<k) lookup.push({p.second, p.first});
            else{
                pair<int, int> top = lookup.top();
                if(top.first<p.second)
                {
                    lookup.pop();
                    lookup.push({p.second, p.first});
                }
            }
            it++;
        }
        vector<int> ans;
        while(!lookup.empty())
        {
            pair<int, int> top = lookup.top();
            ans.push_back(top.second);
            lookup.pop();
        }
        return ans;
    }
};
