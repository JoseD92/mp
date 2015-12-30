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
struct point grafo[2500][5];
ui DijkstraPre[2500][2500];


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

ui Dijkstra(ui x1,ui y1,ui x2,ui y2){
  ui cola[2500][2];
  ui up, down,k,t;
  unsigned char bool[2500];

  if(x1==x2&&y1==y2) return 0;
  if(DijkstraPre[x1*50+y1][x2*50+y2]!=0xFFFFFFFF){
    return DijkstraPre[x1*50+y1][x2*50+y2];
  }
  memset(bool,0x00,sizeof(bool));
  up=0;
  down=1;
  cola[0][0]=x1*50+y1;
  cola[0][1]=0;
  bool[x1*50+y1]=1;
  while(1){
    k=0;
    while(grafo[cola[up][0]][k].x!=51){
      if(!(grafo[cola[up][0]][k].x==x2&&grafo[cola[up][0]][k].y==y2)){
        t=grafo[cola[up][0]][k].x*50+grafo[cola[up][0]][k].y;
        if(!bool[t]){
          bool[t]=1;
          cola[down][0]=t;
          cola[down++][1]=cola[up][1]+1;
          DijkstraPre[x1*50+y1][t]=cola[up][1]+1;
        }
      } else {
        return DijkstraPre[x1*50+y1][x2*50+y2]=cola[up][1]+1;
      }
      ++k;
    }
    ++up;
    if(up==down){
      return DijkstraPre[x1*50+y1][x2*50+y2]=1000001;
    }
  }
  return cola[up][1]+1;
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
    temp2=dp[tam][(help->p).x][(help->p).y]+Dijkstra(x,y,(help->p).x,(help->p).y);
    temp=temp<=temp2?temp:temp2;
    help=help->next;
  }
  return temp+1;
}

int main(){

  ui i,j,z,k;
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
    memset(DijkstraPre,0xFF,sizeof(DijkstraPre));
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

        k=0;
        z=j;
        while(z<c){
          if(teclado[i][j]!=teclado[i][z]) break;
          z++;
        }
        if(z<c) {
          grafo[i*50+j][k].x=i;
          grafo[i*50+j][k++].y=z;
        }
        z=j;
        while(z>0){
          z--;
          if(teclado[i][j]!=teclado[i][z]) break;
        }
        if(z>0){
          grafo[i*50+j][k].x=i;
          grafo[i*50+j][k++].y=z;
        }
        else{
          if(teclado[i][j]!=teclado[i][z]){
            grafo[i*50+j][k].x=i;
            grafo[i*50+j][k++].y=z;
          }
        }

        z=i;
        while(z<r){
          if(teclado[i][j]!=teclado[z][j]) break;
          z++;
        }
        if(z<r){
          grafo[i*50+j][k].x=z;
          grafo[i*50+j][k++].y=j;
        }
        z=i;
        while(z>0){
          z--;
          if(teclado[i][j]!=teclado[z][j]) break;
        }
        if(z>0){
          grafo[i*50+j][k].x=z;
          grafo[i*50+j][k++].y=j;
        }
        else{
          if(teclado[i][j]!=teclado[z][j]){
            grafo[i*50+j][k].x=z;
            grafo[i*50+j][k++].y=j;
          }
        }
        grafo[i*50+j][k].x=51;
        grafo[i*50+j][k++].y=51;
      }
    }

    printf("%u\n",resolver(0,0,ptam));

    freenodos1(lista);
  }

  return 0;
}