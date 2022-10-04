#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
//Srayan Bhattacharyya JU EE
int main()
{
    long long int n; cin >> n;
    string str = to_string(n);
    int f = 0, s = 0;
    int l =str.length();
    rep(i, l)
    {
        if (str[i] == '4') f++;
        else if (str[i] == '7') s++;
    }
    if (f + s == 7 || f + s == 4)  cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}