#include <stdio.h>
#define INF 800001
#define min(x,y) x<y?x:y

typedef unsigned int ui;

struct tanque {
  unsigned char ox;
  unsigned char ni;
  unsigned short w;
};

struct tanque leidos[1000];
int casos, demOx, demNi,tanques;
int bt[2][22][80];

int main(){
   int z,i,j,k,l,anterior,actual;
   char *t;
   struct tanque *tq;

  scanf("%i",&casos);
  while(casos--){
    scanf("%i %i\n%i",&demOx,&demNi,&tanques);
    i=0;
    t = (char*)leidos;
    while(i<tanques){
      scanf("%hhu %hhu %hu",t,t+1,t+2);
      ++i;
      t+=4;
    }

    for(i=0;i<=demOx;i++){
      for(j=0;j<=demNi;j++){
        bt[0][i][j]=INF;
      }
    }
    bt[0][0][0]=0;
    tq=leidos;anterior=0;actual=1;z=0;
    while(z<tanques){
      for(i=0;i<=demOx;i++){
        for(j=0;j<=demNi;j++){
          k=tq->ox>i?0:i-tq->ox;
          l=tq->ni>j?0:j-tq->ni;
          k=bt[anterior][k][l]+tq->w;
          bt[actual][i][j]=min(bt[anterior][i][j],k);
        }
      }

      anterior=anterior^actual;
      actual=anterior^actual;
      anterior=anterior^actual;
      tq++;z++;
    }

    printf("%i\n",bt[tanques&1][demOx][demNi]);
  }

  return 0;
}