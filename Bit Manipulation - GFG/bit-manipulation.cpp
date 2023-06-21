//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int get=0, set=0, clear=0;
        int mask= (1<<(i-1));
        if(num & mask){
            get=1;
        }
        set= (num|mask);
        clear= (num & (~mask));
        cout<<get<<" "<<set<<" "<<clear;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends