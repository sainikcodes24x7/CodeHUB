class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2!=0)
            {
                nums[i]*=2;
            }
                st.insert(nums[i]);
            
        }
        
        int mndiff=*st.rbegin()-*st.begin();
        while(*st.rbegin()%2==0)
        {
            int temp=*st.rbegin();
            st.erase(temp);
            temp/=2;
            st.insert(temp);
            mndiff=min(mndiff,*st.rbegin()-*st.begin());
        }
        return mndiff;
    }
};