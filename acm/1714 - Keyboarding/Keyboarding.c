#include <stdio.h>
#include <string.h>

typedef unsigned int ui;

struct point{
ui x;
ui y;
};

struct nodo2{
struct point p;
struct nodo2 *next;
};

struct nodo1{
char c;
struct nodo2 *lugares;
struct nodo1 *next;
};

void freenodos2(struct nodo2 *in){
  struct nodo2 *help;
  while(in != NULL){
    help = in->next;
    free(in);
    in = help;
  }
}

void freenodos1(struct nodo1 *in){
  struct nodo1 *help;
  while(in != NULL){
    help = in->next;
    freenodos2(in->lugares);
    free(in);
    in = help;
  }
}

char teclado[50][51];
ui dp[10001][50][50];
ui r,c,ptam;
char palabra[10001];
struct nodo1 *lista;
unsigned char alcance[2500][2500];


struct nodo1 *find(char c){
  struct nodo1 *help;
  help=lista;
  while (help!=NULL){
    if(help->c==c) return help;
    help=help->next;
  }
  return NULL;
}

struct nodo2 *placepoint(ui x, ui y, struct nodo2 *in){
  struct nodo2 *help;
  help = (struct nodo2 *)malloc(sizeof(struct nodo2));
  (help->p).x=x;
  (help->p).y=y;
  help->next=in;
  return help;
}

ui resolver(ui x, ui y, ui tam){
  ui temp = 0xFFFFFFFF;
  ui temp2;
  struct nodo2 *help;
  help = (find(palabra[ptam-tam]))->lugares;
  while(help!=NULL){
    if(dp[tam][(help->p).x][(help->p).y]==0xFFFFFFFF){
      dp[tam][(help->p).x][(help->p).y]=resolver((help->p).x,(help->p).y,tam-1);
    }
    temp2=dp[tam][(help->p).x][(help->p).y]+alcance[x*50+y][(help->p).x*50+(help->p).y];
    temp=temp<=temp2?temp:temp2;
    help=help->next;
  }
  return temp+1;
}

int main(){

  ui i,j,z;
  struct nodo1 *nodo1H;

  while(1){
    if(scanf("%u %u",&r,&c)<2) break;
    for(i=0;i<r;i++){
      scanf("%s",teclado[i]);
    }
    scanf("%s",palabra);
    ptam=strlen(palabra);
    palabra[ptam]='*',
    memset(dp,0xFF,sizeof(dp));
    memset(alcance,0xFF,sizeof(alcance));
    lista=NULL;
    for(i=0;i<r;i++){
      for(j=0;j<c;j++){
        dp[0][i][j]=0;
        nodo1H=find(teclado[i][j]);
        if(nodo1H!=NULL){
          nodo1H->lugares=placepoint(i,j,nodo1H->lugares);
        } else {
          nodo1H=(struct nodo1 *)malloc(sizeof(struct nodo1));
          nodo1H->c=teclado[i][j];
          nodo1H->lugares=placepoint(i,j,NULL);
          nodo1H->next=lista;
          lista=nodo1H;
        }
        alcance[i*2500+j][i*2500+j]=0;

        z=j;
        while(z<c){
          if(teclado[i][j]!=teclado[i][z]) break;
          z++;
        }
        if(z<c) alcance[i*50+j][i*50+z]=1;
        z=j;
        while(z>0){
          z--;
          if(teclado[i][j]!=teclado[i][z]) break;
        }
        if(z>0) alcance[i*50+j][i*50+z]=1;
        else{
          if(teclado[i][j]!=teclado[i][z]) alcance[i*50+j][i*50+z]=1;
        }

        z=i;
        while(z<r){
          if(teclado[i][j]!=teclado[z][j]) break;
          z++;
        }
        if(z<r) alcance[i*50+j][z*50+j]=1;
        z=i;
        while(z>0){
          z--;
          if(teclado[i][j]!=teclado[z][j]) break;
        }
        if(z>0){ alcance[i*50+j][z*50+j]=1;}
        else{
          if(teclado[i][j]!=teclado[z][j]) alcance[i*50+j][z*50+j]=1;
        }
      }
    }
printf("pre\n");
    for(i=0;i<2500;i++){
      for(j=0;j<2500;j++){
        if(i!=j){
          for(z=0;z<2500;z++){
            if(alcance[j][z]>alcance[j][i]+alcance[i][z]){
              alcance[j][z]=alcance[j][i]+alcance[i][z];
            }
          }
        }
      }
    }
printf("post\n");
    printf("%u\n",resolver(0,0,ptam));

    freenodos1(lista);
  }

  return 0;
}