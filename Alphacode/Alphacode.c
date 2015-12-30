#include <stdio.h>
#include <string.h>

int main()
{
   int tam;
   unsigned long long int respuesta, a, b;
   int i;
   char string[5012];
   char* point;

   gets(string);
   tam = strlen(string);

   while(string[0]!='0' || tam!=1){
      respuesta = 0;

      if(string[0]!='0'){
         point = string;
         point+=tam;
         string[tam]='9';
         respuesta = 1; a = 1; b =1;
         for(i=tam-1;i>=0;--i){
            --point;
            if(*point > '6'){
               if(i && *(point-1) == '1'){
                  a=b+a;
                  b=a-b;
                  continue;
               }
               respuesta*=a;
               a = 1; b =1;
               continue;
            }
            if(*point > '2' && *point < '7'){
               if(i && (*(point-1) == '1' || *(point-1) == '2')){
                  a=b+a;
                  b=a-b;
                  continue;
               }
               respuesta*=a;
               a = 1; b =1;
               continue;
            }
            if(*point > '0' && *point < '3'){
               if(*(point+1) == '0'){continue;}
               if(i && (*(point-1) == '1' || *(point-1) == '2')){
                  a=b+a;
                  b=a-b;
                  continue;
               }
               respuesta*=a;
               a = 1; b =1;
               continue;
            }
            if(*point == '0'){
               respuesta*=a;
               a = 1; b =1;
               if(!(*(point-1) == '1' || *(point-1) == '2')){
                  respuesta = 0;
                  break;
               }
            }
         }
      }

      printf("%llu\n",respuesta);
      gets(string);
      tam = strlen(string);
   }
   return 0;
}