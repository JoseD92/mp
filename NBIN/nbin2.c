#include <stdio.h>
#include <string.h>

int main(){

  int casos, x, flag;
  unsigned long long int i,j, input;
  unsigned long long int fib[76];
  //unsigned long long int pos[65];
  char k[97];
  char *l;

  k[96] = 0;

  fib[0] = fib[1] = 1;
  for(i=2;i<76;i++){fib[i]=fib[i-1]+fib[i-2];}

  //pos[0]=1;
  //pos[1]=1;
  //for(i=2;i<65;i++){pos[i]=pos[i-1]<<1;}

//for(i=0;i<76;i++){printf("%llu ",fib[i]);}
//printf("\n\n");
//for(i=0;i<64;i++){printf("%llu ",pos[i]);}

  scanf("%i",&casos);
  while(casos--){

    scanf("%llu",&input);

    l = k+95;
    flag = 1;
    for(x=0;x<96;x++){k[x]='0';}

    while(1){
      if(input==0){
        break;
      }
      if(input==1){
        k[95]='1';
        if(flag){
          l = k+95;
          flag = 0;
        }
        break;
      }
      if(input==2){
        k[94]='1';
        if(flag){
          l = k+94;
          flag = 0;
        }
        break;
      }

      for(x=0;fib[x+1]<=input;x++){}

      k[96-x]='1';
      if(flag){
        l = k+96-x;
        flag = 0;
      }

      input -= fib[x];
    }

    printf("%s\n\n",l);

  }


}
