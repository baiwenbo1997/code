#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main()
{
	
	char a[] = "welcome to our school!";

	char b[] = "######################";

	int left = 0;

	int right = sizeof(a)-2;//包含\0

	while (left <= right)//注意“=”奇数偶数有差别 要加=

	{
		b[left] = a[left];

		b[right] = a[right];

		left++;

		right--;

		printf("%s\n", b);
		Sleep(3000);

		//printf("%s\r",b);



	}

	/*char mim[10];
	int i = 1;
	for(i = 1; i < 4; i++)
	{
		printf("请输入你的密码\n");
		scanf("%s", mim);
		if (strcmp(mim, "123456") == 0)
		{
			printf("密码正确\n");
			break;
		}
	}
	if (i == 4)
	{
		printf("您的机会已用完");
	}*/
	

	//printf("%d\n", sizeof(char));
	//printf("%d\n", sizeof(short));
	//printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof(long));
	//printf("%d\n", sizeof(long long));
	////printf("%d\n", sizeof(float));
	//const int i = 5;
 //   printf("%d\n", i);
	//printf("%d\n", sizeof("c:\test\32\test.c"));
	//printf("%d\n", strlen("c:\test\32\test.c"));
	system("pause");
	return 0;
}