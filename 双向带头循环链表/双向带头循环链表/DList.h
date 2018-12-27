#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DLDataType;

//定义链表结点结构
typedef struct DListNode{
	DLDataType value;       //头结点中的value没有意义
	struct DListNode *prev;//指向前一个结点
	struct DListNode *next;//指向后一个结点
}DListNode;
//定义双向链表结构
typedef struct DList{
	DListNode *head;//表示链表的头结点
}DList;

DListNode *DListBuyNode(DLDataType value){
	DListNode *node = (DListNode*)malloc(sizeof(DListNode));
	node->value = value;
	node->prev = node->next = NULL;
	return node;
}
//初始化
void DListInit(DList * dlist){
	dlist->head = DListBuyNode(0);//0其实没有意思
	dlist->head->prev = dlist->head;//这里是头结点
	dlist->head->next = dlist->head;
}
//销毁
//1.清空链表
void DListClear(DList *dlist){
	DListNode *cur, *next;
	cur = dlist->head->next;
	while (cur != dlist->head){
		next = cur->next;
		free(cur);
		cur = next;
	}
	dlist->head->next = dlist->head->prev = NULL;
}
//2.彻底销毁链表
void DListDestroy(DList *dlist){
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}
//增
//头插
void DListPushFront(DList *dlist,DLDataType value){
	assert(dlist != NULL);
	DListNode *node = DListBuyNode(value);
	node->prev = dlist->head;
	node->next = dlist->head->next;
	dlist->head->next->prev = node;
	dlist->head->next = node;
}
//尾插
void DListPushBack(DList *dlist, DLDataType value){
	assert(dlist != NULL);
	DListNode *node = DListBuyNode(value);
	
	node->next = dlist->head;
	node->prev = dlist->head->prev;
	dlist->head->prev->next = node;

	dlist->head->prev = node;
	
}
//在POS的前面插
void DListInsert(DListNode *pos, DLDataType value){
	DListNode *node = DListBuyNode(value);
	node->prev = pos->prev;
	node->next = pos;
	pos->prev->next = node;
	pos->prev = node;
}
//删
//头删
void DListPopFront(DList* dlist){
	assert(dlist != NULL);
	assert(dlist->head->next != dlist->head);//保证链表不为空
	DListNode *cur = dlist->head->next;
	dlist->head->next = cur->next;
	cur->next->prev = dlist->head;
	free(cur);
}
//尾删
void DListPopBack(DList* dlist){
	assert(dlist != NULL);
	assert(dlist->head->next != dlist->head);
	DListNode *cur=dlist->head->prev;
	cur->prev->next = dlist->head;
	cur->next->prev = cur->prev;
	free(cur);
}
//删掉POS
void DListErase(DListNode *pos){
	DListNode *cur = pos;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
}
//查
DListNode*DListFind(DList *dlist, DLDataType value){
	assert(dlist != NULL);
	DListNode *cur ;
	cur = dlist->head->next;
	while (cur != dlist->head){
		cur = cur->next;
		if (cur->value = value){
			return cur;
		}
	}
	return NULL;
}
