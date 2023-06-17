//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int,int>mp;
        int i=0,j=0;
        int res=0,sum=0;
        while(j<n){
            sum+=arr[j];
            if(sum==k){
                res=max(res,j-i+1);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=j;
            }
            if(mp.find(sum-k)!=mp.end()){
                res=max(res,j-mp[sum-k]);
            }
            j++;
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends