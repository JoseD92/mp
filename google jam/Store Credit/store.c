#include <stdio.h>
int main(){
   int casos, C, max, l[2000],i,j,z=1;
   scanf("%d",&casos);
   while (casos--)
   {
      scanf("%d\n%d",&C,&max);
      for(i = 0; i!=max;++i){
         scanf("%d",&l[i]);
      }
      i = 0;
      j = 1;
      --max;
      while((l[i]+l[j]) != C){
         j = j==max?++i+1:++j;
      }
      printf("Case #%i: %i %i\n",z++,++i,++j);
   }
}