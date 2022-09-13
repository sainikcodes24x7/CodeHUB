class Solution {
public:
    bool isPalin(int start, int end, string s)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void helper(int index, vector<string>&temp, string &s, vector<vector<string>>&ans)
    {
        if(index==s.size())
        {
            ans.push_back(temp);
            return;
        }  
        for(int i=index;i<s.size();i++)
        {
            if(isPalin(index,i,s))
            {
                temp.push_back(s.substr(index,i-index+1));
                helper(i+1,temp,s,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>>ans;
        vector<string>temp;
        helper(0,temp,s,ans);
        return ans;
    }
};