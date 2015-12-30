#include <iostream>
using namespace std;
long N, total;
int* t = NULL;
int* k = NULL;

int max (long a, long b, long c, double d, double e)
{
   c=(c+1);
   if (t[a,b]==-1) {
      if (a == b) {return (k[a]*c); }
      else {
         d = ((k[a])*c + max ((a+1),b,c,0,0));
         e = ((k[b])*c + max (a,(b-1),c,0,0));
         if (e>=d) { return (e); t[a,b] = e; }
         else { return (d); t[a,b] = d; };
      };
      } else {
         return (t[a,b]);
   };
};

int main ()
{
   cin >> N ;
   k = new int[N];
   t = new int[N,N];
   for (int I = 0 ; I!=N ; I++) cin >> k[I] ;
   for (int y = 0 ; y!=N ; y++) {
         for (int j = 0 ; j!=N ; j++) {t[y,j] = -1;} ;
   };
   total=(max(0,(N-1),0,0,0));
   cout << total ;
     delete [] k; 
     k = NULL; 
     delete [] t; 
     t = NULL; 
}