//Srayan Bhattachrayya JU EE
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(ll i=0;i<n;i++)
#define rev(i,n) for(ll i=n;i>=0;i--)
#define rev_a(i,a,n) for(ll i=n;i>=a;i--)
#define rep_a(i,a,n) for(ll i=a;i<n;i++)
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <vll> vvll;
typedef vector <string> vs;
typedef set <ll> sll;
typedef vector <pll> vpll;
typedef vector <long double> vld;
#define st(s) sort(s.begin(),s.end())
#define dst(s) sort(s.begin() , s.end() , greater<int>())
#define all(s) s.begin(), s.end()
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
const ll MOD = 1e9 + 7; 
const ll MODS = 998244353; 
const ll NN = 1e7 + 10; 
const ll NS = 1e5 + 10;
const ll LLMAX = 1e18; 
const ld pi = 3.14159265358979323846;
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll mods_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MODS) + MODS) % MODS;}
ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll mod_inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * mod_inv(MOD % i)) % MOD) % MOD;}
ll mods_inv(ll i) {if (i == 1) return 1; return (MODS - ((MODS / i) * mod_inv(MODS % i)) % MODS) % MODS;}
ll mod_pwr(ll a, ll b) { if(b < 0) return 0; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}
ll mod_div(ll a, ll b) {a = a % MOD; ll inv = mod_inv(b); if (inv == -1) return -1; else {ll ans = (inv * a) % MOD; return ans;}}
ll mods_div(ll a, ll b) {a = a % MODS; ll inv = mod_inv(b); if (inv == -1) return -1; else {ll ans = (inv * a) % MODS; return ans;}}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class K, class V> using um = unordered_map <K, V, custom_hash>;

vs split(string s, string del = " "){
    vs ans; ll start = 0; ll end = s.find(del);
    while (end != -1) {
        cout << s.substr(start, end - start) << "\n";
        start = end + del.size(); 
        end = s.find(del, start);
    }
    ans.push_back(s.substr(start, end - start)); 
    return ans;
}

vll divisors(ll n){
    vll v;
    for (ll i = 1; i <= (ll)sqrt(n); i++){
        if (n % i == 0){
            v.emplace_back(i);
            if ((n / i) != i) v.emplace_back(n / i);
        }
    }
    return v;
}

vll findPrimeFactors(ll n){
    vll primeFactors;
    while (n%2== 0) primeFactors.push_back(2), n = n/2;
    for (ll i = 3; i*i <= n; i = i+2){
        while (n%i == 0){   
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    if (n > 2) primeFactors.push_back(n);
    return primeFactors;
}

bool isPrime(ll n){
	if (n == 1) return false;
    if(n==2 or n==3) return true;
    if(n%2==0) return false;
    for(ll i=3; i * i <= n; i += 2) if(n % i==0) return false;
    return true;
}

ll *fact;
void calFact(){
    fact = new ll[NN];
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i < NN; i++)
        fact[i] = mod_mul(fact[i - 1], i);
}
 
ll ncr(ll n, ll r){
    ll ans = fact[n];
    ans = mod_mul(ans, mod_inv(fact[n - r]));
    ans = mod_mul(ans, mod_inv(fact[r]));
    return ans;
}

bool isKthBitSet(ll n, ll k){
    if ((n >> k) & 1)
        return true;
    return false;
}

bool isPalindrome(string S){
    string P = S;
    reverse(all(P));
    if (S == P) return true;
    else return false;
}

ll digitsum(ll x){
	ll ans=0;
	while(x > 0) ans += x % 10, x /= 10;
	return ans;
}

void solve(){}

ll n;
string st;
vll num1,num2;
ll u[20],v[20],U[20],V[20];

ll calc(ll x, ll y)
{
	for (ll i=0; i<=9; i++)
	{
		U[i]=u[i];
		V[i]=v[i];
	}
	if (u[x]==0 || v[y]==0) return 0;
	--U[x]; --V[y];
	ll ret=1;
	for (ll i=0; i<=9; i++)
		if (U[i]>0 && V[9-i]>0)
		{
			ll tmp=min(U[i],V[9-i]);
			ret+=tmp;
			U[i]-=tmp;
			V[9-i]-=tmp;
		}
	return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>st;
	ll n=st.size();
	memset(u,0,sizeof(u));
	for (ll i=0; i<n; i++)
		++u[st[i]-'0'];
	num1.clear(); num2.clear();
	
	for (ll i=0; i<=9; i++) v[i]=u[i];
	ll delta=v[0]-v[9];
	for (ll i=1; i<=delta; i++)
	{
		num1.push_back(0);
		num2.push_back(0);
	}
	if (delta>0)
	{
		u[0]-=delta;
		v[0]-=delta;
	}

	ll ret=0,now=1;
	for (ll i=1; i<=9; i++)
		if (calc(i,10-i)>ret)
		{
			now=i;
			ret=calc(i,10-i);
		}
	if (ret==0)
	{
		sort(st.begin(),st.end());
		rev(i, n - 1) cout <<st[i];
		cout  << "\n";
		rev(i, n - 1) cout <<st[i];
		cout  << "\n";
	} else
	{
		u[now]--; v[10-now]--;
		num1.push_back(now); num2.push_back(10-now);
		rep(i, 10)
			if (u[i]>0 && v[9-i]>0)
			{
				ll tmp=min(u[i],v[9-i]);
				for (ll j=1; j<=tmp; j++) num1.push_back(i);
				for (ll j=1; j<=tmp; j++) num2.push_back(9-i);
				u[i]-=tmp; v[9-i]-=tmp;
			}
		rep_a(i, 1, 10)
		{
			for (ll j=1; j<=u[i]; j++) num1.push_back(i);
			for (ll j=1; j<=v[i]; j++) num2.push_back(i);
		}
		rev(i, n - 1) cout <<num1[i];
		cout  << "\n";
		rev(i, n - 1) cout <<num2[i];
		cout  << "\n";
	}
  
    return 0;
}