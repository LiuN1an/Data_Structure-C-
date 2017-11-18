#include <iostream>
#include<function.h>
#include<Tree.h>
#define INT_MAX (unsigned)-1
using namespace std;

int main()
{
    //MGragh M;
    //CreateUndirMGragh(M);
    //Print(M);
    ALGraph G;
    CreateDirALGraph(G);
    Print(G);
    //printf("\nBFS: ");
    //BFSTraverse(G);
    //printf("\nDFS: ");
    //DFSTraverse(G);

    /*
    int* arr = BFS_MIN_Distance(G,1);
    int i;
    for(i=0; i<G.vexnum; i++){
        printf("\n%d",arr[i]);
    }
    free(arr);
    return 0;
    */

    /*
    BiTree T ;
    CreateBiTree(T);
    PreOrder(T);
    */
}
