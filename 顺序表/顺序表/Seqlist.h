#pragma once
#include<stdio.h>


typedef int SDataType;
typedef struct SeqList{
	SDataType *array;//指向堆上的空间
	int size;//表示当前顺序表里有多少个数
	        //顺便也表示了即将插入的下标
	int capacity;
}SeqList;
//初始化销毁
//初始化
//seqlist是一个变量的地址
//capacity表示顺序表的初始容量
void SeqListInit(SeqList *seqlist,int capacity);
void SeqListDestroy(SeqList *seqlist);


//增删改查

//插入 
//尾插
void SeqListPushBack(SeqList *seqlist, SDataType value);
//头插
void SeqListPushFront(SeqList *seqlist, SDataType value);
//中间插入,往pos所在的下标插入value
void SeqListPushInsert(SeqList *seqlist,int pos, SDataType value);

//删除
//尾删
void SeqListPopBack(SeqList *seqlist);
//头删
void SeqListPopFront(SeqList *seqlist);
//把pos所在下标的数据删了
void SeqListPopInsert(SeqList *seqlist, int pos);
//扩容
static void CheekCapacity(SeqList *seqlist);
//打印
void SeqListPrint(const SeqList *seqlist);
//修改pos所在下标的数据为value
void SeqListModify(SeqList *seqlist, int pos, SDataType value);
//查找第一个遇见的value并且返回下标
int SeqListFind(SeqList* seqlist, int value);
//删除value
void SeqListRemove(SeqList *seqlist, SDataType value);