//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int parti(int arr[], int l, int r){
        int piv=arr[r];
        int i=l,j=l;
        while(j<r){
            if(arr[j]<piv){
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
        swap(arr[i],arr[r]);
        return i;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        while(1){
            int piv=parti(arr,l,r);
            if(piv==k-1){
                return arr[piv];
            }
            else if(piv<k-1){
                l=piv+1;
            }
            else{
                r=piv-1;
            }
        }
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends