#include <iostream>
using namespace std;
long T, E, F, N, diferencia;
int* a = NULL;
int* b = NULL;
int* c = NULL;

int valmin (long X, long Y, long z, long v, long w, long l)
   {
      //valmin(X) = min(B[counter1] + valmin (X - C[counter1]))
      if (X == 0) {
         return (0);
      } else {
         if (a[X] == -1) {
      for ( z=0 ; z!=N ; z++){
         if (((X - (c[z]))) >= 0) {
             v = valmin((X - (c[z])),(Y + 1),0,0,0,-1);
             if (v >= 0) {
                 w = ((b[z]) + v);
                 if (l == (-1)) {
                      l = w;
                 } else {
                    if (w < l) {
                     l = w;
                    };
                 };
             };
         };
      };
      if (l == -1) {
         l = -2;
      };
      a[X] = l;
      return (l);
         } else {
             return (a[X]);
         };
      };
   };

int main ()
{
   cin >> T ;
      for (int K = 0 ; K!=T ; K++) {
      cin >> E >> F;//peso vacio-lleno
	  diferencia=(F - E);
	  cin >> N;//cantidad de monedas
      b = new int[N];
      c = new int[N]; 
      a = new int[(diferencia + 1)];
      for (int I = 0 ; I<=diferencia ; I++) a[I]=-1;
      for (int I = 0 ; I!=N ; I++) {cin >> b[I] >> c[I] ;}; //valor - peso
      if (diferencia != 0) {
         if (valmin(diferencia,0,0,0,0,-1) == -2) {
             cout << "This is impossible." << endl;
         } else {
             cout << "The minimum amount of money in the piggy-bank is " << a[diferencia] << "." << endl ;
         }
      } else {
         cout << "The minimum amount of money in the piggy-bank is o." << endl;
      };
     delete [] a; 
     a = NULL; 
     delete [] b; 
     b = NULL; 
     delete [] c; 
     c = NULL; 
   };
}