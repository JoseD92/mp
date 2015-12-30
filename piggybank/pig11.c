#include <stdio.h>

typedef struct coin {
   unsigned int P;
   unsigned int W;
   float O;
} coin;

unsigned int recur[10000];
coin coinsh[500];

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

unsigned int valmin2(unsigned int *dif, unsigned int *N, coin *coins,unsigned int *ll){
   unsigned int money, ww,respuesta,i,j;
   respuesta = 500000002;
   money = 0;
   ww = dif;
   i = 0;
   while()

if (ww = 0){return (money);}
   
return(respuesta);


void mezcla(coin *coins,unsigned int izq,unsigned int med,unsigned int der){
   unsigned int i = izq;
   unsigned int j = med;
   unsigned int z = 0;
   while (i != med && j != der){
      if (coins[i].O <= coins[j].O){
         coinsh[z++] = coins[i++];
      } else {
         coinsh[z++] = coins[j++];
      }
   }
   while (i != med){
      coinsh[z++] = coins[i++];
   }
   while (j != der){
      coinsh[z++] = coins[j++];
   }
   for (i = 0; i != z; i++){
      coins[i+izq] = coinsh[i];
   }
   return;
}

void ordenar(coin *coins,unsigned int izq,unsigned int der){
   if (der - izq >= 2){
      unsigned int med = (izq + der) / 2;
      ordenar(coins,izq,med);
      ordenar(coins,med,der);
      mezcla(coins,izq,med,der);
   } else {return;}
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
      for (i = 0; i<N ;i++){
         coins[i].O = (float) coins[i].P/(float) coins[i].W;
      }
      if (dif = F - E){
         ordenar(coins,0,N);
         for (i = 0; i<=dif; i++){recur[i] = 500000001;}
         res = valmin(&dif,&N,coins,0);
         if (res != 500000002){
            printf("The minimum amount of money in the piggy-bank is %i.\n", res);
         } else {printf("This is impossible.\n");}
      } else {printf("The minimum amount of money in the piggy-bank is 0.\n");}
   }
   return 0;
}