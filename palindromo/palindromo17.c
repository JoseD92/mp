#include <stdio.h>
#include <string.h>

int main(){
   char numeros[1000001];
   // char *c;
   // char *d;
   unsigned int casos, sumar, j, tam, mitad, p, l;
   char ceros[1000002];
   //long *l;

   // for (l = ceros; l != ceros+1000008; l++){
      // *l = 808464432;
   // };
   
   j = 1000002;
   while(--j){ceros[j] = 48;};
   ceros[j] = 49;

   scanf("%i",&casos);
   while (casos--){
      scanf("%s",numeros);
      tam = strlen(numeros);

         if (tam == 1){
            if (numeros[0] != 57){
            numeros[0]+=1; printf("%s\n",numeros);
            } else { printf("11\n");
            };
         } else {
            if (!(tam % 2)){
               mitad = (tam-1) / 2;
               sumar = 1;
               // c = &numeros[mitad];
               // d = c+1;
               // j = 0;
               // while ((*c == 57) && (*d == 57)){
                  // c--; d++; j++;
               // };

               // while ((mitad-j)&&(*c == *d)){
                  // c--; d++; j++;
               // };
               // if (*c > *d) {sumar = 0;};
               l = (p = mitad) + 1; j = 0;
               while ((numeros[p] == 57)&&(numeros[l] == 57)){p--;l++;j++;};
 
               while ((mitad-j)&&(numeros[p]==numeros[l])){p--;l++;j++;};
               if (numeros[p] > numeros[l]) {sumar = 0;};
            
               if (numeros[l]) {

               // c = &numeros[mitad];
               // d = c+1;
               // j = 0;
               // while (sumar){
                  // if (*c != 57){
                     // *d = *c = *c+1; sumar = 0;
                  // } else {
                     // *d = *c = 48;
                  // };
                  // c--;d++;j++;
              // };

              // for (j=j;j<=mitad;j++){
                  // *d=*c;c--;d++;
               // };

               l = (p = mitad) + 1; j = 0;
               while (sumar){
                  if (numeros[p] != 57){ numeros[p] += 1; numeros[l++] = numeros[p--]; sumar = 0; }
                  else {numeros[l++] = numeros[p--] = 48;};
                  j++;
               };
               for (j=j;j<=mitad;j++){numeros[l++] = numeros[p--];};

               printf("%s\n",numeros);
               } else {
                  ceros[tam] = 49;
                  ceros[tam+1] = 0;
                  printf("%s\n",ceros);
                  ceros[tam] = 48;
                  ceros[tam+1] = 48;
               };
  
            } else {
               mitad = (tam) / 2;
               sumar = 1;
               // c = &numeros[mitad];
               // d = c;
               // j = 0;
               // while ((*c == 57) && (*d == 57)){
                  // c--; d++; j++;
               // };

               // while ((mitad-j)&&(*c == *d)){
                  // c--; d++; j++;
               // };
               // if (*c > *d) {sumar = 0;};
            
               l = p = mitad; j = 0;
               while ((numeros[p] == 57)&&(numeros[l] == 57)){p--;l++;j++;};
 
               while ((mitad-j)&&(numeros[p]==numeros[l])){p--;l++;j++;};
               if (numeros[p] > numeros[l]) {sumar = 0;};
            
               if (numeros[l]) {
               // c = &numeros[mitad];
               // d = c;
               // j = 0;
               // while (sumar){
                  // if (*c != 57){
                     // *d = *c = *c+1; sumar = 0;
                  // } else {
                     // *d = *c = 48;
                  // };
                  // c--;d++;j++;
               // };

               // for (j=j;j<=mitad;j++){
                  // *d=*c;c--;d++;
               // };

               l = p = mitad; j = 0;
               while (sumar){
                  if (numeros[p] != 57){ numeros[p] += 1; numeros[l++] = numeros[p--]; sumar = 0; }
                  else {numeros[l++] = numeros[p--] = 48;};
                  j++;
               };
               for (j=j;j<=mitad;j++){numeros[l++] = numeros[p--];};

               printf("%s\n",numeros);
               } else {
         ceros[tam] = 49;
         ceros[tam+1] = 0;
         printf("%s\n",ceros);
         ceros[tam] = 48;
         ceros[tam+1] = 48;
               };
            };
         };
      };

   return 0;
}