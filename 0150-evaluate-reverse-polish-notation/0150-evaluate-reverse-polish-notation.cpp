class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>st;
        int ans;
      for(int i=0;i<tokens.size();i++){  
        if(tokens[i]!="+" and tokens[i]!="-" and tokens[i]!="*" and tokens[i]!="/" )
        {
            int e=stoi(tokens[i]);
            st.push(e);
        }
        else
        {
            long long int a=st.top();
            st.pop();
            long long int b=st.top();
            st.pop();
            if(tokens[i]=="+")
            {
                ans=a+b;
                st.push(ans);
            }
              if(tokens[i]=="-")
            {
                ans=b-a;
                st.push(ans);
            }
              if(tokens[i]=="*")
            {
                ans=a*b;
                st.push(ans);
            }
              if(tokens[i]=="/")
            {
                ans=b/a;
                st.push(ans);
            }
        }
      }
        ans=st.top();
        st.pop();
        return ans;
    }
};