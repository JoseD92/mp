#include <stdio.h>
#include <string.h>

char matriz[2048][4098];

int power(int base, int exp){
  int out = 1;
  while(exp--){out*=base;}
  return out;
}

void triangula(int maxDeep, int deep, int pos, int bool1, int bool2){

  if(deep == maxDeep){return;}

  matriz[deep][pos] = '/';
  matriz[deep][pos+1] = '\\';
  matriz[deep+1][pos-1] = '/';
  matriz[deep+1][pos] = '_';
  matriz[deep+1][pos+1] = '_';
  matriz[deep+1][pos+2] = '\\';

  if(((deep/2)%2)==0){
    triangula(maxDeep,deep+2,pos-2,1,0);
    triangula(maxDeep,deep+2,pos+2,0,1);
  } else {
    if(bool1){

    }
    if(bool1){

    }
  }

  return;

}

int main(){

  int n, i ,j;

  scanf("%i",&n);
  while(n!=0){

    for(i=0;i<power(2,n);i++){
      for(j=0;j<4*power(2,n-1);j++){
        matriz[i][j] = ' ';
      }
    }

    triangula(power(2,n+1),0,(power(2,n+1)/2)-1,1,1);

    for(i=0;i<(power(2,n));i++){
      matriz[i][power(2,n+1)] = '\n';
      matriz[i][power(2,n+1)+1] = '\0';
      printf("%s",matriz[i]);
    }

    scanf("%i",&n);
  }

}