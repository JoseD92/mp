#include <stdlib.h>
#include <stdio.h>

int main(){
  unsigned int algo[10][10],i,j;
  printf("%i\n",sizeof(algo));
  for(i=0;i<10;++i){
    for(j=0;j<10;++j){
      printf("%u\n",algo[i][j]);
    }
  }
  memset(algo,0xF0,sizeof(algo));
  for(i=0;i<10;++i){
    for(j=0;j<10;++j){
      printf("%u\n",algo[i][j]);
    }
  }
  printf("----%u\n",0xF0F0F0F0);
  printf
}