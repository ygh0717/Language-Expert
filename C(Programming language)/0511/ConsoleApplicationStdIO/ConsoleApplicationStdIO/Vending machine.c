#include <stdio.h>

int main()
{
	int nMenu = -1;	//�ʱⰪ
	const int nPrice[] = { 1000, 1500, 700 };	//����ǥ
	int nMoney;	//�Էµ� �ݾ�
	int nChange = 0;	//�Ž�����

	for(;;)
	{

		//1. �޴�
		printf("======���� ���Ǳ�======\n");
		printf("1. �ݶ�\n");
		printf("2. ���̴�\n");
		printf("3. �������ֽ�\n");
		printf("0. ����\n");
		printf("=======================\n");
		printf("���ϴ� �����ư�� �����ϼ��� : ");

		scanf_s("%d", &nMenu);
		if (nMenu == 0)
		{
			printf("Bye\n\n");
			break;
		}

		//2. �ݾ� ó��
		printf("====================\n");
		printf("�ݾ��� �Է��ϼ��� : ");
		scanf_s("%d", &nMoney);	//�Է�


		if (nMoney >= nPrice[nMenu - 1])
		{
			nChange = nMoney - nPrice[nMenu - 1];
			printf("�ܾ��� %d���Դϴ�.\n", nChange);
		}

		//3. ����� ���
		if (nMenu == 1)
			printf("�ݶ� ���Խ��ϴ�.\n");
		else if (nMenu == 2)
			printf("���̴� ���Խ��ϴ�.\n");
		else if (nMenu == 3)
			printf("�������ֽ� ���Խ��ϴ�.\n");
		else
			printf("�ٸ� ��ȣ�� �Է����ּ���.\n");

		/*switch (nMenu)
		{
		case 0: printf("���α׷��� �����մϴ�.\n");
			break;
		case 1: printf("�ݶ� ���Խ��ϴ�.\n");
			break;
		case 2: printf("���̴� ���Խ��ϴ�.\n");
			break;
		case 3: printf("�������ֽ� ���Խ��ϴ�.\n");
			break;
		}*/
	}
	return 0;
}