#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DLDataType;

//����������ṹ
typedef struct DListNode{
	DLDataType value;       //ͷ����е�valueû������
	struct DListNode *prev;//ָ��ǰһ�����
	struct DListNode *next;//ָ���һ�����
}DListNode;
//����˫������ṹ
typedef struct DList{
	DListNode *head;//��ʾ�����ͷ���
}DList;

DListNode *DListBuyNode(DLDataType value){
	DListNode *node = (DListNode*)malloc(sizeof(DListNode));
	node->value = value;
	node->prev = node->next = NULL;
	return node;
}
//��ʼ��
void DListInit(DList * dlist){
	dlist->head = DListBuyNode(0);//0��ʵû����˼
	dlist->head->prev = dlist->head;//������ͷ���
	dlist->head->next = dlist->head;
}
//����
//1.�������
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
//2.������������
void DListDestroy(DList *dlist){
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}
//��
//ͷ��
void DListPushFront(DList *dlist,DLDataType value){
	assert(dlist != NULL);
	DListNode *node = DListBuyNode(value);
	node->prev = dlist->head;
	node->next = dlist->head->next;
	dlist->head->next->prev = node;
	dlist->head->next = node;
}
//β��
void DListPushBack(DList *dlist, DLDataType value){
	assert(dlist != NULL);
	DListNode *node = DListBuyNode(value);
	
	node->next = dlist->head;
	node->prev = dlist->head->prev;
	dlist->head->prev->next = node;

	dlist->head->prev = node;
	
}
//��POS��ǰ���
void DListInsert(DListNode *pos, DLDataType value){
	DListNode *node = DListBuyNode(value);
	node->prev = pos->prev;
	node->next = pos;
	pos->prev->next = node;
	pos->prev = node;
}
//ɾ
//ͷɾ
void DListPopFront(DList* dlist){
	assert(dlist != NULL);
	assert(dlist->head->next != dlist->head);//��֤����Ϊ��
	DListNode *cur = dlist->head->next;
	dlist->head->next = cur->next;
	cur->next->prev = dlist->head;
	free(cur);
}
//βɾ
void DListPopBack(DList* dlist){
	assert(dlist != NULL);
	assert(dlist->head->next != dlist->head);
	DListNode *cur=dlist->head->prev;
	cur->prev->next = dlist->head;
	cur->next->prev = cur->prev;
	free(cur);
}
//ɾ��POS
void DListErase(DListNode *pos){
	DListNode *cur = pos;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
}
//��
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
