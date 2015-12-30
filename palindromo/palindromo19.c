#include <stdio.h>
#include <string.h>

int main()
{
   int casos,len,i,t,tmp,flag;
   char numero[1000002];
   scanf("%d\n",&casos);
   while (casos--)
   {
      gets(numero);
      len = strlen(numero);
      flag = 1;
      for(i=len; i;)
      {
         if(numero[--i] != '9')
         {
            flag = 0;
            break;
         }
      }
      if(flag)
      {
         numero[0] = '1';
         for(i=1; i<len; i++)
            numero[i] = '0';
         numero[len] = '1';
         numero[len+1] = '\0';
      } else {
         flag = 0;
         for(i=0; i<len/2; i++)
         {
            if(numero[i] < numero[len-i-1])
               flag = -1;
            else if(numero[i] > numero[len-i-1])
               flag = 1;
            numero[len-i-1] = numero[i];
         }
         if(flag == -1 || flag==0)
         {
            t = 0;
            if(len%2 == 0)
               tmp = len/2-1;
            else
               tmp = len/2;
            while(numero[tmp-t] == '9')
            {
               numero[len-1-tmp+t] = numero[tmp-t] = '0';
               t ++;
            }
            numero[tmp-t] ++;
            numero[len-1-tmp+t] = numero[tmp-t];
         }
      }
      printf("%s\n",numero);
   }
   return 0;
}