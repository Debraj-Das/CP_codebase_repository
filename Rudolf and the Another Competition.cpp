// Problem: C. Rudolf and the Another Competition
// URL: https://codeforces.com/problemset/problem/1846/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define maxa(a, b) a += ((b)-a) * ((b) > a)
#define mina(a, b) a -= (a - (b)) * ((b) < a)

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

#define pii pair<int, int>
#define ff first
#define ss second

#define vi vector<int>
#define pb push_back

template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

inline int exp(int a, int b)
{
    int x;
    for (x = 1; b; a *= a, b >>= 1)
        x *= (a * (b & 1) + !(b & 1));
    return x;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

pii point(int t[], const int &m, const int &h)
{
    sort(t, t + m);
    int time = 0;
    pii ans = {0, 0};
    f(i, 0, m)
    {
        time += t[i];
        if (time <= h)
            ans.ff++, ans.ss += time;
        else
            break;
    }
    return ans;
}

bool comp(const pii &a, const pii b)
{
    return (b.ff > a.ff) or ((b.ff == a.ff) and (b.ss < a.ss));
}

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    int t[n][m];
    for (int i = 0, j; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> t[i][j];

    const pii p = point(t[0], m, h);

    int ans = 1;
    f(i, 0, n) ans += comp(p, point(t[i], m, h));

    cout << ans << el;

    return;
}
