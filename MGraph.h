#include<Usual.h>
#define INT_MAX (unsigned)-1

/*
邻接矩阵法，容易确定任意两个顶点之间是否有边相连O(1)，也容易确定无向图中每个点的度或者有向图中每个点的出度和入度O(n)。
但对于遍历图的每个边不友好O(n^2)，是矩阵法的局限性。所以边稠密的图适合矩阵法。
*/
typedef char VertexType;
typedef int  EdgeType;

typedef struct{
    VertexType  Vex[MaxVertexNum];
    EdgeType    Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGragh;

void Print(MGragh M);
int locateVex(MGragh &M,char v2);
void InitMGragh(MGragh &M);
void CreateUndirMGragh(MGragh &M);
void CreateDirMGragh(MGragh &M);



void InitMGragh(MGragh &M){
    int i,j;
    for(i=0; i<M.vexnum; i++){
        for(j=0; j<M.vexnum; j++){
            M.Edge[i][j] = 0;
        }
    }
}
void CreateUndirMGragh(MGragh &M){
    printf("Input 'vexNum,arcNum' : ");
    scanf(" %d,%d",&M.vexnum,&M.arcnum);
    InitMGragh(M);

    printf("\nInput vex:\n");
    int i;
    for(i=0; i<M.vexnum; i++){
        scanf(" %c",&M.Vex[i]);
    }

    char head,tail;int weight;
    printf("Input 'head,tail,weight' :\n");
    for(i=0; i<M.arcnum; i++){
        scanf(" %c,%c,%d",&head,&tail,&weight);
        int H = locateVex(M,head);
        int T = locateVex(M,tail);
        M.Edge[H][T] = weight;
        M.Edge[T][H] = weight;
    }

     printf("Succeed in creating UnDirMgraph!\n");
}
void CreateDirMGragh(MGragh &M){
    printf("Input 'vexNum,arcNum' : ");
    scanf(" %d,%d",&M.vexnum,&M.arcnum);
    InitMGragh(M);

    printf("\nInput vex:\n");
    int i;
    for(i=0; i<M.vexnum; i++){
        scanf(" %c",&M.Vex[i]);
    }

    char head,tail;int weight;
    printf("Input 'head,tail,weight' :\n");
    for(i=0; i<M.arcnum; i++){
        scanf(" %c,%c,%d",&head,&tail,&weight);

        int H = locateVex(M,head);
        int T = locateVex(M,tail);
        M.Edge[H][T] = weight;
    }

     printf("Succeed in creating UnDirMgraph!\n");
}
int locateVex(MGragh &M,char v2){
    int i;
    for(i=0; i<M.vexnum; i++){
        if(v2 == M.Vex[i]){
            return i;
        }
    }
    printf("Not Found Index");
    return -1;
}
void Print(MGragh M){
    int i,j,head,tail;
    printf("     ");
    for(i=0; i<M.vexnum ;i++){
        printf("%c   ",M.Vex[i]);
    }
    for(i=0; i<M.vexnum; i++){
        printf("\n%c    ",M.Vex[i]);
        head = locateVex(M,M.Vex[i]);
        for(j=0; j<M.vexnum; j++){
            tail = locateVex(M,M.Vex[j]);
            printf("%d    ",M.Edge[head][tail]);
        }
    }
}
