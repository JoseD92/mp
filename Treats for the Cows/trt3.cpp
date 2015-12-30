#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long N, total, o;
int* t = NULL;
int* k = NULL;

int max (long a, long b, long c, double d, double e, long g)
{
   c=(c+1);
   g = (a + (b*N));
   if (t[g]==0) {
      if (a == (b - 1)) {
         if (k[a] <= k[b] ) { t[g] = ((k[a]*c)+(k[b]*(c+1))); return (t[g]); }
         else { t[g] = ((k[b]*c)+(k[a]*(c+1))); return (t[g]); }
      } else {
         d = ((k[a])*c + max ((a+1),b,c,0,0,0));
         e = ((k[b])*c + max (a,(b-1),c,0,0,0));
         if (e>=d) { return (e); t[g] = e; }
         else { return (d); t[g] = d; };
      };
      } else {
         return (t[g]);
   };
};

int main ()
{
   cin >> N ;
   k = new int[N];
   o = (N*N);
   t = new int[o];
   for (int I = 0 ; I!=N ; I++) cin >> k[I] ;
    memset(t, 0, o);
   total=(max(0,(N-1),0,0,0,0));
   cout << total ;
   return 0;
}