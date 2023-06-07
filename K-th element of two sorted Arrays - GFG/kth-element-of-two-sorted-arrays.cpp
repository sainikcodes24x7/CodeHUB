//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0,p=0;
        int ans[n+m+1];
        while(i<n and j<m)
        {
            if(arr1[i]<arr2[j])
            {
                ans[p++]=arr1[i++];
            }
            else if(arr1[i]>arr2[j])
            {
                 ans[p++]=arr2[j++];
            }
            else
            {
                 ans[p++]=arr1[i++];
                 ans[p++]=arr2[j++];
            }
        }
        while(i<n)
        {
            ans[p++]=arr1[i++];
        }
        while(j<m)
        {
            ans[p++]=arr2[j++];
        }
        return ans[k-1];
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends