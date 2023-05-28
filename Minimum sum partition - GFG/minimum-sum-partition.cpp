//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	    //int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<=sum;i++)
        {
            dp[0][i]=false;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        vector<int>v;
        //
        for(int j=0;j<=sum;j++)
        {
            if(dp[n][j]==true){
                v.push_back(j);
            }
        }
        int diff=INT_MAX;
        for(int j=0;j<=v.size()/2;j++)
        {
            diff=min(diff,abs(sum-2*v[j]));
        }
        
        return diff;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends