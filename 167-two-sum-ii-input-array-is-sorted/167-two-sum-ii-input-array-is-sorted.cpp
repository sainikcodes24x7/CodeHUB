class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<numbers.size();i++)
        {
            if(mp.find(target-numbers[i])!=mp.end())
            {
                ans.push_back(mp[target-numbers[i]]+1);
                ans.push_back(i+1);
            }
            mp[numbers[i]]=i;
        }
        return ans;
    }
};