class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxm=INT_MIN;
        for(auto x:piles)
        {
            maxm=max(maxm,x);
        }
        int ans=0;
        int low=1;
        int high=maxm;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<piles.size();i++)
            {
                count+=ceil((double)piles[i]/mid);
            }
            if(count>h)
                low=mid+1;
            else
            {
                ans=mid;
                high=mid;
                if(low==high)
                    break;
            }
        }
        return ans;
    }
};