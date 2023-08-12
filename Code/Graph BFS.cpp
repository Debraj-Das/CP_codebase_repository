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

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

void bfs(int i, vi gr[], bool visit[])
{
    queue<int> q;
    q.push(i);
    int ele;
    while (!q.empty())
    {
        ele = q.front();
        q.pop();
        visit[ele] = true;
        cout << ele << sp;
        for (auto x : gr[ele])
            if (!visit[x])
                q.push(x);
    }
    return;
}

inline void solve()
{
    *unuse = 0;
    int v;
    cin >> v;
    vi gr[v];
    int e, x, y;
    cin >> e;
    f(i, 0, e)
    {
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    bool visit[v] = {false};
    int comp = 0;
    f(i, 0, v) if (!visit[i]) comp++, bfs(i, gr, visit), cout << el;
    cout << comp << el;

    return;
}