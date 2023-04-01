/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(a, b) for (int i = a; i < b; i++)
#define fr(a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n], b[n], j[k];
    f(0, n) cin >> a[i];
    f(0, n) cin >> b[i];
    f(0, n) a[i]--;
    f(0, k) j[i] = -1;
    f(0, n) if (j[a[i]] == (-1) or b[i] > b[j[a[i]]]) j[a[i]] = i;
    f(0, k) if (j[i] != (-1)) b[j[i]] = 0;
    sort(b, b + n);
    n = 0;
    f(0, k) n += b[i];
    cout << n << el;
    return;
}