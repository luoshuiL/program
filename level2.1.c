#include <stdio.h>

int main() {
	int jishu(int pass, int passN, int passG, int passP);
	int pass, unitprice, number;
	char goods;
	int passN[6] = { 0 };
	int passP[6] = { 0 };
	int passG[6] = { 0 };
	printf("��װ������������ ͨ�� ���� ����˳����д\n");
	int j = 0;
	do {
		scanf_s("%c", &goods,1);//��������     //��һ����װ�����
		scanf_s("%d", &pass);//ͨ��
		scanf_s("%d", &unitprice);//����
		scanf_s("%d", &number);//��Ŀ
		if (pass > 5 || pass < 1) {        // �ж��Ƿ����
			printf("�����ڴ�ͨ��\n");
		}
		else if (goods > 90 || goods < 65) {
			printf("�����ڴ˻���\n");
		}
		else if (unitprice > 9 || unitprice < 1) {
			printf("���۲�����\n");
		}
		else if(passN[pass]==0){       //װ�����
			passN[pass] = number; 
			passP[pass] = unitprice;
			passG[pass] = goods;
			j++;
		}
		else if (passN[pass] != 0) {    //�ظ���װ
			printf("��ǰͨ�����л��������·���\n");
		}
		scanf_s("%*c");
	}//ͨ�� ���� ����
	while(pass > 5 || pass < 1 || unitprice > 9 || unitprice < 1 || goods > 90 || goods < 65||j<5);
	while(j==5){     //��֪������дѭ��������ֻ�ܴ�һ����
	int unitsum = 0;   //���˲���������
	int p = 0;  //�ж��Ƿ����
	int sum = 0;//�ܽ��
	do {
		printf("�����빺��ͨ��:");//�ڶ���������
		scanf_s("%d", &pass);
		switch (pass) {
		case 1:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];   //��Ʒ����
			sum += unitsum;
			printf("��ǰ����Ҫ%dԪ������0��������\n", sum);
			break;
		case 2:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("��ǰ����Ҫ%dԪ������0��������\n", sum);
			break;
		case 3:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("��ǰ����Ҫ%dԪ������0��������\n", sum);
			break;
		case 4:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("��ǰ����Ҫ%dԪ������0��������\n", sum);
			break;
		case 5:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("��ǰ����Ҫ%dԪ������0��������\n", sum);
			break;
		case 0:              //����
			p = 1;
			break;
		default:
			printf("�����ڴ�ͨ��������������");
			break;
		};
	} while (p != 1);
		printf("����Ҫ%dԪ����Ͷ��\n", sum);
		int coin;
		scanf_s("%d", &coin);   //��������Ͷ��
		int sc = 0;
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
				printf(" �������,����%d\n", sc - sum);  //����
				break;
			};
		};
		sc = 0;//��ʼ�����
		printf("�Ƿ��������,����1����\n");  //�Ƿ��������
		int m = 0;  
		scanf_s("%d", &m);
		if (m ==1) {
			continue;
		}
		else { break; };
	};
	printf("ף���������");
	return 0;
	}
static int jishu(int pass, int passN, int passG, int passP) {   //������Ʒ������
	int n;
	int sum = 0;
	printf("ͨ��%d:", pass);
	for (int i = 0; i < passN; i++) {
		printf("%c", passG);
	};
	printf("����Ʒ����Ϊ%d\n",passP);
	while (passN > 0) {                     
		printf("��Ҫ���������\n");       
		scanf_s("%d", &n);
		if (n <= passN) {
			passN -= n;
			sum += passP * n;
			break;
		}
		else {       //��������
			printf("��Ʒ��������\n");
		};
	};
	return sum;
}
