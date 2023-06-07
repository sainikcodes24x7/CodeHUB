//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
#define lli long long int
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        lli s=1;
        lli e=x;
        lli m=(s+e)/2;
        lli ans;
        
        while(s<=e){
            lli sq=m*m;
            if(sq==x)
            return m;
            else if(sq<x)
            {
                ans=m;
                s=m+1;
            }
            else{
                e=m-1;
            }
            m=(s+e)/2;
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends