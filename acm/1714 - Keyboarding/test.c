#include <stdio.h>
#include <string.h>

typedef unsigned int ui;

ui r,c,ptam;
char teclado[50][51];
char palabra[10001];

int main(){

  ui i,j,z,k;
  struct nodo1 *nodo1H;

  while(1){
    if(scanf("%u %u",&r,&c)<2) break;
    for(i=0;i<r;i++){
      scanf("%s",teclado[i]);
    }
    scanf("%s",palabra);
    ptam=strlen(palabra);
    printf("%u\n",ptam);
  }
  return 0;
}