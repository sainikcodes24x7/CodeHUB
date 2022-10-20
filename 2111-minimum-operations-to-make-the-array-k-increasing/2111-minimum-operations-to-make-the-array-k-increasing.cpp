class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
        int s=0;
        for(int i=0;i<k;i++)
        {
            vector<int>ans;
            for(int j=i;j<n;j+=k)
            {
                if(ans.empty() || ans.back()<=arr[j])
                {
                    ans.push_back(arr[j]);
                }
                else
                {
                    int idx=upper_bound(ans.begin(),ans.end(),arr[j])-ans.begin();
                    ans[idx]=arr[j];
                }
            }
            s+=ans.size();
        }
        return arr.size()-s;
    }
};