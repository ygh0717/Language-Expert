#include <stdio.h>

int main()
{
	//��ҹ��� ��ȯ
	char str[] = "I am a Boy";

	int count = strlen(str);
	
	for (int i = 0; i < count; i++)
	{
		 char t = str[i];
		 int test = t;

		 if (97 <= test && test <= 122)
		 {
			 t -= 32;
			 str[i] = t;
		 }
		 else if (65 <= test && test <= 90)
		 {
			 t += 32;
			 str[i] = t;
		 }
	}
	printf("%s", str);


	/* reverse ����.
	char string[] = "I love you.";
	char string2[20] = {0,};

	int count = strlen(string);
	for (int i = 0; i < count; i++)
	{
		string2[(count - 1)-i] = string[i];

	}
	printf("%s", string2);

	*/

	/* ��������
	
	 char str1[100] ="I love you.";
	int count=0;
	int j = 0;


	for (int i = 0; i<strlen(str1); i++)
	{
		char t = str1[i];

		if (t !=' ')
		{		
			str1[j] = t;
			j++;

		}
		///////////////
		int gap = i - j;

		if (i == strlen(str1)-gap)
		{
			
			str1[i - gap] = '\0';
		}
		//////////////
		
	}
	str1[j] = '\0';

	printf("%s\n", str1);
	*/


	/*
	char str1[100] = "I love you. ";
	char str2[100] = "Do you love me?";

	strcat(str1, str2); //�տ� �Ϳ� �ڸ� ����

	printf("%s\n", str1);
	printf("%s\n", str2);

	strncat(str1, str2, 6);//�տ� �Ϳ� ���� ����(6)��ŭ ����
	printf("%s\n", str1);
	printf("%s\n", str2);

	int count = 0;
	int i = 0;

	int count2 = 0;
	int j = 0;

	for (i = 0; str1[i] > '\n'; i++)
		count++;

	for (j = 0; str2[j] > '\n'; j++)
		count2++;
	
	for (int i = 0; i<count2; i++)
	{
		str1[count + i] = str2[i];
	}



	printf("%s\n", str1);
	printf("%s\n", str2);


	*/


	/*
	int arr[3] = { 1, 2};
	char latter[3] = { 'A', 'B', 'C' };
	char latter2[5] = "ABC"; //'\n' == 0
	char string[] = "I love you!";

	printf("arr %d�Դϴ�\n", sizeof(arr));
	printf("latter %d�Դϴ�\n", sizeof(latter));
	printf("latter2 %d�Դϴ�\n", sizeof(latter2));


	//1. ���ڿ� ���� ���
	int count = 0;
	int i = 0;

	while (string[i++] > '\n')
		count++;
	printf("���ڿ��� ���̴� %d(%d)�Դϴ�.\n", count,i);

	count = 0;
	for (i = 0; string[i] > '\n'; i++)
		count++;
	printf("���ڿ��� ���̴� %d(%d)�Դϴ�\n", count, i);


	count = strlen(string);
	printf("strlen�� ���̴� %d�Դϴ�.\n", count);

	count = sizeof(string);
	printf("sizeof�� ���̴� %d�Դϴ�.\n", count);
	*/

	return 0;

}