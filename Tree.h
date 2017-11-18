#include<Usual.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

void CreateBiTree(BiTree &T){
    char node;
    scanf(" %c",&node);
    if(node == '#'){
        T = NULL;
        //return T;
    }
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = node;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
        //return T;
    }
}

void PreOrder(BiTree T){
    if(T){
        printf("%c ",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        printf("%c ",T->data);
        InOrder(T->rchild);
    }
}
void PostOrder(BiTree T){
    if(T){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ",T->data);
    }
}
