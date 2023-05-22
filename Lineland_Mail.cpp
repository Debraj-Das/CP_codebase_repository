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
    // cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    f(i, 0, n) cin >> arr[i];
    for (int i = 0, maxi, mini; i < n; ++i)
    {
        // find the mini
        if (i == 0)
            mini = arr[i + 1] - arr[i];
        else if (i == n - 1)
            mini = arr[i] - arr[i - 1];
        else
            mini = min(arr[i] - arr[i - 1], arr[i + 1] - arr[i]);
        // find the maxi
        maxi = max(arr[i] - arr[0], arr[n - 1] - arr[i]);
        cout << mini << " " << maxi << el;
    }

    return;
}