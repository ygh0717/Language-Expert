#include <stdio.h>
#define MAX 40
//define MY_ARRAY

#ifdef MY_ARRAY
int main()
{
    printf("Hello World!\n");
    return 0;
}

#else
int stdiomain()
{
    printf("Hello World!\n");
    printf("Hello World!\n");

    int a = 255;
    printf("������ : %d\n", a);
    printf("������ : %#o\n", a);
    printf("�������� : %#x\n", a);

    double b = 89.567;

    printf("%f\n", b);
    printf("%F\n", b);
    printf("%e\n", b);
    printf("%E\n", b);

    printf("a�� �ּ� : %p\n", &a);
    //printf("main�� �ּ� : %p\n", main);
    printf("printf�� �ּ� : %p\n", printf);

    printf("enter a char : ");
    char ch = getchar();
    printf("��� : %d, %c\n", ch, ch);
    printf("�빮�ڷ� ��ȯ : %d, %c\n", ch-32, ch-32);



    return 0;

}
#endif