#include <stdio.h>
#define min(x,y) x<y?x:y;

int main(){

int best[2][22][80];
int N,oxy,nitro,o,n,w;

scanf("%d%d",&oxy,&nitro);
scanf("%d",&N);

for(int i=0;i<=oxy;i++)
    for(int j=0;j<=nitro;j++)
        best[0][i][j]=99999999;
best[0][0][0]=0;


for(int i=0,cur=1,prev=0;i<N;i++,cur=prev,prev=1-cur)
{
    scanf("%d%d%d",&o,&n,&w);
    for(int j=0;j<=oxy;j++)
        for(int k=0;k<=nitro;k++)
            best[cur][j][k]=best[prev][j][k];

    for(int j=0;j<=oxy;j++)
        for(int k=0;k<=nitro;k++)
        {
            int jj,kk;
            jj=min(oxy,j+o);
            kk=min(nitro,k+n);
            best[cur][jj][kk]=min(best[cur][jj][kk],best[prev][j][k]+w);
        }

    for(int j=oxy;j>=0;j--)
        for(int k=nitro;k>=0;k--)
        {
            if(j!=oxy)best[cur][j][k]=min(best[cur][j][k],best[cur][j+1][k]);
            if(k!=nitro)best[cur][j][k]=min(best[cur][j][k],best[cur][j][k+1]);
        }
}
printf("%d\n",best[N&1][oxy][nitro]);
}