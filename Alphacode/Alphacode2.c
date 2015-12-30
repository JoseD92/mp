#include <stdio.h>

int main()
{
   unsigned long long int respuesta, a, b;
   int i;
   char string[5012];
   char* point;

   gets(string);

   while(string[0]!='0' || string[1]!=0){
      respuesta = 0;

      if(string[0]!='0'){
         point = string;
         respuesta = 1; a = 1; b =1;
         --point;
         for(i=0;1;++i){
            ++point;
            if(*point==0){break;}
            if(*point > '2'){
               continue;
            }
            if(*point > '0' && *point < '3'){
               if(*(point+1) == '0'){
                  respuesta*=b;
                  a = 1; b =1;
                  continue;
               }
               if(*(point+1) == '1' || *(point+1) == '2'){
                  a=b+a;
                  b=a-b;
                  continue;
               }
               if(*(point+1) == 0){
                  respuesta*=a;
                  break;
               }
               if(*point == '2' && *(point+1) > '6'){
                  respuesta*=a;
                  a = 1; b =1;
                  continue;
               }
               a=b+a;
               respuesta*=a;
               a = 1; b =1;
               continue;
            }
            if(*point == '0'){
               if(!(*(point-1) == '1' || *(point-1) == '2')){
                  respuesta = 0;
                  break;
               }
            }
         }
      }

      printf("%llu\n",respuesta);
      gets(string);
   }
   return 0;
}