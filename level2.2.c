#include <stdio.h>

int main() {
	printf("��װ������������ ͨ�� ���� ����˳����д\n");
	printf("(�����˻ز���������������Ʒ����ʱ����99)\n");
	int pass = 0, unitprice = 0, number;
	char goods;
	int passN[6] = { 0 };  //ͨ����������
	int passP[6] = { 0 };  //ͨ�����ﵥ��
	int passG[6] = { 0 };  //ͨ����������
	int j = 0;  //��װ�����ͨ����Ŀ
	int storeH[6] = { 0 };
	int k = 0;//�����˻ز���������
	do {
		
		scanf_s("%c", &goods,1);//��������     //��һ����װ�����
		if (goods == 57) {                //�˲�������Ҫ
			if (j == 0||k==3) {
				printf("�޷��˻�\n");
				scanf_s("%*[^\n]");//�建����������ѧ�ģ�
				scanf_s("%*c");//�建����������ѧ�ģ�  
				continue;
			}
			else if (k < 3) {
				there:
				k++;
				pass = storeH[j];
				passN[pass] = 0;
				j--;
				printf("�ѳɹ��˻�ͨ��%d��Ʒ,�����װ��\n",pass);
				scanf_s("%*[^\n]");//�建����������ѧ�ģ�
				scanf_s("%*c");//�建����������ѧ�ģ�
				continue;
			}
		}
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
			k = 0;//
			passN[pass] = number; 
			passP[pass] = unitprice;
			passG[pass] = goods;
			printf("ͨ��%dװ��ɹ�\n",pass);
			j++;
			storeH[j] = pass;
		}
		else if (passN[pass] != 0) {    //�ظ���װ����
			printf("��ǰͨ�����л��������·���\n");
		}
		scanf_s("%*[^\n]");
		scanf_s("%*c");//�建����������ѧ�ģ�
	}
	while(pass > 5 || pass < 1 || unitprice > 9 || unitprice < 1 || goods > 90 || goods < 65||j<5);
	printf("�ڷ���ϣ���ʼ����,����0������������99����һ��\n");
	while (j == 5) {     //��֪������дѭ��������ֻ�ܴ�һ����
		int unitsum = 0;   //���˲���������
		int end = 0;  //�ж��Ƿ����
		int sum = 0;//�ܽ��
		int storeN[4] = { 0 };  //�˲���Ҫ
		int storeS[4] = { 0 };
		int storeP[4] = { 0 };
		int i = 0;//��3��ѭ��
		int a = 0;//�ܵĲ�����
		int jishu(int pass, int passN, int passG, int passP);    //�㵥�ι������ĺ���
		do {
			printf("�����빺��ͨ��:");//�ڶ���������
			scanf_s("%d", &pass);
			switch (pass) {
			case 1:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //��Ʒ����
					sum += unitsum;
					printf("��ǰ����Ҫ%dԪ������0������������99����һ���������3����\n", sum);
					if (i < 3) {                                              //���ˣ��ظ���5�δ��룬Ӧ�ÿ����ú����򻯣����Ҳ���������ֵ
						a++;
						i++;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
					else {
						a++;
						i = 1;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
				}
				else { printf("��ǰͨ��ȱ�����뻻��ͨ������\n"); }
				break;
			case 2:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //��Ʒ����
					sum += unitsum;
					printf("��ǰ����Ҫ%dԪ������0������������99����һ���������3����\n", sum);
					if (i < 3) {                                              
						a++;
						i++;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
					else {
						a++;
						i = 1;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
				}
				else { printf("��ǰͨ��ȱ�����뻻��ͨ������\n"); }
				break;
			case 3:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //��Ʒ����
					sum += unitsum;
					printf("��ǰ����Ҫ%dԪ������0������������99����һ���������3����\n", sum);
					if (i < 3) {                                              
						a++;
						i++;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
					else {
						a++;
						i = 1;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
				}
				else { printf("��ǰͨ��ȱ�����뻻��ͨ������\n"); }
				break;
			case 4:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //��Ʒ����
					sum += unitsum;
					printf("��ǰ����Ҫ%dԪ������0������������99����һ���������3����\n", sum);
					if (i < 3) {                                              
						a++;
						i++;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
					else {
						a++;
						i = 1;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
				}
				else { printf("��ǰͨ��ȱ�����뻻��ͨ������\n"); }
				break;
			case 5:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //��Ʒ����
					sum += unitsum;
					printf("��ǰ����Ҫ%dԪ������0������������99����һ���������3����\n", sum);
					if (i < 3) {                                              
						a++;
						i++;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
					else {
						a++;
						i = 1;
						storeN[i] = unitsum / passP[pass];
						storeS[i] = unitsum;
						storeP[i] = pass;
					}
				}
				else { printf("��ǰͨ��ȱ�����뻻��ͨ������\n"); }
				break;
			case 0:              //����
				end = 1;
				break;
			case 99:  //����
				if (a>0&&k < 3) {
				here:
					k++;
					pass = storeP[i];
					sum -= storeS[i];
					passN[pass] += storeN[i];
					a--;
					if (i > 1) {
						i--;
					}
					else {
						i = 3;
					}
					printf("�ѻ���һ����������ǰ��Ҫ%dԪ\n", sum);
					break;
				}
				else if(a==0){
					printf("���˳�������Ʒ�׶Σ��������һ��װ��Ļ����˳���������˿Ͳ������ⲽ����Ϊ��д��Ŀ��\n");
					goto there;//��֪��goto�������ã�����ʵ���벻����İ취ʵ�ֿ�׶γ�����
				}
				else if (k ==3) {
					printf("���˴��������꣬�޷�����\n");
					break;
				}
			default:
				printf("�����ڴ�ͨ��������������/n");
				break;
			};
		} while (end != 1);
		end = 0;
		if (sum != 0) { printf("����Ҫ%dԪ����Ͷ�ң������˻ز�����������99\n", sum); }
		int coin;
		int sc = 0;   //��Ͷ����
		k = 0;//����Ԫ��
		int q = 0;     //�˻���
		int p = 0;//�ܲ�����
		int storeC[4] = { 0 };
		while (sc < sum) {
			scanf_s("%d", &coin);
			switch (coin) {
			case 1:
				k = 0;
				sc += 1;
				printf("��Ͷ��%dԪ\n", sc);
				if (q < 3) {      //ͬ���˹������
					p++;
					q++;
					storeC[q] = coin;
				}
				else {
					p++;
					q = 1;
					storeC[q] = coin;
				}
				break;
			case 2:
				k = 0;
				sc += 2;
				printf("��Ͷ��%dԪ\n", sc);
				if (q < 3) {
					p++;
					q++;
					storeC[q] = coin;
				}
				else {
					p++;
					q = 1;
					storeC[q] = coin;
				}
				break;
			case 5:
				k = 0;
				sc += 5;
				printf("��Ͷ��%dԪ\n", sc);
				if (q < 3) {
					p++;
					q++;
					storeC[q] = coin;
				}
				else {
					p++;
					q = 1;
					storeC[q] = coin;
				}
				break;
			case 99:
				if (p > 0 && k < 3) {
					k++;
					p--;
					sc -= storeC[q];
					printf("�ѻ���һ������ǰ��Ͷ��%dԪ\n", sc);
					if (q > 1) {
						q--;
					}
					else {
						q = 3;
					}
				}
				else {
					printf("���˳�Ͷ�ҽ׶Σ���Ϊ���˻���һ���������Ʒ\n");
					goto here;
				}
			default:
				printf("û�д�Ʊ��\n");
				break;
			}
		}
		if (sc == sum) {
			printf("�������");
		}
		else {
			int gap = sc - sum;
			printf("�������������%dԪ\n", gap);
		}
		sc = 0;//��ʼ�����
		printf("�Ƿ��������,����1����\n");  //�Ƿ��������
		int m = 0;
		scanf_s("%d", &m);
		if (m == 1) {
			continue;
		}
		else { break; };
	}
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
	printf("����Ʒ����Ϊ%d\n", passP);
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