//  “Work like there is someone working 24 hours a day to take it away from you.”

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define db double
#define el endl
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define asc(x) sort(x.begin(),x.end())
#define des(x) sort(x.begin(),x.end(),greater<int>())
#define rep(i, n) for (int i = 0; i < n; i++)
#define rev(i, n) for (int i = n; i >= 0; i--)
#define rep_a(i, a, n) for (int i = a; i < n; i++)


const long long MOD = 998244353;
const long long INF = 1e9 + 10;
const long long INFLL = 1e18;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef set<int> si;
typedef set<ll> sll;

typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define yes cout << "YES\n"
#define no  cout << "NO\n"

#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAXX(v) *max_element(all(v))
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;


#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
//-------------------------------------------------------------------------
#define MAX 1000005
int prime[MAX];
vector<int> allPrimes;//primes
void sieve()
{
    memset(prime,0, sizeof(prime));//na dileo hobe. emniteo global array. so all element 0
    prime[0]=prime[1]=1;// 0 and 1 prime na
    for(int i = 4; i < MAX; i+= 2) prime[i] = 1;//2 prime, 4 theke suru kore ar baki sob even num prime na
    
    for(int i = 3; i*i < MAX; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j = i*i; j < MAX; j+=i)
            prime[j]=1;
        }
    }

    for(int i = 2; i < MAX; i++)
        if(prime[i]==0)
            allPrimes.push_back(i);// sob prime rakhlam p vector e
 
}

vector<ll>findPrimeFactors(ll n)
{
    vector<ll> primeFactors;
    while (n%2== 0) primeFactors.push_back(2), n = n/2;
    for (ll i = 3; i*i <= n; i = i+2)
    {
        while (n%i == 0)
        {
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    if (n > 2) primeFactors.push_back(n);
    return primeFactors;
}
bool isPrime(ll n)
{
    if(n==2 or n==3) return true;
    if(n%2==0) return false;
    for(ll i=3; i*i<=n; i+=2) if(n%i==0) return false;
    return true;
}
//------------------------------------------------------------------------
bool isPalindrome(string S){
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
    if (S == P) {return true;}
    else {return false;}}
//------------------------------------------------------------------------
ll stringtointeger(string s){  ll num; num = stoi(s); return num;}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) { ll res = 1; while (b > 0) {if (b & 1) res = res * a ; a = a * a; b >>= 1;} return res;}

const int N=200005;

//------------------------------------------------------------------------

void solve(){
    ll n; cin>>n;
    cout<<n<<" ";
    while(n>1){
        if(n%2) {n=n*3+1; cout<<n<<" ";}
        else{
            n=n/2;
            cout<<n<<" ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
  
    {

       solve();

    }

    return 0;
}