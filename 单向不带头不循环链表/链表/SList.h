#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

typedef struct SLNode{
	SLDataType value;
	struct SLNode *next;

} SLNode;
typedef struct SList{
	SLNode *first;//SLNode *head表示第一次节点的地址不是头节点
} SList;

//初始化
void SListInit(SList *list);
//销毁
void SListDestroy(SList *list);
//申请新结点
SLNode* SListBuyNode(SLDataType value);
//增
//头插
void SListpushFront(SList *list,SLDataType value);
//在POS的前面插
void SListInsertBefor(SList *list,SLNode *pos, SLDataType value);
//在POS的后面插
void SListInsertAfter(SLNode *pos, SLDataType value);
//尾插
void SListPushBack(SList *list, SLDataType value);
//删
//头删
void SListPopFront(SList *list);
//尾删
void SListPopBack(SList *list);
//删除POS后的一个结点
void SListEraseAfter(SLNode *pos);


//改
void SListUpdate(SLNode *pos, SLDataType value);
//查
SLNode* SListFind(const SList *list, SLDataType value);
//打印
void SListPrint(const SList *list);