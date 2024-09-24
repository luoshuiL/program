#include <stdio.h>

int main() {
	int jishu(int pass, int passN, int passG, int passP);    ////算单次购买货物的函数
	int pass, unitprice, number;
	char goods;
	int passN[6] = { 0 };  //通道货物数量
	int passP[6] = { 0 };  //通道货物单价
	int passG[6] = { 0 };  //通道货物种类
	printf("请装填货物，按照名称 通道 单价 数量顺序填写\n");
	int j = 0;  //已装货物的通道数目
	do {
		scanf_s("%c", &goods,1);//货物名称     //第一步：装入货物
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
			passN[pass] = number; 
			passP[pass] = unitprice;
			passG[pass] = goods;
			j++;
		}
		else if (passN[pass] != 0) {    //重复安装报错
			printf("当前通道已有货物请重新放置\n");
		}
		scanf_s("%*c");//清缓存区（网上学的）
	}
	while(pass > 5 || pass < 1 || unitprice > 9 || unitprice < 1 || goods > 90 || goods < 65||j<5);
	printf("摆放完毕，开始购买");
	while(j==5){     //不知道怎样写循环条件，只能凑一下了
	int unitsum = 0;   //单此操作所需金额
	int p = 0;  //判断是否结束
	int sum = 0;//总金额
	int storeN[4] = { 0 };  //退步需要
	int storeS[4] = { 0 };
	int storeP[4] = { 0 };
	int i = 0;//退3步循环
	j = 0;//总的操作数
	int k = 0;//记录回退步数
	do{printf("请输入购买通道:");//第二步：购买
		scanf_s("%d", &pass);
		switch (pass) {
		case 1:
			k = 0;
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];   //商品件数
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
			if (i < 3) {                                              //回退，重复了5次代码，应该可以用函数简化，但我不会输出多个值
				j++;
				i++;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
			}
			else {
				j++;
				i = 1;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
			}
			break;
		case 2:
			k = 0;
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
			if (i < 3) {
				j++;
				i++;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
			}
			else {
				j++;
				i = 1;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
			}
			break;
		case 3:
			k = 0;
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
			if (i < 3) {
				j++;
				i++;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
			}
			else {
				j++;
				i = 1;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
				}
			break;
		case 4:
			k = 0;
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买，输入99回退一步（最多退3步）\n", sum);
			if (i < 3) {
				j++;
				i++;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
			}
			else {
				j++;
				i = 1;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
				}
			break;
		case 5:
			k = 0;
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买,输入99回退一步（最多退3步）\n", sum);
			if (i < 3) {
				j++;
				i++;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
			}
			else {
				j++;
				i = 1;
				storeN[i] = unitsum / passP[pass];
				storeS[i] = unitsum;
				storeP[i] = pass;
				}
			break;
		case 0:              //结束
			p = 1;
			break;
		case 99:  //回退
			k++;
			if (j>0&&k<4) {
				pass = storeP[i];
				sum -= storeS[i];
				passN[pass] += storeN[i];
				j--;
				if (i > 1) {
					i--;
				}
				else {
					i = 3;
				}
				printf("已回退一步操作，当前需要%d元\n",sum);
			}
			else { printf("无法退回\n"); }
			break;
		default:
			printf("不存在此通道，请重新输入/n");
			break;
		};
	} while (p != 1);
	printf("共需要%d元，请投币，如需退回操作，请输入99\n", sum);
	int coin;
	int sc = 0;
	k = 0;//回退元素
	i = 0;
	int storeC[4] = { 0 };
	while (sc<sum) {
		scanf_s("%d", &coin);
		switch (coin) {
		case 1:
			k = 0;
			sc += 1;
			printf("已投入%d元\n", sc);
			if (i < 3) {      //同回退购买操作
				j++;
				i++;
				storeC[i] = coin;
			}
			else {
				j++;
				i=1;
				storeC[i] = coin;
			}
			break;
		case 2:
			k = 0;
			sc += 2;
			printf("已投入%d元\n", sc);
			if (i < 3) {
				j++;
				i++;
				storeC[i] = coin;
			}
			else {
				j++;
				i = 1;
				storeC[i] = coin;
			}
			break;
		case 5:
			k = 0;
			sc += 5;
			printf("已投入%d元\n", sc);
			if (i < 3) {
				j++;
				i++;
				storeC[i] = coin;
			}
			else {
				j++;
				i = 1;
				storeC[i] = coin;
			}
			break;
		case 99:
			k++;
			if (j > 0 && k < 4) {
				sc -= storeC[i];
				printf("已回退一步，当前已投入%d元\n", sc);
				if (i > 1) {
					i--;
				}
				else{
					i = 3;
				}
			}
			else  {
				printf("无法退回\n"); }
			break;
		default:
			printf("没有此票面\n");
			break;
			}	
	}
	if (sc ==sum) {
		printf("购物结束");
	}
	else {
		int gap = sc - sum;
		printf("购物结束，找零%d元\n",gap);
	}
		sc = 0;//初始化金额
		printf("是否继续购买,输入1继续\n");  //是否继续购买
		int m = 0;  
		scanf_s("%d", &m);
		if (m ==1) {
			continue;
		}
		else { break; };
	};
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