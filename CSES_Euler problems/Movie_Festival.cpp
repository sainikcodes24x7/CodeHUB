#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll T=1;
    //cin>>T;
    while(T--){
       vector<pair<ll,ll>> v;
       ll n;
       cin>>n;
       for(ll i=0;i<n;i++){
          ll a,c;
          cin>>a>>c;
          // pushing end time, start time
          v.push_back({c,a});
       }
       sort(v.begin(),v.end());

       ll curr=v[0].first;
       ll ans=1;
       for(ll i=1;i<n;i++){
           if(v[i].second>=curr){
            // take this
            curr=v[i].first;
            ans++;
           }
       }
       cout<<ans<<"\n";
    }
return 0;
}