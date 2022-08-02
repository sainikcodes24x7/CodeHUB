class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int ans=0;
        int n=fruits.size();
        unordered_map<int,int>mp;
        for(j=0;j<n;j++)
        {
            mp[fruits[j]]++;
            
            while(mp.size()>2){
                mp[fruits[i]]--;
            if(mp[fruits[i]]==0)
                mp.erase(fruits[i]);
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};