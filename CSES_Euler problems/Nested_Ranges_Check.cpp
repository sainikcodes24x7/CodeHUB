//  “Work like there is someone working 24 hours a day to take it away from you.”

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define db double
#define el '\n'
#define ld long double
#define pb push_back
#define all(x) x.begin(), x.end()
#define asc(x) sort(x.begin(), x.end())
#define des(x) sort(x.begin(), x.end(), greater<int>())
#define rep(i, n) for (int i = 0; i < n; i++)
#define rev(i, n) for (int i = n; i >= 0; i--)
#define rep_a(i, a, n) for (int i = a; i < n; i++)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define int long long

const long long MOD = 998244353;
const long long INF = 1e9 + 10;
const long long INFLL = 1e18;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef set<int> si;
typedef set<ll> sll;

typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define yes cout << "YES\n"
#define no cout << "NO\n"

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

#define print(arr)                                     \
    for (auto it = arr.begin(); it != arr.end(); ++it) \
        cout << *it << " ";                            \
    cout << endl;
//-------------------------------------------------------------------------

//------------------------------------------------------------------------
ll stringtointeger(string s)
{
    ll num;
    num = stoi(s);
    return num;
}

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
ll pwr(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const int N = 200005;

//------------------------------------------------------------------------

struct range{
    int l,r,index;
    
};
bool cmp(range a,range b){
    if(a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}
void solve()
{
    // int n;
    // cin >> n;
    // vector<pair<int, int>> p(n);
    // vi contains(n, 0);
    // rep(i, n)
    // {
    //     cin >> p[i].first >> p[i].second;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i != j)
    //             if (p[i].first <= p[j].first && p[i].second >= p[j].second)
    //                 contains[i] = 1;
    //     }
    // }
    // rep(i, n) cout << contains[i] << " ";
    // cout << el;
    // vi contains1(n, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i != j)
    //         {
    //             if (p[i].first >= p[j].first && p[i].second <= p[j].second)
    //                 contains1[i]=1;
    //         }
    //     }
    // }
    // rep(i, n) cout << contains1[i] << " ";
    // cout << el;

    //THIS IS BRUTE FORCE METHOD OF TIME COMPLEXITY OF O(N2)


    int n; cin>>n;
    vector<range>ranges(n);
    vector<bool>contained(n);
    vector<bool>contains(n);
    rep(i,n){
        cin>>ranges[i].l>>ranges[i].r;
        ranges[i].index=i;
    }
    sort(all(ranges),cmp);
    int maxEnd=0;
    rep(i,n){
        if(ranges[i].r<=maxEnd)
            contained[ranges[i].index]=true;
        maxEnd=max(maxEnd,ranges[i].r);

    }
    int minEnd=1e9+10;
    for(int i=n-1;i>=0;i--){
        if(ranges[i].r>=minEnd) contains[ranges[i].index]=true;
        minEnd=min(minEnd,ranges[i].r);
    }

     rep(i,n){
        cout<<(int)contains[i]<<" ";
     } cout<<el;
     rep(i,n) cout<<(int)contained[i]<<" ";
     cout<<el;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {

        solve();
    }

    // return 0;
}