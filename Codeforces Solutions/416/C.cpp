//Srayan Bhattachrayya JU EE
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
const int N = 1e3 + 10;
const int INF = (1 << 30) - 1;
#define pii pair < int, int >
int c[N], p[N];
pair <int, int> r[N];
bool used[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >>n;
	for (ll i = 0; i < n; i++) cin >> c[i] >> p[i];
	cin >> k;
	for (ll i = 0; i < k; i++){
		cin >> r[i].f;
		r[i].s = i;
	}
	sort(r, r + k);
	vector < pii > ans;
	ll sum = 0;
	for (ll i = 0;i < k; i++){
		ll x = r[i].f;
		ll mx = -INF;
		ll ind = -1;
		for (ll j=0;j<n;j++){
			if ( used[j]) continue;
			if ( c[j] <= x){
				if ( p[j] > mx){
					mx = p[j];
					ind = j;
				}
			}	
		}
		if ( ind != -1){
			ans.push_back(mp(ind, r[i].s));
			sum += p[ind];
			used[ind] = true;			
		}
	}
	cout <<ans.size()<<" "<<sum<<"\n";
	for (ll i=0;i<ans.size();i++){
		cout <<ans[i].f+1<<" "<<ans[i].s+1<<"\n";
	}
    return 0;
}