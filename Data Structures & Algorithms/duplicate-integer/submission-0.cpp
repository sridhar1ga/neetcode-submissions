class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> lookup;

        for(int i=0; i<nums.size(); i++)
        {
            if(lookup.find(nums[i])!=lookup.end()) return true;

            lookup.insert(nums[i]);
        }

        return false;
    }
};