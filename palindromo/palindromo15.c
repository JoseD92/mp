#include <stdio.h>
#include <string.h>

int main(){
   int casos;
   char numeros[1000009];
   char *c;
   char *d;
   int sumar;
   int i;
   int j;
   int tam = 0;
   int mitad;
   scanf("%i",&casos);

   for (i=0 ; i < casos ; i++){
      scanf("%s",numeros);
      tam = strlen(numeros);
      c = numeros;
      while (*c == 57){
         c++;
      };
      if (c == (numeros+tam)){
         numeros[0] = 49;
         for(j=1;j<tam;j++){
            numeros[j] = 48;
         };
         numeros[j] = 49;
         numeros[j+1] = 0;
      // if (c == (numeros+tam)){
         // *numeros = 49;
         // for(c=numeros+1;c!=(numeros+tam);c++){
            // *c = 48;
         // };
         // numeros[tam] = 49;
         // numeros[tam+1] = 0;
      } else {

         if (tam == 1){
            numeros[0]+=1;
         } else {
            if ((tam % 2) == 0){
               mitad = (tam-1) / 2;
               sumar = 1;
               c = &numeros[mitad];
               d = c+1;
               j = 0;
               while ((j<mitad)&&(*c == *d)){
                  c--; d++; j++;
               };
               if (*c > *d) {sumar = 0;};
            
               c = &numeros[mitad];
               d = c+1;
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

            } else {
               mitad = (tam) / 2;
               sumar = 1;
               c = &numeros[mitad-1];
               d = c+2;
               j = 0;
               while ((j<mitad)&&(*c == *d)){
                  c--; d++; j++;
               };
               if (*c > *d) {sumar = 0;};
            
               c = &numeros[mitad];
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
   printf("%s\n",numeros);
   };

   return 0;
}