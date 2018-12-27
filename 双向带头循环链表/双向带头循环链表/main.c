#include"DList.h"
int main(){
	DList dlist;
	DListInit(&dlist);
	DListPushFront(&dlist, 1);
	DListPushBack(&dlist, 2);
	DListNode *p=DListFind(&dlist, 2);
	printf("%p", p);
	DListInsert(p,3);
	printf("ccc");
	system("pause");
	return 0;
}