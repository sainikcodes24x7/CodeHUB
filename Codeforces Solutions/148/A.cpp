#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
//Srayan Bhattacharyya JU EE
int main()
{
    int k, l, m, n, d;
    cin >> k; cin >> l; cin >> m; cin >> n; cin >> d;
    int ct = 0;
    rep(i, d+1)
    {
        if ( ((i % k != 0) && (i % l != 0)) && ((i % m != 0) && (i % n != 0) ) ) ct++;
        else continue;
    }
    cout << d-ct << endl;
    
    return 0;
}