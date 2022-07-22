class Solution {
public:
    void dfs(int i, string s, string digits, vector<string>&ans, vector<string>keypad)
    {
        if(s.size()==digits.size())
        {
            ans.push_back(s);
            return;
        }
        for(int j=0;j<keypad[digits[i]-'0'].size();j++)
        {
            s+=keypad[digits[i]-'0'][j];   
            dfs(i+1,s,digits,ans,keypad);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return {};
        vector<string>keypad={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
       string s;
        vector<string>ans;
        dfs(0,s,digits,ans,keypad);
        return ans;
    }
};