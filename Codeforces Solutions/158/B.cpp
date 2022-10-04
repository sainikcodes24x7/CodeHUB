#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
typedef long long ll;
//Srayan Bhattacharyya JU EE

int grpcnt[5];
int main()
{
    int n; cin >> n; int taxi = 0;
    int a[n];
    rep (i, n){
        cin >> a[i];
        grpcnt[a[i]]++;
    }
    
    taxi += grpcnt[4];
     if(grpcnt[3] < grpcnt[1]){
        taxi += grpcnt[3];
        grpcnt[1] = grpcnt[1] - grpcnt[3];
        grpcnt[3] = 0;
    }else if(grpcnt[1] <= grpcnt[3]){
        taxi += grpcnt[1];
        grpcnt[3] = grpcnt[3] - grpcnt[1];
        grpcnt[1] = 0;
    }
    if(grpcnt[3] > 0){
        taxi += grpcnt[3];
        grpcnt[3] = 0;
    }
    //change
    if(grpcnt[2] > 0){
        taxi += grpcnt[2]/2;
        grpcnt[2] = grpcnt[2]%2;
    }

    int remain = grpcnt[1] + (grpcnt[2]*2); 
    if(remain <= 4 && remain > 0){
        taxi += 1;
    }else if(remain % 4 != 0){
        taxi += (remain / 4) + 1; 
    }
    else{
        taxi += remain / 4;
    }
    cout << taxi << "\n";
    return 0;
}