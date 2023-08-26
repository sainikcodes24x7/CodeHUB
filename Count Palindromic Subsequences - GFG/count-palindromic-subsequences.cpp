//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
           long long mod = 1e9+7;
        int n = str.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int cnt = 0;
        for(int g = 0 ; g<n; g++){
            for(int i = 0 ,j=g;j<n;j++,i++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    if(str[i]==str[j]){
                        dp[i][j] = 3;
                    }
                    else{
                        dp[i][j] = 2;
                    }
                }
                else{
                    if(str[i]==str[j]){
                        //prefix subsequence count + suffix sum count+1
                        
                        dp[i][j] = 1+dp[i+1][j]+dp[i][j-1];
                    }
                    
                    else{
                        //prefix subsequence count + suffix sum count- subsequence count of middle
                        dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                    }
                }
                dp[i][j]%=mod;
                
            }
        }
         if(dp[0][n-1]<0)return dp[0][n-1]+mod;
        else return dp[0][n-1]%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends