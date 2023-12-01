// Problem: O. Five in One
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/O
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
    "Arise! Awake! And stop not until the goal is reached."
    "You cannot believe in God until you believe in yourself."
    "Talk to yourself once in a day, otherwise you may miss meeting an intelligent person in this world."
    "We are what our thoughts have made us; so take care about what you think.
                    Words are secondary. Thoughts live; they travel far."
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
const ld ep = 0.0000001;
const ld pi = acos(-1.0);

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

const int N = 101;
int divisor[N];

void cal()
{
   divisor[0] = 0;
   divisor[1] = 1;
   rep(i, 2, N) divisor[i] = 2;

   for (int i = 2, j; i < N; i++)
      for (j = i + i; j < N; j += i)
         divisor[j]++;

   return;
}

bool pan(int n)
{
   string s = to_string(n);
   for (int i = 0, j = s.sz - 1; i < j; i++, j--)
      if (s[i] != s[j])
      {
         return false;
      }

   return true;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   cal();

   int n = 100;

   int ar[n];
   rep(i, 0, n) ar[i] = i + 1;

   cout << "The maximum number : " << *max_element(ar, ar + n) << el;
   cout << "The minimum number : " << *min_element(ar, ar + n) << el;

   int pm = 0;
   rep(i, 0, n) if (divisor[ar[i]] == 2)
   {
      pm++;
   };

   cout << "The number of prime numbers : " << pm << el;

   pm = 0;
   rep(i, 0, n) if (pan(ar[i]))
   {
      cerr << ar[i] << sp;
      pm++;
   }
   cerr << el;

   cout << "The number of palindrome numbers : " << pm << el;

   pm = 0;
   rep(i, 0, n) if (divisor[ar[i]] >= divisor[pm])
   {
      cerr << ar[i] << sp << divisor[ar[i]] << el;
      pm = ar[i];
   }

   cout << "The number that has the maximum number of divisors : " << pm << el;

   return 0;
}

/*
  After Solving the any problems write some point on notebook for future refferences
    1. Go through the solution and overall logic flows

    2. Go through editiorial and other implementation

    3. Make note ->
        a. Didied the into keys steps
        b. Topic and level(out of 100)
        etc..

    4. What new points you discover from this problems
        a. insight
        b. intuition
        c. process (steps of both)

    5. Solution Date and Submission time (reading , thinking , implementation , total)

    6. submit count and solve by youself ?
*/