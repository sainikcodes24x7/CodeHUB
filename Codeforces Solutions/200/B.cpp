#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
//Srayan Bhattacharyya JU EE
int main()
{
    int n; cin >> n;
    int a[n];
    double p = 0;
    rep(i, n)
    {
        cin >> a[i];
        p += a[i];
    }
    cout << double((p*100)/(n*100.0)) << endl;

    return 0;
}