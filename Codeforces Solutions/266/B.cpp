#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
//Srayan Bhattacharyya JU EE

int main()
{
    int n, t; cin >> n >> t;
    string s; cin >> s;
    int a = 0;
    while (t--)
    {
        rep(i, n-1)
        {
            if (s[i] == 'B' && s[i+1] == 'G')
            {
                s[i] = 'G'; s[i+1] = 'B';
                i++;    
            }
        }
    }
    cout << s << endl;

    return 0;    
}