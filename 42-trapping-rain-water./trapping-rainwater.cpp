class Solution {
public:
    int trap(vector<int>& heights) {
         int l=0;
        int r=heights.size()-1;
        int maxl=0;
        int maxr=0;
        int res=0;
        while(l<=r)
        {
            if(heights[l]<=heights[r])
            {
                if(heights[l]>maxl)
                    maxl=heights[l];
                else
                    res+=(maxl-heights[l]);
                l++;
            }
            else
            {
                if(heights[r]>maxr)
                    maxr=heights[r];
                else
                    res+=(maxr-heights[r]); 
                r--;
            }
        }
        return res;
    }
};
