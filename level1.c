#include <stdio.h>

int main(){
	int pass, unitprice, number, i, n, coin, sc = 0, buy, signal,m;//buyΪ����ͨ����scΪͶ����Ŀ,nΪ������Ŀ,m��i��signalΪ�ж�
	char goods;
	printf("��װ������������ ͨ�� ���� ����˳����д\n");
	do{scanf_s("%c", &goods);//��������
		scanf_s("%d %d %d", &pass, &unitprice, &number);
		if (pass > 5 ||pass<1|| unitprice > 9 ||unitprice<1|| goods > 90 || goods < 65) {
			printf("�����쳣������������\n");
		}
	}//ͨ�� ���� ����
	while(pass > 5 || unitprice > 10 || goods > 90 || goods < 65);
	printf("ͨ��%d:",pass);                  //��ʾװ�����
	for (i = 0; i < number; i++) {
		printf("%c", goods);
	};
	printf(" ����Ϊ%d\n", unitprice);
	do {                                      //��һ��������ͨ��
		printf("�����빺��ͨ��\n");
		scanf_s("%d", &buy);
		if (buy!= pass) {
			signal = 1;
			printf("��ͨ�������ڻ��ͨ��û����Ʒ\n");
		}
		else { break; }
	} while (signal == 1);
	while (number > 0) {                      //���빺��ҳ��
		printf("ͨ��%d���",buy);
			for (i = 0; i < number; i++) {
				printf("%c", goods);
			};
			printf("\n");
		while (number > 0) {
			printf("��Ҫ���������\n");       //�ڶ�������������
			scanf_s("%d", &n);         
			if (n <= number) {
				number -= n;
				break;
			}
			else {       //��������
				printf("��Ʒ��������\n");
			};
		};
		const int sum = unitprice * n;
		printf("��Ҫ%dԪ����Ͷ��\n", sum);
		scanf_s("%d", &coin);                 //��������Ͷ��
		sc += coin;
		while (coin == 1 || coin == 2 || coin == 5 && sum > 0) {
			printf("��Ͷ��%dԪ\n", sc);
			scanf_s("%d", &coin);
			if (coin != 1 && coin != 2 && coin != 5) {
				break;
			};
			sc += coin;
			if (sc == sum) {
				printf("�������\n");
				break;
			};
			if (sc > sum) {
				printf(" �������,����%d\n", sc - sum);
				break;
			};
		};
		if (coin != 1 && coin != 2 && coin != 5) {   //Ͷ������
			printf("���Ϲ�\n");
			number += n;//��Ʒ�˻�
		};
		sc = 0;//��ʼ�����
		printf("�Ƿ��������,����1����\n");       //�Ƿ��������
		scanf_s("%d", &m);
		if (m ==1) {
			continue;
		}
		else { break; };
	};
	return 0;
	}