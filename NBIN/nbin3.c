#include <stdio.h>
#include <string.h>

int main(){

  int casos, x;
  unsigned long long int i,j, respuesta, input;
  unsigned long long int fib[71];
  unsigned long long int pos[65];
  char k[65];
  char *l;

  k[64] = 0;

  k[63] = '0';

  fib[0] = fib[1] = 1;
  for(i=2;i<71;i++){fib[i]=fib[i-1]+fib[i-2];}

  pos[0]=1;
  pos[1]=1;
  for(i=2;i<65;i++){pos[i]=pos[i-1]<<1;}

//for(i=0;i<71;i++){printf("%llu ",fib[i]);}
//printf("\n\n");
//for(i=0;i<64;i++){printf("%llu ",pos[i]);}

  scanf("%i",&casos);
  while(casos--){

    respuesta = 0;

    scanf("%llu",&input);

    while(1){
      if(input==0){
        break;
      }
      if(input==1){
        respuesta += 1;
        break;
      }
      if(input==2){
        respuesta += 2;
        break;
      }

      for(x=0;fib[x+1]<=input;x++){}
printf("%llu --- %llu -- %i\n",respuesta,fib[x],x);
      respuesta+=pos[x];

      input -= fib[x];
    }

    j=1;
    l=k+63;
    for(x=63;x>=0;x--){

      if(respuesta & j){
         k[x]='1';
         l=k+x;
      } else {
         k[x]='0';
      }
      j=j<<1;

    }

    printf("%s\n\n",l);

  }


}
