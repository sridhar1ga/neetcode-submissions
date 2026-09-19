class Solution {
public:
    string encode(vector<string>& strs) {
        string ans="";
        for(auto str : strs )
        {
            int tmp = str.size();
            ans += to_string(tmp)+"#" + str;
        }
        // cout << ans << endl;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int l=0;
        int r=0;
        while(l<s.size())
        {
            r=l;
            while(s[r]!='#') r++;
            // cout << s.substr(l, r-l+1) << " ";
            int size = stoi(s.substr(l, r-l+1));
            // cout << size << endl;
            l = r+1;
            ans.push_back(s.substr(l, size));
            l += size;
        }
        return ans;
    }
};
