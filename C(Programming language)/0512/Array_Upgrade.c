#include<stdio.h>


int main(void)
{

	int age = 0;
	char name[20];


	printf("���� �Է� : ");
	scanf_s("%d", age);

	fflush(stdin); //�Է¹��۸� ����.
	//getchar();

	printf("�̸� �Է� : ");
	gets(name);



	printf("%d , %s\n", age, name);

	char ch = 0;
	
	//1. Ű���� -> �����
	/*
	while (ch != EOF)// ctrl + Z (-1)
	{
		ch = getchar();// �б�
		putchar(ch); // ����
	}
	*/


	
	//2. Ű���� -> ����
	/*
	FILE* stream;
	fopen_s(&stream, "C:\\temp\\data.txt", "wt");//txt white���

	while (ch != EOF)// ctrl + Z (-1)
	{
		// = getchar();// �б�
		ch  = fgetc(stdin); //�����Լ��ε� ���ٴٵ� ����¾����ִ�

		//putchar(ch); // ����Ϳ� ����
		fputc(ch, stdout);

		fputc(ch, stream); //stream�� ch�� ���. //���Ͽ� ����

	}
	fclose(stream);
	*/

	//3. ���� -> ����
	/*
	FILE* stream1;
	FILE* stream2;
	int input = 0;

	fopen_s(&stream1, "C:\\temp\\data.txt", "r");
	fopen_s(&stream2, "C:\\temp\\data2.txt", "w");

	while (input != EOF)
	{
		input = fgetc(stream1);	//1�� ���Ͽ��� �б�
		fputc(input, stream2);	//2�� ���Ͽ��� ����
		fputc(input, stdout);	//����Ϳ� ����.

	}

	fclose(stream1);
	fclose(stream2);
	*/

	//4 Ű����(���ڿ� 1��) -> ����
	/*
	FILE* stream;
	char buffer[50];

	fopen_s(&stream, "C:\\temp\\data3.txt", "w");

	fgets(buffer, sizeof(buffer), stdin);
	fputs(buffer, stream);
	fclose(stream);
	*/

	/*
	FILE* stream;
	//char buffer[50];

	char name[20];
	int kor, eng, math, total;
	int end;

	fopen_s(&stream, "C:\\temp\\grade.txt", "w");

	while(1)
	{

		printf("�̸��� �Է��ϼ��� : ");
		//scanf_s("%s", name, 20);

		getchar(); //���ʿ��� enter����
		gets(name);
		//puts(name);

		printf("����, ����, ���� ���� �Է� :  ");
		fscanf_s(stdin, "%d %d %d", &kor, &eng, &math);

		total = kor + eng + math;
		double average = total / 3;

		fprintf(stdout, "%s : %d %d %d %d,���: %f\n", name, kor, eng, math, total, average);
		fprintf(stream, "%s : %d %d %d %d, ���: %f\n", name, kor, eng, math, total, average);

		printf("��� ? yse:1, no: 0 : ");
		scanf_s("%d", &end);
		if (end == 0) break;
	}

	fclose(stream);

	*/
	return 0;
}