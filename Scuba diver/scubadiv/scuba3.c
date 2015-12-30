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
int bt[1000][22][80];

int sol(int num, int oxi, int ni){
  ui ii,jj;
  if(oxi>=demOx && ni>=demNi) return 0;
  if(num==tanques) return INF;
  if(oxi>demOx) oxi=demOx;
  if(ni>demNi) ni=demNi;
  if(bt[num][oxi][ni]!=0xFFFFFFFF) return bt[num][oxi][ni];
  ii = sol(num+1,oxi,ni);
  jj = sol(num+1,oxi+leidos[num].ox,ni+leidos[num].ni)+leidos[num].w;
  return bt[num][oxi][ni] = min(ii,jj);
}

int main(){
   ui i;
   char *t;

  scanf("%i",&casos);
  while(casos--){
    memset(bt,0xFF,sizeof(bt));
    scanf("%i %i\n%i",&demOx,&demNi,&tanques);
    i=0;
    t = (char*)leidos;
    while(i<tanques){
      scanf("%hhu %hhu %hu",t,t+1,t+2);
      ++i;
      t+=4;
    }

    printf("%i\n",sol(0,0,0));
  }

  return 0;
}