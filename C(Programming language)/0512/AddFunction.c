#include <stdio.h>

int sum(int, int);
int sub(int, int);
void count();
int facto(int);
void self_service();

int main()
{
	int (*p1)(int, int) = NULL;
	p1 = sum;
	int res1 = p1(10, 50);
	printf("p1의 결과 : %d\n", res1);

	for (int i = 0; i < 5; i++) 
	{
		count();
	}

	int a = 10;
	int b = 20;
	int c;
	int d = facto(4);
	c = sum(a, b);
	printf("%d\n", c);
	printf("%d", d);

	return 0;
}

int sum(int x, int y)
{
	int sum = x + y;
	return sum;
}

int sub(int x, int y)
{
	int sub = x - y;
	return sub;
}

void count()
{
	static int ct = 0;
	ct++;

	printf("불린 횟수 : %d\n", ct);
	return ct;
}

int facto(int num)
{
	int result = 1;

	for (int i = 1; i < num; i++)
	{
		result *= i;
	}
	printf("factorial : %d!  = %d\n", num, result);
	return result;
}

int facto_self(int n)
{
	return n * facto_self(n - 1);
}

void self_service()
{
	printf("self");
	//self_service();
}