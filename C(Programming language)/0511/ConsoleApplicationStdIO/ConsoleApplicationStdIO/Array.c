#include <stdio.h>

int main()
{
	int aList[4][5] = {
		{10, 20, 30, 40},
		{50, 60, 70, 80},
		{90, 100, 110, 120},
	};

	int col = sizeof(aList[0]) / sizeof(int);	//5
	int row = sizeof(aList) / sizeof(aList[0]);	//4
	// 青 凯 蔼 Sum
	for (int i = 0; i < row-1; i++)
	{
		for (int j = 0; j < col-1; j++)
		{
			aList[i][col-1] += aList[i][j];
			aList[row-1][j] += aList[i][j];
			aList[row-1][col-1] += aList[i][j];
		}
	}
	// 傈眉 免仿
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d\t", aList[i][j]);
		}
		printf("\n");
	}

	/////////////////////////////////////////////////////
	/*int arrGrade[2][3] = { 1,2,3,4,5,6 };
	printf("林家 : %d\n", arrGrade);
	printf("林家 : %d\n", arrGrade[0]);
	printf("蔼1 : %d\n", arrGrade[0][1]);	//2
	printf("蔼1 : %d\n", *(*arrGrade+1));	//2
	printf("蔼1 : %d\n", **arrGrade + 1);	//2
	printf("林家 : %d\n", arrGrade[1]);
	printf("林家1 : %d\n", arrGrade[1][1]);	//5
	printf("林家1 : %d\n", (*(*arrGrade + 1)+1));	//5

	int arNumbers[] = { 10, 22, 32, 5, 6, 1, 11};
	int max = 0;
	int min = 0;
	
	max = arNumbers[0];
	min = *(arNumbers + 0);

	for (int i = 1; i < sizeof(arNumbers)/ sizeof(int); i++)
	{
		if (max < arNumbers[i])
			max = arNumbers[i];
	}

	for (int i= 1; i < sizeof(arNumbers) / sizeof(int); i++)
	{
		if (min > *(arNumbers+i))
			min = *(arNumbers+i);
	}

	printf("max : %d\n", max);
	printf("min : %d\n", min);

	int arr[3] = { 1,2,3 };
	char latter[3] = { 'A', 'B', 'C' };

	printf("蔼 : %d, %d, %d\n", arr[0], arr[1], arr[2]);
	printf("林家 : %d, %d, %d\n", &arr[0], &arr[1], &arr[2]);
	printf("蔼1 : %d, %d, %d\n", *arr, *arr + 1, *arr + 2);
	printf("林家1 : %d, %d, %d\n", arr, arr+1, arr+2);
	
	printf("====================================\n");
	printf("蔼 : %c, %c, %c\n", latter[0], latter[1], latter[2]);
	printf("林家 : %d, %d, %d\n", &latter[0], &latter[1], &latter[2]);
	printf("蔼1 : %c, %c, %c\n", *latter, *latter + 1, *latter + 2);
	printf("林家1 : %d, %d, %d\n", latter, latter + 1, latter + 2);*/

	return 0;
}