class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prodbefore(n, 1);
        vector<int> prodAfter(n,1);

        for(int i=1; i<n; i++)
        {
            prodbefore[i] = prodbefore[i-1]*nums[i-1];
        }

        for(int i=n-2; i>=0; i--)
        {
            prodAfter[i] = prodAfter[i+1]*nums[i+1];
        }

        for(int i=0; i<n; i++)
        {
            nums[i] = prodbefore[i] * prodAfter[i];
        }

        return nums;
    }
};
