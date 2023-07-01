// Problem: B. Tenzing and Books
// URL: https://codeforces.com/contest/1842/problem/B
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

#define ff first
#define ss second
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>

inline int exp(int a, int b)
{
    int x = 1;
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
    cin.tie(0);
    cout.tie(0);

    register int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

inline void solve()
{
    int n, x;
    cin >> n >> x;
    int a[n], ans = 0;
    f(i, 0, n) cin >> a[i];
    for (int i = 0; i < n and ans != x; i++)
    {
        if ((x | a[i]) != x)
            break;
        ans |= a[i];
    }
    f(i, 0, n) cin >> a[i];
    for (int i = 0; i < n and ans != x; i++)
    {
        if ((x | a[i]) != x)
            break;
        ans |= a[i];
    }
    f(i, 0, n) cin >> a[i];
    for (int i = 0; i < n and ans != x; i++)
    {
        if ((x | a[i]) != x)
            break;
        ans |= a[i];
    }

    if (ans == x)
        cout << "Yes" << el;
    else
        cout << "No" << el;

    return;
}
