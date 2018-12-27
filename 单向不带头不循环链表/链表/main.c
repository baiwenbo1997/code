#include"SList.h"


void TestSList1(){
	
	SList list;
	SListInit(&list);
	assert(list.first == NULL);
	/*SLNode *first;
	SListInit(&first);
	assert(first == NULL);*/
	SListpushFront(&list,1);
	SListpushFront(&list, 2);
	SListpushFront(&list, 3);
	//3 2 1
	SListPushBack(&list, 11);
	SListPushBack(&list, 12);
	SListPushBack(&list, 13);
	//3 2 1 11 12 13
	SListPopBack(&list);
	//3 2 1 11 12 
	SListPopFront(&list);
	//2 1 11 12
	SLNode *n = SListFind(&list, 1);
	SListInsertBefor(&list,n,3);
	SListPrint(&list);
	SLNode*p=SListFind(&list, 2);
	
	
}
int main(){
	TestSList1();
	printf("s");
	return 0;
}