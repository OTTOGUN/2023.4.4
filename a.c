#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

Status InitLinkList(LNode* L){
    L -> data = NULL;
    L -> next = NULL;
}

Status EnList(LNode* L,int n){
    LNode* r = L;
    ElemType e = 0;
    for(int i = 0;i < n;i++){
        LNode* p = (LinkList)malloc(sizeof(LNode));
        printf("请输入第%d个元素:\n",i + 1);
        scanf("%d",&e);
        p -> data = e;
        p -> next = NULL;
        r -> next = p;
        r = p;
    }
}

Status PrintList(LNode* L){
    int count = 1;
    while (L -> next){
        printf("第%d个元素为%d\n",count,L -> next -> data);
        count++;
        L = L -> next;
    }
}

void MergeList(LNode* LA,LNode* LB){
    LinkList pa,pb,pc;
    pa = LA -> next;
    pb = LB -> next;
    pc = LA;
    while(pa && pb){
        if(pa -> data > pb -> data){
            pc -> next = pb;
            pc = pc -> next;
            pb = pb -> next;
        }
        if(pa -> data < pb -> data){
            pc -> next = pa;
            pc = pc -> next;
            pa = pa -> next;
        }
        if(pa -> data == pb -> data){
            pc -> next = pa;
            pc = pa;
            pa = pa -> next;
            pb = pb -> next;
        }
    }
    pc -> next = pa?pa:pb;
}

int main(){
    LNode LA;
    LNode LB;

    InitLinkList(&LA);
    InitLinkList(&LB);

    EnList(&LA,4);
    printf("############分割线############\n");
    EnList(&LB,6);

    PrintList(&LA);
    printf("############分割线############\n");
    PrintList(&LB);
    printf("############分割线############\n");

    MergeList(&LA,&LB);

    PrintList(&LA);
}