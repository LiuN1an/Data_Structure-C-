#include<Usual.h>
#include<Queue.h>
#define MaxVertexNum 100
/*
邻接表法AL，给定顶点容易找到它的所有邻边O(E)。不容易确定给定两个顶点是否存在边O(V),
*/
typedef char VertexType;
typedef int  EdgeType;

typedef struct ArcNode{
    EdgeType weight;
    VertexType adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

void Print(ALGraph G);
int locateVex(ALGraph &G,char v1);
void InitALGraph(ALGraph &G);
void CreateDirALGraph(ALGraph &G);
void CreateUndirALGraph(ALGraph &G);
void Insert(ALGraph &G,char vnode,char arcnode,int weight);

/*
    返回data为v1的顶点在顶点表数组中的下标
*/
int locateVex(ALGraph &G,char v1){
    int i;
    for(i=0; i<G.arcnum; i++){
        if(G.vertices[i].data == v1){
            return i;
        }
    }
    printf("Not Found Index");
    return -1;
}
/*
    初始化图，其实在邻接表里面并不需要这个功能
*/
void InitALGraph(ALGraph &G){
    G.arcnum = 0;
    G.vexnum = 0;
}

/*
    有向图邻接表存储结构的创建
*/
void CreateDirALGraph(ALGraph &G){
    printf("Input 'vexNum,arcNum' : ");
    scanf(" %d,%d",&G.vexnum,&G.arcnum);

    int i,k;
    printf("\nInput vex:\n");
    for(i=0; i<G.vexnum; i++){
        scanf(" %c",&G.vertices[i].data);
        G.vertices[i].first = NULL;
    }

    int weight;char v1,v2;
    printf("Input 'head,tail,weight' :\n");
    for(k=0; k<G.arcnum; k++){
        scanf(" %c,%c,%d",&v1,&v2,&weight);
        Insert(G,v1,v2,weight);
    }

    printf("Succeed in creating Dirgraph!\n");
}

/*
    无向图邻接表存储矩阵的创建
*/
void CreateUndirALGraph(ALGraph &G){
    printf("Input 'vexNum,arcNum' : ");
    scanf(" %d,%d",&G.vexnum,&G.arcnum);

    int i,k;
    printf("\nInput vex:\n");
    for(i=0; i<G.vexnum; i++){
        scanf(" %c",&G.vertices[i].data);
        G.vertices[i].first = NULL;
    }

    int weight;char v1,v2;
    printf("Input 'head,tail,weight' :\n");
    for(k=0; k<G.arcnum; k++){
        scanf(" %c,%c,%d",&v1,&v2,&weight);
        Insert(G,v1,v2,weight);
        Insert(G,v2,v1,weight);
    }

    printf("Succeed in creating Dirgraph!\n");
}

void Print(ALGraph G){
    int i;
    ArcNode* p;
    for(i=0; i<G.vexnum; i++){
        VNode v = G.vertices[i];
        printf("%c : ",G.vertices[i].data);
        p = v.first;
        while(p){
            printf("(%d)-->%c ",p->weight,p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
}

void Insert(ALGraph &G,char vnode,char arcnode,int weight){
    ArcNode *p,*q;
    int n,ivnode;
    ivnode = locateVex(G,vnode);
    if(G.vertices[ivnode].first==NULL){
            p = (ArcNode*)malloc(sizeof(ArcNode));
            p->weight = weight;
            G.vertices[ivnode].first = p;
            q = G.vertices[ivnode].first;
        }
    else{
            q = G.vertices[ivnode].first;
            for(n=0; n<G.arcnum; n++,q=q->next){
                if(!q->next){
                    break;
                }
            }
            p = (ArcNode*)malloc(sizeof(ArcNode));
            p->weight = weight;
            q->next = p;
            q = q->next;
        }
    q->adjvex = arcnode;
    q->next = NULL;
}
