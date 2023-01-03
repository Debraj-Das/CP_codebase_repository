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

int tsp(vector<vector<int>> dist ,int set0ofcities, int city , int n)
{
    //base condition
    if(set0ofcities==((1<<n)-1))
    return dist[city][0];

    int ans = INT_MAX;
    for(int i=0,choice=1,subProb;i<n;i++,choice<<=1)
    {
        if((set0ofcities&choice)==0)
        {
            subProb = dist[city][i] + tsp(dist,set0ofcities|choice,i,n);
            ans =min(ans,subProb);
        }
    }
    return ans ;
}

void solve() 
{
	vector<vector<int>> dist = {
        {10,20,42,25},
        {20,10,40,34},
        {42,30,10,10},
        {25,34,10,10}
    };
    cout<<tsp(dist,1,0,4)<<endl;
    return ;
}
