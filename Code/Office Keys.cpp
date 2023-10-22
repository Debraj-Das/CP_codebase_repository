// Problem: E. Office Keys
// URL: https://codeforces.com/gym/302977/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

#define pii pair<int, int>
#define ff first
#define ss second
#define mp make_pair

#define vb vector<bool>
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

    // int __t ; cin >> __t; while (__t--)
    solve();

    return 0;
}

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    int per[n], key[k];
    f(i, 0, n) cin >> per[i];
    f(i, 0, k) cin >> key[i];

    sort(per, per + n);
    sort(key, key + k);

    int dp[k + 1][n + 1];
    for (int i = 0, j; i <= k; i++)
        for (j = 0; j <= n; j++)
            dp[i][j] = INT_MAX;

    dp[0][0] = 0;

    for (int i = 0, j; i < k; i++)
        for (j = 0; j <= n; j++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j < n)
            {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(per[j] - key[i]) + abs(key[i] - p)));
            }
        }

    cout << dp[k][n] << el;

    return;
}
