#include<Usual.h>
#include<ALGraph.h>
#include<MGraph.h>

bool visited[MaxVertexNum];
Queue *Q;

void BFS(ALGraph G, int v);
void BFSTraverse(ALGraph G);
void visit(ALGraph G,int v);
int FirstNeighbor(ALGraph G,int u);
int NextNeighbor(ALGraph G,int u,int w);
int* BFS_MIN_Distance(ALGraph G,int u);
void DFSTraverse(ALGraph G);
void DFS(ALGraph G,int v);

/*
�����ṹ��������Q�����ڶ������Ƚ��ȳ������ԣ��ڽ��й�ȱ�����ʱ����ʼ�����ӣ�����ʱ�����ʼ�����������ڽ�����
�����ÿ�����ĳ��Ӷ��ᵼ�������е����ڽ����ӣ��������˹�ȱ�����
*/
void BFSTraverse(ALGraph G){
    int i;
    Q = (Queue*)malloc(sizeof(Queue));
    for(i=0; i<G.vexnum; i++){
        visited[i] = false;
    }
    InitQueue(Q);
    for(i=0; i<G.vexnum; i++){
        if(!visited[i]){
            BFS(G,i);
        }
    }
}
void BFS(ALGraph G, int v){
    int w;
    visit(G,v);
    visited[v] = true;
    EnQueue(Q,v);
    while(!isEmpty(Q)){
        DeQueue(Q,v);
        for(w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w)){
            if(!visited[w]){
                visit(G,w);
                visited[w] = true;
                EnQueue(Q,w);
            }
        }
    }
}

int* BFS_MIN_Distance(ALGraph G,int u){
    int i,w;
    int* dis = (int *)malloc(sizeof(int));;
    for(i=0; i<G.vexnum; i++){
        visited[i] = false;
        dis[i] = unsigned(-1)>>1;
        //printf("%x",dis[i]);
    }
    visited[u] = true;
    dis[u] = 0;
    EnQueue(Q,u);
    while(!isEmpty(Q)){
        DeQueue(Q,u);
        for(w=FirstNeighbor(G,u); w>=0; w=NextNeighbor(G,u,w)){
            printf("here ");
            if(!visited[w]){
                visited[w] = true;
                dis[w] = dis[u]+1;
                printf("\n%d",dis[w]);
                EnQueue(Q,w);
            }
        }
    }
    return dis;
}

/*
��ȱ���ʱ����Ҫ�����ṹ����ÿ�������ʱ��ֻ��Ҫ�ҵ�������һ���ڽӵ�Ȼ��ݹ�����ڽӵ���ڽӵ㣬ֱ���õ����ڵ���ͨ��ͼȫ��������Ϻ�
�ٻص�DFSTravers������
*/
void DFSTraverse(ALGraph G){
    int i;
    for(i=0; i<G.vexnum; i++){
        visited[i] = false;
    }
    for(i=0; i<G.vexnum; i++){
        if(!visited[i]){
            DFS(G,i);
        }
    }
}
void DFS(ALGraph G,int v){
    int w;
    visit(G,v);
    visited[v] = true;
    for(w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w)){
        if(!visited[w]){
            DFS(G,w);
        }
    }
}

void visit(ALGraph G,int v){
    printf("%d\t",G.vertices[v].data);
}

int FirstNeighbor(ALGraph G,int u){
    ArcNode *p;
    if(u >= G.vexnum){
        return -1;
    }
    p = G.vertices[u].first;
    if(p != NULL){
        return p->adjvex;
    }
    else{
        return -1;
    }
}

int NextNeighbor(ALGraph G,int u,int w){
    ArcNode *p;
    if(u >= G.vexnum){
        return -1;
    }
    p = G.vertices[u].first;
    while( p && (! (p->adjvex == w))) {
        p = p->next;
    }
    if(!p || !p->next){
        return -1;
    }
    return p->next->adjvex;
}
