#include <stdio.h>
#include <string.h>

int main(){
   int casos;
   char *numeros = (double *)malloc(10000000);
   char *c;
   char *d;
   int sumar;
   int resolver[10001][2];
   int i;
   int j;
   int z = 0;
   int tam = 0;
   int tam2;
   int mitad;
   scanf("%i",&casos);

   for (i=0 ; i < casos-1 ; i++){
      scanf("%s",numeros+tam);
      c = numeros+tam;
      while (*c == 57){
         c++;
      };
      j = 0;
      // gets(numeros+tam);
      if (c == (numeros+strlen(numeros))){
         numeros[tam] = 49;
         for(j=tam+1;j<tam+strlen(numeros+tam);j++){
            numeros[j] = 48;
         };
         numeros[j] = 49;
         numeros[j+1] = 0;
      }
      tam2 = tam;
      tam += strlen(numeros+tam);
      numeros[tam++] = 10;
      if (!j){
         resolver[z][0] = tam2;
         resolver[z][1] = tam-2;
         z++;
      };
   };
   scanf("%s",numeros+tam);
      c = numeros+tam;
      while (*c == 57){
         c++;
      };
      j = 0;
      // gets(numeros+tam);
      if (c == (numeros+strlen(numeros))){
         numeros[tam] = 49;
         for(j=tam+1;j<tam+strlen(numeros+tam);j++){
            numeros[j] = 48;
         };
         numeros[j] = 49;
         numeros[j+1] = 0;
      }
      tam2 = tam;
      tam += strlen(numeros+tam);
      numeros[tam++] = 10;
      if (!j){
         resolver[z][0] = tam2;
         resolver[z][1] = tam-2;
         z++;
      };

   for (i = 0 ; i < z ; i++){
      if (resolver[i][0] == resolver[i][1]){
         numeros[resolver[i][0]]+=1;
      } else {
         if (((resolver[i][1]-resolver[i][0]+1) % 2) == 0){
            mitad = (resolver[i][1]-resolver[i][0]-1) / 2;
            sumar = 1;
            c = &numeros[resolver[i][0]+mitad];
            d = c+1;
            j = 0;
            while ((j<mitad)&&(*c == *d)){
               c--; d++; j++;
            };
            if (*c > *d) {sumar = 0;};
            
            c = &numeros[resolver[i][0]+mitad];
            d = c+1;
            j = 1;
            while (sumar){
               if (*c != 57){
                  *d = *c = *c+1; sumar = 0;
               } else {
                  *d = *c = 48;
               };
               c--;d++;j++;
            };

            for (j=j;j<=mitad;j++){
               *d=*c;c--;d++;
            };

         } else {
            mitad = (resolver[i][1]-resolver[i][0]+1) / 2;
            sumar = 1;
            c = &numeros[resolver[i][0]+mitad-1];
            d = c+2;
            j = 0;
            while ((j<mitad)&&(*c == *d)){
               c--; d++; j++;
            };
            if (*c > *d) {sumar = 0;};
            
            c = &numeros[resolver[i][0]+mitad];
            d = c;
            j = 0;
            while (sumar){
               if (*c != 57){
                  *d = *c = *c+1; sumar = 0;
               } else {
                  *d = *c = 48;
               };
               c--;d++;j++;
            };

            for (j=j;j<=mitad;j++){
               *d=*c;c--;d++;
            };

         };
      };
   };
   printf("%s",numeros);
   return 0;
}