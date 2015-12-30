#include <stdio.h>

int main(){

  unsigned int matriz[201][201];
  unsigned int casos, n, i, j, z;
  
  scanf("%u",&casos);

  while(casos--){

    scanf("%u",&n);

    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        scanf("%u",&matriz[i][j]);
      }
    }

    for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++){

        for(z=0;z<n;z++){
          if(z==i || z==j){
            continue;
          }
          if(matriz[i][j] >= (matriz[z][i] + matriz[z][j])){
            goto no_ve;
          }
        }

        printf("%u %u\n",i+1,j+1);
        no_ve: continue;
      }
    }

  }

  return 0;

}