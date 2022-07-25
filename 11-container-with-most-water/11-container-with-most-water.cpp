class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,high=height.size()-1,n=height.size(),ans=0;
        while(low<high)
        {
             int minheight=min(height[high],height[low]);
            int diff=high-low;
            int area=minheight*diff;
            ans=max(ans,area);
            
            if(height[low]>height[high])
                high--;
            else
                low++;
        }
        return ans;
    }
};