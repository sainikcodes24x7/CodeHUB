//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int atmostk(string s, int k){
        vector<long long int>f(26,0);
        
        long long int start=0,count=0,distinct=0;
        for(int i=0;i<s.size();i++){
            if(f[s[i]-'a']==0){
                distinct++;
            }
            f[s[i]-'a']++;
            
            while(distinct>k){
                f[s[start]-'a']--;
                if(f[s[start]-'a']==0)
                    distinct--;
                    start++;
                
                
            }
            if(distinct<=k)
            count=count+i-start+1;
        }
        return count;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	return atmostk(s,k)-atmostk(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends