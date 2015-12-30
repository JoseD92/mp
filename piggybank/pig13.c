#include <stdio.h>

//optimizado, sacando el maximo comun divisor de todos los pesos

typedef struct coin {
   unsigned int P;
   unsigned int W;
} coin;

unsigned int recur[10000];

unsigned int valmin(unsigned int *dif, unsigned int *N, coin *coins){
   if (recur[*dif] == 500000001) {
      unsigned int respuesta = 500000002;
      unsigned int i, temp, dift;
      for (i = 0 ; i < *N; i++){
         if (coins[i].W <= *dif){
            dift = *dif - coins[i].W;
            temp = valmin(&dift,N,coins);
            if (temp != 500000002){
               temp += coins[i].P;
               if (temp < respuesta){ respuesta = temp;};
            };
         };
      };
      return (recur[*dif] = respuesta);
   } else {return (recur[*dif]);}
}

unsigned int MCD(unsigned int x, unsigned int y){
   unsigned int b = 1;
   while(x != y){
      if (x < y){y -= x;}
      else {x -= y;}
   }
   return(x);
}

int main()
{
   unsigned int T, E, F, N,i,dif,res,mcd;
   coin coins[500];
   recur[0] = 0;
   scanf("%d\n",&T);
   while(T--){
      scanf("%d %d\n%d",&E,&F,&N);
      dif = F - E;
      scanf("%d %d",&coins[0].P,&coins[0].W);
      mcd = MCD(coins[0].W,dif);
      for (i = 1; i<N ;i++){
         scanf("%d %d",&coins[i].P,&coins[i].W);
         mcd = MCD(coins[i].W,mcd);
      }
      if (dif){
         dif = dif/mcd;
         for (i = 0; i<N ;i++){coins[i].W = coins[i].W/mcd;}
         for (i = 1; i<=dif; i++){recur[i] = 500000001;}
         res = valmin(&dif,&N,coins);
         if (res != 500000002){
            printf("The minimum amount of money in the piggy-bank is %i.\n", res);
         } else {printf("This is impossible.\n");}
      } else {printf("The minimum amount of money in the piggy-bank is 0.\n");}
   }
   return 0;
}