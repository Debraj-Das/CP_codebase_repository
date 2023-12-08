// Problem: K. Prime Fibonacci
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223206/problem/K
// Memory Limit: 256 MB
// Time Limit: 250 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rev(i, a, b) for (int i = (a); i > (b); --i)
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define setpr(x) cout << setprecision(x) << fixed
#define sz size()

using pii = pair<int, int>;
#define ff first
#define ss second
#define mp make_pair

using vb = vector<bool>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()

template <typename T1, typename T2> using P = pair<T1, T2>;
template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

template <typename T> inline T exp(T a, int b)
{
   T x = 1;
   while (b)
   {
      if (b & 1)
         x *= a;
      a *= a;
      b >>= 1;
   }
   return x;
}

inline void solve();

const int N = 50;
bool prime[N];

bool is_prime(ll n)
{
   if (n < 2)
      return false;

   for (ll i = 2; i * i <= n; i++)
      if (n % i == 0)
         return false;

   return true;
}

void fib()
{
   ll fib[N];
   fib[0] = 0;
   fib[1] = 1;

   rep(i, 2, N) fib[i] = fib[i - 1] + fib[i - 2];

   rep(i, 0, N)
   {
      prime[i] = is_prime(fib[i]);
      // cerr << prime[i] << sp << fib[i] << el;
   }

   return;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   fib();
   int __t;
   cin >> __t;
   while (__t--)
      solve();

   return 0;
}

void solve()
{
   int n;
   cin >> n;

   n--;

   cout << eif(prime[n], "prime", "not prime") << el;

   return;
}
