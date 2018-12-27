#include"SList.h"
void SListInit(SList *list){
	assert(list != NULL);
	list->first = NULL;
}
//void SListInit(SLNode **first){
//	assert(first != NULL);
//	*first = NULL;
//}
SLNode* SListBuyNode(SLDataType value){
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	assert(node);
	node->value = value;
	node->next = NULL;
	return node;
}
void SListpushFront(SList *list,SLDataType value){
	assert(list != NULL);
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;

}
void SListPopFront(SList *list){
	assert(list != NULL);//保证链表是有的
	assert(list->first != NULL);//保证链表不为空
	SLNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}
void SListPushBack(SList *list, SLDataType value){
	assert(list != NULL);
	if (list->first->next == NULL){
		SListpushFront(list, value);
		return;
	}
	//链表中有节结点的情况
	
	SLNode *cur;
	SLNode *node = SListBuyNode(value);
	//找链表中的最后一个结点
	for (cur = list->first; cur->next != NULL;cur=cur->next);
	//cur为最后一个结点
	cur->next = node;
}
void SListPopBack(SList *list){
	SLNode *cur;
	if (list->first->next == NULL){
		SListPopFront(list);
		return;
	}
	for (cur = list->first; cur->next->next != NULL; cur = cur->next);
	SLNode *old = cur;
	free(cur->next);
	cur->next = NULL;
}
void SListDestroy(SList *list){
	assert(list != NULL);
	SLNode *cur=list->first;
	SLNode *next;
	while (cur != NULL){
		next = cur->next;
		free(next);
		cur = next;
	}
	list->first = NULL;
}
void SListPrint(const SList *list){
	SLNode *cur = list->first;
	for (cur; cur != NULL; cur = cur->next){
		printf("%d-->", cur->value);
	}
	printf("NULL\n");
}
SLNode* SListFind(const SList *list, SLDataType value){
	assert(list != NULL);
	SLNode *cur = list->first;
	while (cur != NULL){
		cur = cur->next;
		if (cur->value = value){
			return cur;
		}
		else{
			return NULL;
		}
		
	}
	return NULL;
}
void SListInsertBefor(SList *list,SLNode *pos, SLDataType value){
	assert(pos != NULL);
	assert(list != NULL);
	SLNode* cur = list->first;
	while (cur->next != pos){
		cur = cur->next;
	}
	SLNode* node = SListBuyNode(value);
	cur->next = node;
	node->next = pos;	
}
//POS一定是链表中的有效链表
void SListInsertAfter(SLNode *pos, SLDataType value){
	assert(pos != NULL);
	SLNode *node = SListBuyNode(value);
	node->next = pos->next;
	pos->next = node;
}
void SListUpdate(SLNode *pos, SLDataType value){
	pos->value = value;
}
void SListEraseAfter(SLNode *pos){
	SLNode *next = pos->next;
	pos->next = next->next;
	free(next);
}