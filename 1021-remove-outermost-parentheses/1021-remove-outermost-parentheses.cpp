class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans="";
        for(auto itr:s)
        {
            if(itr=='(')
            {
                if(st.size()>0)
                    ans+='(';
                st.push('(');
            }
            else
            {
                if(st.size()>1)
                    ans+=')';
                st.pop();
            }
        }
        return ans;
    }
};