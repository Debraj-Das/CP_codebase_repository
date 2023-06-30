/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

int solve(int n, int m, vector<int> a)
{
    if (n > m)
        return 0;
    int ans = 1;
    sort(a.begin(), a.end());
    for (int i = 0, j; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            ans = (ans * ((a[j] - a[i]) % m)) % m;
            if (ans == 0)
                return 0;
        }
    return ans;
}

void solve()
{

    return;
}