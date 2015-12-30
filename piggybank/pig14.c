#include <stdio.h>

unsigned int c[500][10000],p[500],w[500];

unsigned int valmin(unsigned int *dif, unsigned int *N){
   unsigned int i,j,tmp1,tmp2;
   for (i =1;i<*N;i++){
      for(j=1;j<*dif;j++){
         if(w[i]>j){c[i][j] = c[i-1][j];}
         else{
            tmp1 = p[i] + c[i-1][j-w[i]];
            tmp2 = c[i-1][j];
            if(tmp1 > tmp2){c[i][j] = tmp1;}
            else {c[i][j] = tmp2;}
         }
      }
   }
   return(c[*N][*dif]);
}

int main()
{
   unsigned int T, E, F, N,i,j,dif,res;
   scanf("%d\n",&T);
   for (i=0;i<500;i++){c[i][0] = 0;}
   for (i=0;i<10000;i++){c[0][i] = 0;}
   while(T--){
      scanf("%d %d\n%d",&E,&F,&N);
      for (i = 0; i<N ;i++){
         scanf("%d %d",&p[i],&w[i]);
      }
      if (dif = F - E){
         res = valmin(&dif,&N);
         if (res != 500000002){
            printf("The minimum amount of money in the piggy-bank is %i.\n", res);
            for (i=0;i<N;i++){for (j=0;j<dif;j++){printf("%i ",c[i][j]);}}
         } else {printf("This is impossible.\n");}
      } else {printf("The minimum amount of money in the piggy-bank is 0.\n");}
   }
   return 0;
}