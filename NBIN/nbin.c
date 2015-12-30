#include <stdio.h>
#include <string.h>

char k[66];

void toChar(unsigned long long int numero){

  int i;
  unsigned long long int test = 1;
  
  for(i=0;i<65;i++){k[i]=0;}

  for(i=0;i<65;i++){

    k[64-i]= numero&test?'1':'0';
    test = test<<1;

  }

}

int valid(){

  int i = 0;

  for(i=0;i<64;i++){
  if(k[i]=='1' && k[i+1]=='1'){return 0;}}

  return 1;

}

int main(){

  unsigned long long int i,j;
  i=0;j=0;

  k[65]=0;

  while(1){

    toChar(i);
    if(valid()){
      printf("%i -- %i -- %s\n",i,j,k+64-13);
      j++;
      getchar();
    }
    i++;

  }

}