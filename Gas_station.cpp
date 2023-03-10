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
    int n;
    cin >> n;
    int a[n], b[n];
    f(0, n) cin >> a[i];
    f(0, n) cin >> b[i];
    int sum = 0;
    f(0, n) sum += (a[i] -= b[i]);
    if (sum < 0)
        cout << -1 << el;
    else
    {
        int index = 0;
        sum = 0;
        f(0, n)
        {
            sum += a[i];
            if (sum < 0)
            {
                sum = 0;
                index = i + 1;
            }
        }
        cout << index << el;
    }

    return;
}
