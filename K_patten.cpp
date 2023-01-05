/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;
void solve() ;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--) solve();  // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void print_simple(int n)
{
    if (n == 1)
    {
        cout << '*' << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
        cout << '*' << ' ';
    cout << endl;
    print_simple(n - 1);
    for (int i = 0; i < n; ++i)
        cout << '*' << ' ';
    cout << endl;
    return;
}

void solve()
{
    int n;
    cin >> n;
    print_simple(n);

    return;
}
