#include <stdio.h>

int main()
{
   unsigned long long int a, b, c, d, k, respuesta;
   while(1){
      printf("\nEntre K y N:");
      scanf("%llu %llu",&k,&c);
      respuesta = c;
      a = 1; b = 0; d = 1;
      while(k){
         while(--c){
            a = a + b;
            b = a - b;
         }
         c = a - d;
         d = a;
         --k;
         respuesta = a;
printf("%llu %llu %llu\n",k,d,c);
      }
      printf("%llu\n",respuesta);
   }
}