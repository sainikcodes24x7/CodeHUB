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

const int N = 200005;

//------------------------------------------------------------------------

// 1 -->blocked
void solve()
{
    int n;
    cin >> n;
    bool grid[n + 1][n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
                grid[i][j] = 0;
            else
                grid[i][j] = 1;
        }
    }
    int dp[n + 1][n + 1];
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {

            if (i == n && j == n)
                dp[i][j] = 1;
            else
            {
                int op1 = (j == n) ? 0 : dp[i][j + 1];
                int op2 = (i == n) ? 0 : dp[i + 1][j];
                dp[i][j] = (op1 + op2) % (int)(1e9 + 7);
                if (grid[i][j])
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    if(grid[n][n] || grid[1][1]) cout<<0<<endl;
    else
    cout<<dp[1][1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {

    solve();

    // }

    // return 0;
}