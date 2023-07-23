//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // Your code here
       // we make an 2d vector of n*W
       vector<vector<int>>ans(n+1,vector<int>(W+1));
       
       // first row and colum with 0s
       for(int i=0;i<n+1;i++)
       {
           ans[i][0]=0;
       }
       for(int j=0;j<W+1;j++)
       {
           ans[0][j]=0;
       }
       
       for(int i=1;i<n+1;i++) //items
       {
           for(int j=1;j<W+1;j++) //weight
           {
               if(wt[i-1]<=j){
               
               //ans[i][j]=max(val[i-1]+ans[i-1][j-wt[i-1]],ans[i-1][j]);
               ans[i][j]=max(ans[i-1][j],val[i-1]+ans[i-1][j-wt[i-1]]);
                   
               }
               else{
                   
               ans[i][j]=ans[i-1][j];
               }
           }
       }
       return ans[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends