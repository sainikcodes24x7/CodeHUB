class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
         long totalsum = 0, currentsum = 0;
        int n = nums.size();
        
        // calc totalsum
        for(auto i : nums)
            totalsum += i;
        
        int mini = INT_MAX;
        int indexans = 0;
        
        // calc the avg1 till ith index and avg2 till n-1-ith index
        // now take absolute diff btw avg1 and avg2 and keep tracking the index giving minimum diff
        // return the index giving minimum diff
        for(int i=0; i<n; i++)
        {
            currentsum += nums[i];
            int avg1 = currentsum/(i+1);
            if(i==n-1)
            {
                if(avg1<mini)
                    return n-1;
                else
                    break;
            }
            int avg2 = (totalsum - currentsum)/(n-i-1);
            
            if(abs(avg1-avg2)<mini)
            {
                mini = abs(avg1-avg2);
                indexans = i;
            }
        }
        
        return indexans;
    }
};