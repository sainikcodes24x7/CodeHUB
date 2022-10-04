#include<bits/stdc++.h>

//#include<boost/multiprecision/cpp_int.hpp>

//using namespace boost::multiprecision;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

  

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int

#define dsort(v)  sort(v.begin(),v.end(),greater<ll>())

#define cpi cpp_int

#define ld long double

#define pb  push_back

#define lb  lower_bound 

#define ub  upper_bound 

#define all(v) v.begin(),v.end()

#define endl "\n"

#define sz(x) x.size()

#define INF 1e18

#define setbits(x) __builtin_popcount(x)

#define setbitsll(x) __builtin_popcountll(x)

#define bits(x)    (int)(log2(x) + 1)





// Loops

#define rep(x,a,b)            for (int x=a; x<=b; x++) 

#define nrep(x,a,b)           for (int x=a; x>=b; x--) 

 

#define boost {ios_base::sync_with_stdio(false);  cin.tie(NULL);cout.tie(NULL);}



typedef pair<ll, ll>pll;

typedef pair<int, int> pii;

typedef vector<ll> vll;

typedef vector<int> vi;

typedef vector<pll> vpll;

typedef vector<pii > vii;

typedef priority_queue<pii, vector<pii>, greater<pii> > min_heap;

typedef priority_queue<pii > max_heap;





//power optimized 

 

ll power(ll x, ll y, ll p)  

{  

    ll res = 1;  

    x = x % p;  

    if (x == 0) return 0;



// 128 bit integers can store upto 10^38.

 

    while (y > 0)  

    {   

        if (y & 1)  

            res = ((__int128)res*x) % p;  

        y = y>>1; 

        x = ((__int128)x*x) % p;  

    }  

    return res;  

}  



const ll mod = 1e9 + 7;

const int mod1 = 998244353;





// ******************************************************************



const int maxn = 2e5 + 1;





void test_case()

{

string s;

cin >> s;



ll n = s.length();



unordered_map<ll, ll> mp;



ll mask = 0;

vector<ll> fre(26, 0);



for(ll i = 0; i < n; i++)

   if(s[i] != '?')

    fre[s[i] - 'a']++;



for(ll i = 0; i < 26; i++)

  if(fre[i] & 1)

     mask = mask | (1 << i);





ll pm = 0;

ll ans = 0;



for(ll i = 0; i < n; i++)

{



    if(s[i] != '?')

    {

         ll k = s[i] - 'a';

         pm = pm ^ (1ll << k);

    

    }

   else

   {

       ll k = 26;

       pm = pm ^ (1ll << k);

  

   }

   

  ll rmask = mask;

  ll smask = pm ^ (rmask);

  ans = ans + mp[smask];

  

  if(pm == rmask)

    ans++;

  

 for(ll i = 0; i < 26; i++)

  {

      ll rmask = mask ^ (1ll << i);

      rmask = rmask ^ (1ll << 26);

      ll smask = pm ^ rmask;

      

      ans = ans + mp[smask];

      

      if(pm == rmask)

        ans++;

  }

 

   mp[pm]++;

    

}



cout << ans << endl;



}





int main()

{boost;



int test;

cin >> test;



while(test--)

  test_case();

	



    return 0;

}
