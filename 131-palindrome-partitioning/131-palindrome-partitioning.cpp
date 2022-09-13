class Solution {
public:
    bool isPalin(int start, string s, int end)
{
    while(start<end)
    {
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}
    void helper(int i, string &s, vector<string>&temp, vector<vector<string>>&ans)
{
    if(i==s.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int itr=i;itr<s.size();itr++)
    {
        if(isPalin(i,s,itr))
        {
            temp.push_back(s.substr(i,itr-i+1));
            helper(itr+1,s,temp,ans);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
    vector<string>temp;
    helper(0,s,temp,ans);
    return ans;
    }
};