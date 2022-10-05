// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define db double
#define el endl
#define ld long double
#define pb push_back
#define all(x) x.begin(), x.end()
#define asc(x) sort(x.begin(), x.end())
#define des(x) sort(x.begin(), x.end(), greater<int>())
#define rep(i, n) for (int i = 0; i < n; i++)
#define rev(i, n) for (int i = n; i >= 0; i--)
#define rep_a(i, a, n) for (int i = a; i < n; i++)

#define MOD 1000000007
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

#define int long long 
// const long long MOD = 998244353;

int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1);
    dp[0] = 1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= target; i++)
    {
        for (auto num : nums)
        {
            if (i < num)
                break;
            dp[i] += dp[i - num];
            dp[i]%=MOD;
        }
    }
    return dp.back();
}
void solve()
{
    // order matters in this ques
    int n;
    cin >> n;
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    cout<<combinationSum4(nums,n)<<el;
}
int32_t main()
{

    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
    }

    return 0;
}