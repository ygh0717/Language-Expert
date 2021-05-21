#include<iostream>

#define ON_MAIN
#ifdef ON_MAIN 
using namespace std;

/*int mymax(int a, int b)
{
	return a > b ? a : b;
}
char mymax(char a, char b)
{
	return a > b ? a : b;
}
double mymax(double a, double b)
{
	return a > b ? a : b;
}*/

// 함수 템플릿의 정의
template <typename T>
T mymax(T a, T b)
{
	return a > b ? a : b;
}

template <typename W>
void myswap(W& c, W& d)
{
	W temp;
	temp = c;
	c = d;
	d = temp;
}


int main(void)
{
	//함수 템플릿2
	{
		int i = 50;
		int j = 10;
		cout << "Before " << "i = " << i << ", j = " << j << endl;
		myswap<int>(i, j);
		cout << "After " << "i = " << i << ", j = " << j << endl;

		char c1 = 'A';
		char c2 = 'Z';
		cout << "Before " << "c1 = " << c1 << ", j = " << c2 << endl;
		myswap(c1, c2);
		cout << "After " << "c1 = " << c1 << ", j = " << c2 << endl;
	}

	//함수 템플릿
	/*{
		cout << mymax(10, 20) << endl;
		cout << mymax(3.14, 1.14) << endl;
		cout << mymax('A', 'B') << endl;
		//cout << mymax(10, 11.1) << endl;	//type Err. -> 밑 예제처럼 형변환<~~>
		cout << mymax<int>(10, 11.1) << endl;
		cout << mymax<double>(10, 11.1) << endl;
	}*/
	return 0;
}
#endif