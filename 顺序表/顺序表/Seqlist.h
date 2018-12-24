#pragma once
#include<stdio.h>


typedef int SDataType;
typedef struct SeqList{
	SDataType *array;//ָ����ϵĿռ�
	int size;//��ʾ��ǰ˳������ж��ٸ���
	        //˳��Ҳ��ʾ�˼���������±�
	int capacity;
}SeqList;
//��ʼ������
//��ʼ��
//seqlist��һ�������ĵ�ַ
//capacity��ʾ˳���ĳ�ʼ����
void SeqListInit(SeqList *seqlist,int capacity);
void SeqListDestroy(SeqList *seqlist);


//��ɾ�Ĳ�

//���� 
//β��
void SeqListPushBack(SeqList *seqlist, SDataType value);
//ͷ��
void SeqListPushFront(SeqList *seqlist, SDataType value);
//�м����,��pos���ڵ��±����value
void SeqListPushInsert(SeqList *seqlist,int pos, SDataType value);

//ɾ��
//βɾ
void SeqListPopBack(SeqList *seqlist);
//ͷɾ
void SeqListPopFront(SeqList *seqlist);
//��pos�����±������ɾ��
void SeqListPopInsert(SeqList *seqlist, int pos);
//����
static void CheekCapacity(SeqList *seqlist);
//��ӡ
void SeqListPrint(const SeqList *seqlist);
//�޸�pos�����±������Ϊvalue
void SeqListModify(SeqList *seqlist, int pos, SDataType value);
//���ҵ�һ��������value���ҷ����±�
int SeqListFind(SeqList* seqlist, int value);
//ɾ��value
void SeqListRemove(SeqList *seqlist, SDataType value);