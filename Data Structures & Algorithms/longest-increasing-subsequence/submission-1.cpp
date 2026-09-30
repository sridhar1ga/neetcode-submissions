class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> lis;
        int ans = 1;
        for(int i=0; i<arr.size(); i++)
        {
            if(lis.empty() or lis.back()<arr[i]) lis.push_back(arr[i]);
            else
            {
                int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
                lis[pos] = arr[i];
            }
        }

        return lis.size();
    }
};
