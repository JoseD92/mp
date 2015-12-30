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
ui caso, demOx, demNi,tanques;
ui bt[1000][22][80], fl[1000][22][80];

unsigned int sol(ui num, ui oxi, ui ni){
  ui ii,jj;
  if(oxi>=demOx && ni>=demNi) return 0;
  if(num==tanques) return INF;
  if(oxi>demOx) oxi=demOx;
  if(ni>demNi) ni=demNi;
  if(fl[num][oxi][ni]==caso) return bt[num][oxi][ni];
  fl[num][oxi][ni]=caso;
  ii = sol(num+1,oxi,ni);
  jj = sol(num+1,oxi+leidos[num].ox,ni+leidos[num].ni)+leidos[num].w;
  return bt[num][oxi][ni] = min(ii,jj);
}

int main(){
   ui i, cs;
   char *t;

  scanf("%u",&cs);
  memset(fl,0x00,sizeof(fl));
  for(caso=1;caso<=cs;caso++){

    scanf("%u %u\n%u",&demOx,&demNi,&tanques);
    i=0;
    t = (char*)leidos;
    while(i<tanques){
      scanf("%hhu %hhu %hu",t,t+1,t+2);
      ++i;
      t+=4;
    }

    printf("%u\n",sol(0,0,0));
  }

  return 0;
}