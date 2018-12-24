#include"Seqlist.h"
#include<stdlib.h>

void TestSeqList1(){
	SeqList seqlist;
	SeqListInit(&seqlist,1);
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2); 
	SeqListPushBack(&seqlist, 3);
	//1 2 3
	SeqListPushFront(&seqlist, 6);
	SeqListPushFront(&seqlist, 5);
	SeqListPushFront(&seqlist, 4);
	//4 5 6 1 2 3 4
	SeqListPopFront(&seqlist);
	//5 6 1 2 3
	SeqListPopBack(&seqlist);
	// 5 6 1 2
	SeqListPushInsert(&seqlist, 2,4);
	//5 6 4 1 2
	SeqListPopInsert(&seqlist, 2);
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);

}
int main(){
	TestSeqList1();
	
	system("pause");
	return 0;
}