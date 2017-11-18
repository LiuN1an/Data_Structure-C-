#include<Usual.h>
#define MaxQNum 50
/*
Queue with array
*/
typedef int QElement;
typedef struct{
    QElement elements[MaxQNum];
    int font;
    int rear;
}Queue;

void InitQueue(Queue* &Q){
    Q->font = Q->rear = 0;
}
bool EnQueue(Queue* &Q,QElement x){
    if((Q->rear+1) % MaxQNum == Q->font){
        return false;
    }
    Q->elements[Q->rear] = x;
    Q->rear++;
    return true;
}
bool DeQueue(Queue* &Q,QElement &x){
    if(Q->rear == Q->font){
        return false;
    }
    x = Q->elements[Q->font];
    Q->font = (Q->font+1) % MaxQNum;
    return true;
}
bool isEmpty(Queue* Q){
    if(Q->rear == Q->font)
        return true;
    return false;
}
