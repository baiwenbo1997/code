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
	free(seqlist->array);//最重要的
	seqlist->array = NULL;
	seqlist->size = 0;
	seqlist->capacity = 0;
}
//尾插
void SeqListPushBack(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	CheekCapacity(seqlist);
	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}
//尾删
void SeqListPopBack(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(seqlist->size > 0);//删除size要大于0
	seqlist->size--;
}
//头插
void SeqListPushFront(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	//做数据搬移，i代表空间下标；
	CheekCapacity(seqlist);
	for (int i = seqlist->size; i > 0; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
	//i代表数据下标
	/*for(int i=seqlist->size-1;i>=0;i--){
	seqlist-array[i+1]=seqlist->array[i];
	}*/
}
//头删
void SeqListPopFront(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(seqlist->size > 0);
	for (int i = 0; i < seqlist->size - 1; i++){
		seqlist->array[i] = seqlist->array[i + 1];
	}
	seqlist->size--;
}
//从中间pos插入
void SeqListPushInsert(SeqList *seqlist,int pos, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(pos >= 0 && pos <= seqlist->size);//重要
	CheekCapacity(seqlist);
	for (int i = seqlist->size - 1; i >= pos; i--)
	{
		seqlist->array[i + 1] = seqlist->array[i];
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}
//从POS删除
void SeqListPopInsert(SeqList *seqlist, int pos){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(pos >= 0 && pos < seqlist->size);//和插入的差别
	for (int i = pos; i < seqlist->size - 1; i++){
		seqlist->array[i] = seqlist->array[i + 1];
	}
	seqlist->size--;
}
//扩容
static void CheekCapacity(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array);
	assert(seqlist->size <= seqlist->capacity);
	if (seqlist->size < seqlist->capacity){
		return;
	}
	//到了这里一定要扩容了
	int capacity = 2 * seqlist->capacity;
	SDataType *array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	assert(array != NULL);
	//把老数据搬移过来
	for (int i = 0; i < seqlist->size; i++){
		array[i] = seqlist->array[i];
	}
	//注意先释放
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