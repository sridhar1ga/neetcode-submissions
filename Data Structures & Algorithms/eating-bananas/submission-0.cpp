class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_element = INT_MIN;
        for(int i=0; i<piles.size(); i++)
        {
            max_element = max(max_element, piles[i]);
        }

        int l = 1, r = max_element, m;
        int time = 0;
        int ans = INT_MAX;
        while(l<=r)
        {
            m = (l+r)/2;
            // cout << m << endl;
            time = 0;   
            for(int i=0; i<piles.size(); i++)
            {
                time += piles[i]/m + (piles[i]%m ? 1 : 0);
            }

            if(time<=h)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};
