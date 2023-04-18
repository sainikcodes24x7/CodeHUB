class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            // if(s[0]==']' || s[0]=='}' || s[0]==')')
            // return false;
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]==']' && st.size()!=0)
            {
                if(st.top()!='[')
                return false;
                else
                st.pop();
            }
             else if(s[i]=='}'  && st.size()!=0)
            {
                if(st.top()!='{')
                return false;
                else
                st.pop();
            }
             else if(s[i]==')'  && st.size()!=0)
            {
                if(st.top()!='(')
                return false;
                else
                st.pop();
            }
            else
            return false;
            
        }
        if(st.size()==0)
        return true;
        else
        return false;
    }
};