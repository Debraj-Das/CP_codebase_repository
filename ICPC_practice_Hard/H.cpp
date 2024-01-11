// Problem: H. Chewbaсca and Number
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/H
/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#include <cstdio>

int main()
{
   long long x, ans = 0, dec = 1;
   scanf("%lld", &x);

   for (int rem; x; x /= 10, dec *= 10)
   {
      rem = x % 10;
      ans += dec * (2 * rem < 9 ? rem : 9 - rem);
   }

   ans = (ans > 0 ? ans : 9);
   printf("%lld", ans);

   return 0;
}
