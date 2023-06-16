// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int memo(int coins[], int M, int V, vector<int>&dp)
	{
	    if(V==0)
	    return 0;
	    
	    if(V<0)
	    return INT_MAX;
	    
	    if(dp[V]!=-1)
	    return dp[V];
	    
	    int mini=INT_MAX;
	    for(int i=0;i<M;i++)
	    {
	        int ans=memo(coins,M,V-coins[i],dp);
	        if(ans!=INT_MAX){
	            mini=min(mini,1+ans);
	        }
	    }
	    dp[V]=mini;
	    return dp[V];
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<int>dp(V+1,-1);
	    int ans=memo(coins,M,V,dp);
	    if(ans==INT_MAX)
	    return -1;
	    else
	    return ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends