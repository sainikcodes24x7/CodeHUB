//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        // Code here
        stack<int>st;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(st.empty() || st.top()<=arr[i]){
                ans.push_back(arr[i]);
                st.push(arr[i]);
            }
            //st.push(i);
        }
            /*while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            */
            reverse(ans.begin(),ans.end());
            return ans;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends