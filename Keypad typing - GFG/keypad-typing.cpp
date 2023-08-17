//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

string printNumber(string , int);

// User function pasted here
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,temp;
		cin>>s;
		int i,len=s.length();
		
		cout << printNumber(s,len) << "\n";
	}
	return 0;
}
// } Driver Code Ends


//User function template for C++


//Function to find matching decimal representation of a string as on the keypad.
string printNumber(string s, int n) 
{
    //code here
      unordered_map<char, char> keypad = {
        {'a', '2'}, {'b', '2'}, {'c', '2'},
        {'d', '3'}, {'e', '3'}, {'f', '3'},
        {'g', '4'}, {'h', '4'}, {'i', '4'},
        {'j', '5'}, {'k', '5'}, {'l', '5'},
        {'m', '6'}, {'n', '6'}, {'o', '6'},
        {'p', '7'}, {'q', '7'}, {'r', '7'}, {'s', '7'},
        {'t', '8'}, {'u', '8'}, {'v', '8'},
        {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'}
    };

    string result = "";
    for (int i = 0; i < n; i++) {
        result += keypad[s[i]];
    }

    return result;
}
