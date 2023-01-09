/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

// #include <bits/stdc++.h>
// using namespace std;
// void solve();

// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     clock_t z = clock();

//     int t = 1;
//     cin >> t;
//     while (t--)
//         solve(); // solve the problem inside of drive function for test cases.

//     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

//     return 0;
// }

// void solve()
// {
//     int a;
//     cin >> a;
//     if (a != 1)
//     {
//         int b = sqrt(a);
//         if (a == (b * b))
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
//     else
//         cout << "NO" << endl;
//     return;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int t;
//     cin >> t;
//     queue<int> q;
//     vector<int> n;
//     for (int i = 0; i < t; i++)
//     {
//         int temp;
//         cin >> temp;
//         n.push_back(temp);
//         q.push(temp);
//     }
//     int t_temp = q.front();
//     int i_t = t;

//     int count = 0;
//     for (int i = 1; i <= t_temp; i++)
//     {

//         if (t_temp % i == 0)
//             ++count;

//         if ((count > 3) || ((count < 3) && (i == t_temp)))
//         {
//             cout << "NO" << endl;
//             q.pop();
//             t_temp = q.front();
//             i = 0;
//             count = 0;
//             continue;
//         }

//         if ((count == 3) && (i == t_temp))
//         {
//             cout << "YES" << endl;
//             q.pop();
//             t_temp = q.front();
//             i = 0;
//             count = 0;
//             continue;
//         }
//     }

//     return 0;
// }




/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
 int x = 1;
 while (b)
 {
     if (b & 1) x *= a;
     a *= a;
     b >>= 1;
 }
 return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
 const char* comma = strchr (names + 1, ',');
 cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

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

void solve()
{
    cout<< "meet all o" <<endl;
    
    
    return ;
}
