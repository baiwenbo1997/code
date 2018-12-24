#include"SeqList.h"
#include<assert.h>
#include<stdlib.h>
void SeqListInit(SeqList *seqlist, int capacity){
	assert(seqlist != NULL);
	seqlist->array = (SDataType*)malloc(sizeof(SDataType*)*capacity);
	seqlist->size = 0;
	seqlist->capacity = capacity;


}
void SeqListDestroy(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array);
	free(seqlist->array);//����Ҫ��
	seqlist->array = NULL;
	seqlist->size = 0;
	seqlist->capacity = 0;
}
//β��
void SeqListPushBack(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	CheekCapacity(seqlist);
	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}
//βɾ
void SeqListPopBack(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(seqlist->size > 0);//ɾ��sizeҪ����0
	seqlist->size--;
}
//ͷ��
void SeqListPushFront(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	//�����ݰ��ƣ�i����ռ��±ꣻ
	CheekCapacity(seqlist);
	for (int i = seqlist->size; i > 0; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
	//i���������±�
	/*for(int i=seqlist->size-1;i>=0;i--){
	seqlist-array[i+1]=seqlist->array[i];
	}*/
}
//ͷɾ
void SeqListPopFront(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(seqlist->size > 0);
	for (int i = 0; i < seqlist->size - 1; i++){
		seqlist->array[i] = seqlist->array[i + 1];
	}
	seqlist->size--;
}
//���м�pos����
void SeqListPushInsert(SeqList *seqlist,int pos, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(pos >= 0 && pos <= seqlist->size);//��Ҫ
	CheekCapacity(seqlist);
	for (int i = seqlist->size - 1; i >= pos; i--)
	{
		seqlist->array[i + 1] = seqlist->array[i];
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}
//��POSɾ��
void SeqListPopInsert(SeqList *seqlist, int pos){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(pos >= 0 && pos < seqlist->size);//�Ͳ���Ĳ��
	for (int i = pos; i < seqlist->size - 1; i++){
		seqlist->array[i] = seqlist->array[i + 1];
	}
	seqlist->size--;
}
//����
static void CheekCapacity(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(seqlist->size <= seqlist->capacity);
	if (seqlist->size < seqlist->capacity){
		return;
	}
	//��������һ��Ҫ������
	int capacity = 2 * seqlist->capacity;
	SDataType *array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	assert(array != NULL);
	//�������ݰ��ƹ���
	for (int i = 0; i < seqlist->size; i++){
		array[i] = seqlist->array[i];
	}
	//ע�����ͷ�
	free(seqlist->array);
	seqlist->array = array;
	seqlist->capacity = capacity;
}
void SeqListPrint(const SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array);
	for (int i = 0; i < seqlist->size; i++){
		printf("%d ", seqlist->array[i]);
	}
}
void SeqListModify(SeqList *seqlist, int pos, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(pos>0 && pos < seqlist->size);
	seqlist->array[pos] = value;
}
int SeqListFind(SeqList* seqlist, int value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	for (int i = 0; i < seqlist->size; i++){
		if (seqlist->array[i] == value){
			return i;
		}
	}
	return -1;
}
void SeqListRemove(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	int pos = SeqListFind(seqlist, value);
	SeqListPopInsert(seqlist, pos);
}