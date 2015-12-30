#include <stdio.h>

typedef unsigned int ui;

unsigned char ox[1000], ni[1000];
unsigned short w[1000];
ui casos, demOx, demNi,tanques, mejor;

void resuelve(ui actual, ui oxa, ui nia, ui wa){
  ui noxa, nnia, nwa, i;
  if (wa > mejor) return;
  if (oxa>=demOx && nia>=demNi){
    mejor=wa;
    return;
  }
  i = actual;
  while(i<tanques){
    noxa = oxa+ox[i];
    nnia = nia+ni[i];
    nwa = wa+w[i];
    resuelve(i+1,noxa,nnia,nwa);

    ++i;
  }
  return;
}

int main(){
   ui i;

  scanf("%u",&casos);

  while(casos--){
    mejor=0xFFFFFFFF;
    scanf("%u %u\n%u",&demOx,&demNi,&tanques);
    i=0;
    while(i<tanques){
      scanf("%hhu %hhu %hu",ox+i,ni+i,w+i);
      ++i;
    }
    resuelve(0,0,0,0);
    printf("%u\n",mejor);
  }

  return 0;
}