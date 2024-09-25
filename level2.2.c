#include <stdio.h>

int main() {
	printf("请装填货物，按照名称 通道 单价 数量顺序填写\n");
	printf("(如需退回操作，请在输入商品名称时输入99)\n");
	int pass = 0, unitprice = 0, number;
	char goods;
	int passN[6] = { 0 };  //通道货物数量
	int passP[6] = { 0 };  //通道货物单价
	int passG[6] = { 0 };  //通道货物种类
	int j = 0;  //已装货物的通道数目
	int storeH[6] = { 0 };
	int k = 0;//连续退回操作的数量
	do {
		
		scanf_s("%c", &goods,1);//货物名称     //第一步：装入货物
		if (goods == 57) {                //退步操作需要
			if (j == 0||k==3) {
				printf("无法退回\n");
				scanf_s("%*[^\n]");//清缓存区（网上学的）
				scanf_s("%*c");//清缓存区（网上学的）  
				continue;
			}
			else if (k < 3) {
				there:
				k++;
				pass = storeH[j];
				passN[pass] = 0;
				j--;
				printf("已成功退回通道%d商品,请继续装填\n",pass);
				scanf_s("%*[^\n]");//清缓存区（网上学的）
				scanf_s("%*c");//清缓存区（网上学的）
				continue;
			}
		}
		scanf_s("%d", &pass);//通道
		scanf_s("%d", &unitprice);//单价
		scanf_s("%d", &number);//数目
		if (pass > 5 || pass < 1) {        // 判断是否合理
			printf("不存在此通道\n");
		}
		else if (goods > 90 || goods < 65) {
			printf("不存在此货物\n");
		}
		else if (unitprice > 9 || unitprice < 1) {
			printf("定价不合理\n");
		}
		else if(passN[pass]==0){       //装入货物
			k = 0;//
			passN[pass] = number; 
			passP[pass] = unitprice;
			passG[pass] = goods;
			printf("通道%d装填成功\n",pass);
			j++;
			storeH[j] = pass;
		}
		else if (passN[pass] != 0) {    //重复安装报错
			printf("当前通道已有货物请重新放置\n");
		}
		scanf_s("%*[^\n]");
		scanf_s("%*c");//清缓存区（网上学的）
	}
	while(pass > 5 || pass < 1 || unitprice > 9 || unitprice < 1 || goods > 90 || goods < 65||j<5);
	printf("摆放完毕，开始购买,输入0结束购买，输入99回退一步\n");
	while (j == 5) {     //不知道怎样写循环条件，只能凑一下了
		int unitsum = 0;   //单此操作所需金额
		int end = 0;  //判断是否结束
		int sum = 0;//总金额
		int storeN[4] = { 0 };  //退步需要
		int storeS[4] = { 0 };
		int storeP[4] = { 0 };
		int i = 0;//退3步循环
		int a = 0;//总的操作数
		int jishu(int pass, int passN, int passG, int passP);    //算单次购买货物的函数
		do {
			printf("请输入购买通道:");//第二步：购买
			scanf_s("%d", &pass);
			switch (pass) {
			case 1:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //商品件数
					sum += unitsum;
					printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
					if (i < 3) {                                              //回退，重复了5次代码，应该可以用函数简化，但我不会输出多个值
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
				else { printf("当前通道缺货，请换个通道购买\n"); }
				break;
			case 2:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //商品件数
					sum += unitsum;
					printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
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
				else { printf("当前通道缺货，请换个通道购买\n"); }
				break;
			case 3:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //商品件数
					sum += unitsum;
					printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
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
				else { printf("当前通道缺货，请换个通道购买\n"); }
				break;
			case 4:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //商品件数
					sum += unitsum;
					printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
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
				else { printf("当前通道缺货，请换个通道购买\n"); }
				break;
			case 5:
				if (passN[pass] != 0) {
					k = 0;
					unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
					passN[pass] -= unitsum / passP[pass];   //商品件数
					sum += unitsum;
					printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
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
				else { printf("当前通道缺货，请换个通道购买\n"); }
				break;
			case 0:              //结束
				end = 1;
				break;
			case 99:  //回退
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
					printf("已回退一步操作，当前需要%d元\n", sum);
					break;
				}
				else if(a==0){
					printf("已退出购买商品阶段，并将最后一次装入的货物退出（按道理顾客不能有这步，但为了写题目）\n");
					goto there;//我知道goto不能乱用，但我实在想不到别的办法实现跨阶段撤回了
				}
				else if (k ==3) {
					printf("回退次数已用完，无法回退\n");
					break;
				}
			default:
				printf("不存在此通道，请重新输入/n");
				break;
			};
		} while (end != 1);
		end = 0;
		if (sum != 0) { printf("共需要%d元，请投币，如需退回操作，请输入99\n", sum); }
		int coin;
		int sc = 0;   //已投入金额
		k = 0;//回退元素
		int q = 0;     //退回用
		int p = 0;//总操作数
		int storeC[4] = { 0 };
		while (sc < sum) {
			scanf_s("%d", &coin);
			switch (coin) {
			case 1:
				k = 0;
				sc += 1;
				printf("已投入%d元\n", sc);
				if (q < 3) {      //同回退购买操作
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
				printf("已投入%d元\n", sc);
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
				printf("已投入%d元\n", sc);
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
					printf("已回退一步，当前已投入%d元\n", sc);
					if (q > 1) {
						q--;
					}
					else {
						q = 3;
					}
				}
				else {
					printf("已退出投币阶段，并为您退回上一步购买的商品\n");
					goto here;
				}
			default:
				printf("没有此票面\n");
				break;
			}
		}
		if (sc == sum) {
			printf("购物结束");
		}
		else {
			int gap = sc - sum;
			printf("购物结束，找零%d元\n", gap);
		}
		sc = 0;//初始化金额
		printf("是否继续购买,输入1继续\n");  //是否继续购买
		int m = 0;
		scanf_s("%d", &m);
		if (m == 1) {
			continue;
		}
		else { break; };
	}
	printf("祝您购物愉快");
	return 0;
	}
static int jishu(int pass, int passN, int passG, int passP) {   //单个商品购买步骤
	int n;
	int sum = 0;
	printf("通道%d:", pass);
	for (int i = 0; i < passN; i++) {
		printf("%c", passG);
	};
	printf("此商品单价为%d\n", passP);
	while (passN > 0) {
		printf("需要购买的数量\n");
		scanf_s("%d", &n);
		if (n <= passN) {
			passN -= n;
			sum += passP * n;
			break;
		}
		else {       //数量不足
			printf("商品数量不足\n");
		};
	};
	return sum;
}