//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<long long> distributeCandies(int n, int k) {
        // code here
        vector<long long>v(k,0);
        int idx=0,cnt=1;
        while(n){
            v[idx++]+=cnt;
            n-=cnt;
            cnt++;
            if(idx==k){
                idx=0;
            }
            if(cnt>n){
                cnt=n; //remaining candies to the last person
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends