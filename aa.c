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

typedef struct {
    ElemType* base;
    int length;
}SqList;

Status InitList(SqList* Q){
    if(!(Q -> base = (SqList*)malloc(sizeof(ElemType) * MAXSIZE))){
        exit(OVERFLOW);
    }
    Q -> length = 0;
}

//创建顺序表，并且初始为Number个元素
Status EnList(SqList* Q,int Number){
    for(int i = 0;i < Number;i++){
        ElemType e = 0;
        printf("请输入第%d个元素\n",i + 1);
        scanf("%d",&e);
        Q -> base[i] = e;
        (Q -> length)++;
    }
}

Status InsertList(SqList* Q,int Number,ElemType e) {
    Q->base[Q->length] = e;
    (Q -> length)++;
}

void Scan(SqList* Q1,SqList* Q2){
    int i = 0;
    int j = 0;
    int flag = 1;
    for(i = 0;i < Q1 -> length;i++){
        for(j = 0;j < Q2 -> length;j++){
            if(Q1 -> base[i] == Q2 -> base[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            InsertList(Q2,1,Q1 -> base[i]);
        }
    }
}

Status SortList(SqList* Q){
    int i = Q -> length;
    int j = 0;
    for(i = Q -> length;i > 1;i--){
        for(j = 0;j < i - 1;j++){
            int temp = 0;
            if(Q -> base[j] > Q -> base[j+1]){
                temp = Q -> base[j];
                Q -> base[j] = Q -> base[j+1];
                Q -> base[j+1] = temp;
            }
        }
    }
}

void PrintList(SqList Q){
    for(int i = 0;i < Q.length;i++){
        printf("第%d个元素:%d\n",i + 1,Q.base[i]);
    }
}

int main(){
    SqList(A);
    SqList(B);

    InitList(&A);
    InitList(&B);

    EnList(&A,4);
    printf("###################分割线###################\n");
    EnList(&B,6);
    PrintList(A);
    printf("###################分割线###################\n");
    PrintList(B);
    printf("###################分割线###################\n");

    Scan(&A,&B);
    SortList(&B);

    PrintList(B);
}