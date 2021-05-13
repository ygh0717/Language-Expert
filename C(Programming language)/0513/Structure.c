#include <stdio.h>

struct point{
	int x;
	int y;
};

typedef struct rect{
	int x;
	int y;
	int w;
	int h;
	int color;
}MYRECT;

typedef int AGE;
typedef struct point MYPOINT;

#pragma pack(push, 1)
struct USERDATA {
	char ch;
	int age;
}; 
struct MYDATA {
	char ch;
	int age;
	double height;
};
#pragma pack(pop)

typedef struct score {
	int kor;
	int eng;
	int math;
	int sum;
	int avg;
}SCORE;

typedef struct student {
	int num;
	char name[20];
	SCORE s;
}STU;

typedef struct worker {
	int num;
	char name[20];

	struct worker* pLink;
}WORKER;

//사이즈가 4바이트가 잡힌다. 왜? 공용체는 메모리를 공용으로 쓴다??
typedef union shape {
	int x;
	int y;
}SHAPE;


//공용체 안에있는 맴버들중에 가장 큰 사이즈의 변수의 크기로 메모리를 잡아서 공용 , 여기서는 8바이트
typedef union differ{
	char a;		//1Byte
	int b;		//4Byte
	double c;	//8Byte
}DIF;

int main()
{
	//공용체 
	{

		SHAPE test;
		DIF test2;

		test.x = 10;
		printf("union %d, %d\n", test.x, test.y);
		test.y = 20;
		printf("union %d, %d\n", test.x, test.y);
		printf("union사이즈 %d\n", sizeof(test));
		printf("union사이즈 %d\n", sizeof(union shape));

		printf("union사이즈 %d\n", sizeof(test2));
		printf("union사이즈 %d\n", sizeof(union differ));


	}

	//구조체의 자기참조 포인터==============================================
	
	{
		WORKER a = { 1, "홍길동", NULL };
		WORKER b = { 2, "김길동", NULL };
		WORKER c = { 3, "조길동", NULL };

		a.pLink = &b;
		b.pLink = &c;

		WORKER* pHeap = &a;

		for (int i = 0; i < 3; i++)
		{
			printf("[%p] %d, %s[%p]\n", pHeap, pHeap->num, pHeap->name, pHeap->pLink);
			pHeap = pHeap->pLink;
		}

	}


	//중첩 구조체============================================================
	STU yoon = { 10, "윤강희", {100,99,98} };
	STU* pStu = NULL;
	pStu = &yoon;

	pStu->s.sum = pStu->s.kor + pStu->s.eng + pStu->s.math;
	pStu->s.avg = pStu->s.sum / 3;

	printf("%d번 %s학생의 성적\n국어 : %d, 영어 : %d, 수학 : %d\n총점 : %d, 평균 : %d\n",
		pStu->num, pStu->name, pStu->s.kor, pStu->s.eng, pStu->s.math, pStu->s.sum, pStu->s.avg);

	//구조체의 배열==========================================================
	SCORE myClass[5]=
	{
		{90, 20, 40 },
		{ 80, 90, 70 },
		{ 40, 100, 10 },
		{ 50, 80, 60 },
		{ 80, 50, 30 }
	};

	for (int i = 0; i<sizeof(myClass)/sizeof(SCORE); i++)
	{
		SCORE kim = { 100,20, 70 };
		myClass[i].sum = myClass[i].kor + myClass[i].eng + myClass[i].math;
		myClass[i].avg = myClass[i].sum / 3;
		printf("%d번 학생의 성적\n국어 : %d, 영어 : %d, 수학 : %d\n총점 : %d, 평균 : %d\n",
			i+1, myClass[i].kor, myClass[i].eng, myClass[i].math, myClass[i].sum, myClass[i].avg);
	}
	

	/*AGE kim = 45;
	AGE lee = 33;*/

	int a = 100;

	struct point pt1 = { 10,20 };
	MYPOINT pt2;
	MYPOINT pt3 = { 111,222 };
	pt2.x = 100;
	pt2.y = 200;

	printf("pt1 : %d, %d\n", pt1.x, pt1.y);
	printf("pt2 : %d, %d\n", pt2.x, pt2.y);

	struct rect rect1 = { 10, 20 , 30, 40 };
	printf("rect1 : %d, %d, %d, %d\n", rect1.x, rect1.y, rect1.w, rect1.h);

	printf("MYPOINT의 사이즈 : %d\n", sizeof(MYPOINT));
	printf("MYRECT의 사이즈 : %d\n", sizeof(MYRECT));

	printf("USERDATA의 사이즈 : %d\n", sizeof(struct USERDATA));	//5->8 2의 => n승으로 메모리->엑세스 위해 8Byte씩
	printf("MYDATA의 사이즈 : %d\n", sizeof(struct MYDATA));		//13->16 #pragma로 필요한 만큼 메모리 할당 가능

	return 0;
}