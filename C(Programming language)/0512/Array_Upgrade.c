#include<stdio.h>


int main(void)
{

	int age = 0;
	char name[20];


	printf("나이 입력 : ");
	scanf_s("%d", age);

	fflush(stdin); //입력버퍼를 비운다.
	//getchar();

	printf("이름 입력 : ");
	gets(name);



	printf("%d , %s\n", age, name);

	char ch = 0;
	
	//1. 키보드 -> 모니터
	/*
	while (ch != EOF)// ctrl + Z (-1)
	{
		ch = getchar();// 읽기
		putchar(ch); // 쓰기
	}
	*/


	
	//2. 키보드 -> 파일
	/*
	FILE* stream;
	fopen_s(&stream, "C:\\temp\\data.txt", "wt");//txt white모드

	while (ch != EOF)// ctrl + Z (-1)
	{
		// = getchar();// 읽기
		ch  = fgetc(stdin); //파일함수로도 스텐다드 입출력쓸수있다

		//putchar(ch); // 모니터에 쓰기
		fputc(ch, stdout);

		fputc(ch, stream); //stream에 ch를 써라. //파일에 쓰기

	}
	fclose(stream);
	*/

	//3. 파일 -> 파일
	/*
	FILE* stream1;
	FILE* stream2;
	int input = 0;

	fopen_s(&stream1, "C:\\temp\\data.txt", "r");
	fopen_s(&stream2, "C:\\temp\\data2.txt", "w");

	while (input != EOF)
	{
		input = fgetc(stream1);	//1번 파일에서 읽기
		fputc(input, stream2);	//2번 파일에서 쓰기
		fputc(input, stdout);	//모니터에 쓰기.

	}

	fclose(stream1);
	fclose(stream2);
	*/

	//4 키보드(문자열 1개) -> 파일
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

		printf("이름을 입력하세요 : ");
		//scanf_s("%s", name, 20);

		getchar(); //불필요한 enter소진
		gets(name);
		//puts(name);

		printf("국어, 영어, 수학 점수 입력 :  ");
		fscanf_s(stdin, "%d %d %d", &kor, &eng, &math);

		total = kor + eng + math;
		double average = total / 3;

		fprintf(stdout, "%s : %d %d %d %d,평균: %f\n", name, kor, eng, math, total, average);
		fprintf(stream, "%s : %d %d %d %d, 평균: %f\n", name, kor, eng, math, total, average);

		printf("계속 ? yse:1, no: 0 : ");
		scanf_s("%d", &end);
		if (end == 0) break;
	}

	fclose(stream);

	*/
	return 0;
}