// Problem: P1 - The Triangle
// URL: https://dmoj.ca/problem/ioi94p1
// Memory Limit: 16 MB
// Time Limit: 600 ms

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int __t ; cin >> __t; while (__t--)
    solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;

    int ar[n][n];

    for (int i = 0, j; i < n; i++)
        for (j = 0; j <= i; j++)
            cin >> ar[i][j];

    for (int i = 1; i < n; i++)
        ar[i][0] += ar[i - 1][0];

    for (int i = 1, j, x; i < n; i++)
        for (j = 1; j <= i; j++)
        {
            x = ar[i - 1][j - 1];
            if (j < i)
                x = max(x, ar[i - 1][j]);
            ar[i][j] += x;
        }

    // for (int i = 0, j; i < n; i++)
    // {
    // for (j = 0; j <= i; j++)
    // cerr << ar[i][j] << sp;
    // cerr << el;
    // }

    int ans = ar[n - 1][0];
    rep(i, 1, n) ans = max(ans, ar[n - 1][i]);

    cout << ans;

    return;
}