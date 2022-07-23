class Solution {
public:
    void generate(int op,int cl,string s,int n, vector<string>&ans)
    {
        if(op>n || cl>n || op<cl)
            return;
        if(op==n and cl==n)
            ans.push_back(s);
        generate(op+1,cl,s+"(",n,ans);
        if(op>cl)
        {
            generate(op,cl+1,s+")",n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        generate(0,0,s,n,ans);
        return ans;
    }
};