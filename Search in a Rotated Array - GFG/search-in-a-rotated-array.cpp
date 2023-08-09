//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        int s=l,e=h;
        while(s<=e){
            int m=(s+e)/2;
            if(arr[m]==key){
                return m;
            }
            else if(arr[m]>=arr[s]){
                if(key>=arr[s] and key<arr[m]){
                    e=m-1;
                }
                else{
                    s=m+1;
                }
            }
            else{
                if(key>arr[m] and key<=arr[e]){
                    s=m+1;
                }
                else{
                    e=m-1;
                }
            }
        }
        return -1;
        //complete the function here
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends