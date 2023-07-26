//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool solve(int mid, int arr[], int n, int k){
        int painter=1;
        int curBooks=0;
        for(int i=0;i<n;i++){
            if(curBooks+arr[i]<=mid){
                curBooks+=arr[i];
            }
            else{
                painter++;
                curBooks=arr[i];
            }
        }
        if(painter<=k){
            return true;
        }
        return false;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        
        long long s=maxi;
        long long e=sum;
        
        long long ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(solve(mid,arr,n,k)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends