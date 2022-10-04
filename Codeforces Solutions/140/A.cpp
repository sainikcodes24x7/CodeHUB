#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
typedef long long ll;
//Srayan Bhattacharyya JU EE

int main()
{
    int n, R, r;
	cin >> n >> R >> r;
    if(n == 1) {
		if(R < r) cout << "NO";
		else cout << "YES";
		return 0;
	}
	if(2 * r > R) {
		cout << "NO";
		return 0;
	}
	if(2 * r == R) {
		if(n == 2) cout << "YES";
		else cout << "NO";
		return 0;
	}
	double angle = asin(  ((double)(r))/(R - r)  );
	if(angle * n * 2 > 1e-9 + asin(1) * 4) cout << "NO";
	else cout << "YES";
    return 0;
}