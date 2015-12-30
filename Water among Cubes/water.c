#include <stdlib.h>
#include <stdio.h>

unsigned int tamano[10000];
//se accede con tamano[x+y*100]
unsigned int derramable[10000];
unsigned int pila[10000];
unsigned int cola[10000];
char linea[250];

int main(){
  unsigned int i, j, k, ancho, alto, casos;
  unsigned int *ii;

  // for(i=0;i<100;++i){
    // derramable[];
  // }
  // for(i=100;i<10000;i+=100){
    // derramable[];
  // }

  scanf("%d\n",&casos);

  while (casos--)
  {
    scanf("%d %d",&alto, &ancho);
    if(alto<3 || ancho <3){ //no hay manera de almacenar agua
      printf("0\n");
      for(;alto;--alto){//leyendo lineas basura
        gets(linea);
      }
      continue;
    }

    k=alto*ancho; //lleyendo lineas cuando se puede almacenar
    ii = &tamano;
printf("__%u__",k);
    while(k--){
      scanf("%u",ii);
      ++ii;
      printf("%u",*ii);
    }

    j=0; 
    while(alto!=j){
      for(i=0;i<ancho;++i){
        printf("%u ",tamano[i+j*100]);
      }
      printf("\n");
      ++j;
    }

    
  }
  
}