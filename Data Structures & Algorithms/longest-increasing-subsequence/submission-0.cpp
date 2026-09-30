class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> dp(arr.size(), 1);
        int ans = 1;

        for(int i=1; i<arr.size(); i++)
        {
            for(int j=i; j>=0; j--)
            {
                if(arr[j]<arr[i] and dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
