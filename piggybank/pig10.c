#include <stdio.h>

typedef struct coin {
   unsigned int P;
   unsigned int W;
} coin;

unsigned int recur[10000];

unsigned int valmin(unsigned int *dif, unsigned int *N, coin *coins){
   if (*dif == 0){return 0;}
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

int main()
{
   unsigned int T, E, F, N,i,dif,res;
   coin coins[500];
   scanf("%d\n",&T);
   while(T--){
      scanf("%d %d\n%d",&E,&F,&N);
      for (i = 0; i<N ;i++){
         scanf("%d %d",&coins[i].P,&coins[i].W);
      }
      if (dif = F - E){
         for (i = 0; i<=dif; i++){recur[i] = 500000001;}
         res = valmin(&dif,&N,coins);
         if (res != 500000002){
            printf("The minimum amount of money in the piggy-bank is %i.\n", res);
         } else {printf("This is impossible.\n");}
      } else {printf("The minimum amount of money in the piggy-bank is 0.\n");}
   }
   return 0;
}