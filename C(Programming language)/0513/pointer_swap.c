#include <stdio.h>
void swap(int x, int y);
void swap2(int* x, int* y);

int main()
{
	int a = 10;
	int b = 20;

	printf("swap Àü : %d, %d\n", a, b);

	swap2(&a, &b);
	/*int temp;
	temp = a;
	a = b;
	b = temp;*/

	printf("swap ÈÄ : %d, %d", a, b);


	return 0;
}

void swap(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;

}

void swap2(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}