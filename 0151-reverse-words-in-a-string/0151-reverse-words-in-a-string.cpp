class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        s+="";
        string ans="";
        for(auto itr:s)
        {
            if (ans.length() > 0 && itr == ' ')
            {
                st.push(ans);
                ans="";
            }
            else if (itr!=' ')
            {
                ans+=itr;
               
            }
        }
                    if(ans!="")
                    st.push(ans);
                    ans = "";
                
        
        while(!st.empty())
        {
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};