//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string exp)
    {
        // Your code here
        stack<int>st;
    int mod=1e9+7;
    int res=0;
    for(int i=0;i<exp.size();i++){
        if((exp[i]=='+' ||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')&& exp[i]!=' '){
            char str=exp[i];
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
             if(exp[i] == ' '){
                    continue;
                }
            if(str=='+'){
                res=(a+b)%mod;
            }
            else if(str=='-'){
                res=(a-b)%mod;
            }
            else if(str=='*'){
                res=(a*b)%mod;
            } else if (str == '/') {
              res = (a / b) % mod;
            }
            st.push(res);
        }
         else if (exp[i]==' ') {
          continue;
          
        } else {
          st.push(exp[i] - '0');
        }
        
    }
    return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends