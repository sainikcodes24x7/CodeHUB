//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[101][10001];
    bool helper(vector<int>& arr,int sum, int n)
    {
        if(sum==0)
            return true;
        if(n<=0)
            return false;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        else{
            if(arr[n-1]<=sum)
        {
            return dp[n][sum]= helper(arr,sum-arr[n-1],n-1) || helper(arr,sum,n-1);
        }
        else
        {
            return dp[n][sum]=helper(arr,sum,n-1);   
        }
        }    
        
            
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        //vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        memset(dp,-1,sizeof(dp));
        return helper(arr,sum,n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends