#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
typedef long long ll;
//Srayan Bhattacharyya JU EE
int main()
{
    int n; int m;
    cin >> n >> m;
    int start = 1;
    ll time = 0;
    while (m--){
        int end; cin >> end;
        if (end > start){
            time += end - start;
        }
        else if (start > end){
            time += n - (start - end);
        }
        else if (start == end){
            continue;
        }
        start = end;
    }    
    cout << time << "\n";
    return 0;
}