#define MOD 1000000007
#define ll long long
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll ans=0;
        unordered_map<ll,ll>mp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            int c=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j])
                    continue;
                int ans1=arr[i]/arr[j];
                int ans2=arr[j];
                c=(c+mp[ans1]*mp[ans2]%MOD)%MOD;
            }
            mp[arr[i]]=c;
            ans+=c;
        }
        return ans%MOD;
    }
};