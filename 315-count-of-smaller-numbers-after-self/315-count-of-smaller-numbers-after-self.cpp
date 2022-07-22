class Solution {
public:
    vector<int>ans;
    void merge(vector<pair<int,int>>&temp,int l, int m, int r)
    {
        int lsize=m-l+1;
        int rsize=r-m;
        vector<pair<int,int>>leftarr;
        vector<pair<int,int>>rightarr;
        
        for(int i=l;i<=m;i++)
        {
            leftarr.push_back(temp[i]);
        }
        for(int i=m+1;i<=r;i++)
        {
            rightarr.push_back(temp[i]);
        }
        int k=l;
        int i=0,j=0;
        int count=0;
        while(i<leftarr.size())
        {
            while(j<rightarr.size() and rightarr[j].first<leftarr[i].first)
            {
                temp[k]=rightarr[j];
                k++;
                j++;
                count++;
            }
            ans[leftarr[i].second]+=count;
            temp[k]=leftarr[i];
            i++;
            k++;
        }
        return;
    }
    void mergesort(vector<pair<int,int>>&temp, int start, int end)
    {
        if(start>=end)
            return;
        int mid=(start+end)/2;
        mergesort(temp,start,mid);
        mergesort(temp,mid+1,end);
        merge(temp,start,mid,end);
        
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        ans.resize(nums.size(),0);
        vector<pair<int,int>>temp;
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back({nums[i],i});
        }
        mergesort(temp,0,nums.size()-1);
        return ans;
    }
};