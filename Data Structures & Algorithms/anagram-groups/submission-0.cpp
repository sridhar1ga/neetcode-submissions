class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> lookup;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++)
        {
            string orig = strs[i];
            sort(orig.begin(), orig.end());
            lookup[orig].push_back(strs[i]);
        }

        for(auto paire : lookup)
        {
            ans.push_back(paire.second);
        }

        return ans;
    }
};
