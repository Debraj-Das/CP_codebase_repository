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

    solve();

    return 0;
}

bool alnum(const string &s)
{
    return all_of(s.begin(), s.end(), [](char c) { return isalnum(c); });
}

bool substring(string s)
{
    if (alnum(s) == false)
        return false;

    set<char> st;
    for (char &c : s)
        st.insert(c);

    if (st.size() < 3)
        return false;

    string vow = "AEIOUaeiou";

    for (char &c : vow)
    {
        if (st.find(c) != st.end())
        {
            return true;
        }
    }

    return false;
}

int countValidWords(string &s)
{

    const int n = s.size();
    int i, l, ans = 0;
    for (i = 0, l = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            ans += substring(s.substr(l, (i - l)));

            l = ++i;
        }
    }

    ans += substring(s.substr(l, n - l));

    return ans;
}

void solve()
{
    string s = "This is an example string 234";

    cout << countValidWords(s) << el;

    return;
}
