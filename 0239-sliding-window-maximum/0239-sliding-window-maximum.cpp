class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        
        for(int i=k;i<nums.size();i++)
        {
            pq.push({nums[i],i});
            
            if(pq.top().second<=(i-k))
            {
                while(pq.top().second<=(i-k))
                {
                    pq.pop();
                } 
            }
            ans.push_back(pq.top().first);
        }
        return ans;
        
      /*  int n=nums.size();
        vector<int>ans;
        int j=k-1;
        int i=0;
        while(j<n)
        {
            int maxm=INT_MIN;
            for(int k=i;k<=j;k++)
            {
                maxm=max(maxm,nums[k]);
            }
            ans.push_back(maxm);
            i++;
            j++;
        }
        return ans;
 */
    }
};