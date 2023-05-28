//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod=1e9+7;
	public:
	int solve(int arr[],int n, int sum, vector<vector<int>>&dp)
	{
	    if(n<=0)
	        return sum==0;
	    if(dp[n-1][sum]!=-1)
	        return dp[n-1][sum];
	    int ans=solve(arr,n-1,sum,dp)%mod;    
	    if(arr[n-1]<=sum)
	    {
	        //int ans=(solve(arr,n-1,sum-arr[n-1],dp)%mod || solve(arr,n-1,sum,dp)%mod);
	        ans+=solve(arr,n-1,sum-arr[n-1],dp)%mod;
	        return dp[n-1][sum]=ans%mod;
	    }
	    //else{
	        //int ans=solve(arr,n-1,sum,dp)%mod;
	        return dp[n-1][sum]=ans%mod;
	    //}

	         
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends