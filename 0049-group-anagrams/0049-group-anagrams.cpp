class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto itr:strs)
        {
            string a=itr;
            sort(a.begin(),a.end());
            mp[a].push_back(itr);
        }
        vector<vector<string>>ans;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }
};