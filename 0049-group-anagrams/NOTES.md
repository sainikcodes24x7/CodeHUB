class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
map<string,vector<string>>mp;
for(string s:strs)
{
// we iterate over each string and sort it
string a=s;
sort(a.begin(),a.end());
// we push it back to the map
mp[a].push_back(s);
}
vector<vector<string>>ans;
for(auto i=mp.begin();i!=mp.end();i++)
{
// inside 2d vector we push 1d vec
ans.push_back(i->second);
}
return ans;
}
};