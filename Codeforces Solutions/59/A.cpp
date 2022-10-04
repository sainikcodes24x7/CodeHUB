#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
//Srayan Bhattacharyya JU EE
int main()
{
    string s;
    cin >> s;
    int lower = 0, upper = 0;
    int n = s.length();
    rep(i,n)
    {
        if (int(s[i]) > 96) lower++;
        else upper++;
    }
    //cout << lower << endl << upper;
    if (lower < upper)
    rep(i, n)
    {
        if (int(s[i]) > 96) 
        s[i] -= 32;
    }
    else
    rep(i, n)
    {
        if (int(s[i]) < 96) 
        s[i] += 32;
    }
    cout << s;
    
    return 0;
}
    
