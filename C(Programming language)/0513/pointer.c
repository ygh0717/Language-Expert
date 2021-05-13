#include <stdio.h>

int main()
{
	double pi = 3.14;
	pi = 4.14;

	int aaa = 1;
	int bbb = 2;
	//const int* p = NULL;
	int* p = NULL;

	p = &aaa;
	printf("1. p 값 : %d\n", *p);	//1

	aaa = 100;
	printf("2. p 값 : %d\n", *p);	//100

	*p = 1000;	//error
	printf("3. p 값 : %d\n", *p);	//1000

	p = &bbb;
	printf("4. p 값 : %d\n", *p);


	int* ptr0;
	int a[3]; // a[2], *(a+2)
	int arr[2][3] = { 10,20,30,
					  40,50,60 };	// arr[1][2], **arr, *arr[1]
	printf("arr의 사이즈 : %d\n", sizeof(arr)); // 4Byte

	printf("ptr0의 사이즈 : %d\n", sizeof(ptr0)); // 4Byte

	ptr0 = arr;
	printf("1. 값: %d, 주소 : %d\n", *ptr0, ptr0);

	ptr0++;
	printf("2. 값: %d, 주소 : %d\n", *ptr0, ptr0);
	ptr0++;
	printf("3. 값: %d, 주소 : %d\n", *ptr0, ptr0);
	ptr0++;
	printf("4. 값: %d, 주소 : %d\n", *ptr0, ptr0);

	int* ptr1[3];
	printf("ptr1의 사이즈 : %d\n", sizeof(ptr1)); // 12Byte

	ptr1[1] = arr;
	printf("ptr1의 값: %d\n", *ptr1);
	printf("ptr1의 값: %d\n", *ptr1[1]);

	int(*ptr2)[3];	// int[3]을 가리키는 포인터 (배열의 포인터, 1개)
	printf("ptr2의 사이즈 : %d\n", sizeof(ptr2)); // 4Byte

	ptr2 = arr;
	printf("11. 값: %d, 주소 : %d\n", **ptr2, *ptr2);
	ptr2 = arr +1;
	printf("22. 값: %d, 주소 : %d\n", **ptr2, *ptr2);

	ptr2 = arr;
	printf("%d\n", ptr2[0]);
	printf("%d\n", ptr2[1]);
	printf("%d\n", ptr2[0][0]);
	printf("%d\n", ptr2[1][2]);


	return 0;
}