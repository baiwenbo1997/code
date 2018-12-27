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
	SLNode *first;//SLNode *head��ʾ��һ�νڵ�ĵ�ַ����ͷ�ڵ�
} SList;

//��ʼ��
void SListInit(SList *list);
//����
void SListDestroy(SList *list);
//�����½��
SLNode* SListBuyNode(SLDataType value);
//��
//ͷ��
void SListpushFront(SList *list,SLDataType value);
//��POS��ǰ���
void SListInsertBefor(SList *list,SLNode *pos, SLDataType value);
//��POS�ĺ����
void SListInsertAfter(SLNode *pos, SLDataType value);
//β��
void SListPushBack(SList *list, SLDataType value);
//ɾ
//ͷɾ
void SListPopFront(SList *list);
//βɾ
void SListPopBack(SList *list);
//ɾ��POS���һ�����
void SListEraseAfter(SLNode *pos);


//��
void SListUpdate(SLNode *pos, SLDataType value);
//��
SLNode* SListFind(const SList *list, SLDataType value);
//��ӡ
void SListPrint(const SList *list);