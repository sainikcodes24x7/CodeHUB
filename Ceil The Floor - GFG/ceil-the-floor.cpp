//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int floor=-1, ceil=-1;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=x){
            floor=max(floor,arr[i]);
        }
        if(arr[i]>=x){
            if(ceil==-1)
                ceil=arr[i];
            else
                ceil=min(ceil,arr[i]);
        }
    }
    return {floor,ceil};
}