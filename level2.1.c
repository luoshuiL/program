#include <stdio.h>

int main() {
	int jishu(int pass, int passN, int passG, int passP);   //算单次购买货物的函数
	int pass, unitprice, number;
	char goods;
	int passN[6] = { 0 };//通道货物数量
	int passP[6] = { 0 };//通道货物单价
	int passG[6] = { 0 };//通道货物种类
	printf("请装填货物，按照名称 通道 单价 数量顺序填写\n");
	int j = 0; //已装货物的通道数目
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
	do {
		printf("请输入购买通道:");//第二步：购买
		scanf_s("%d", &pass);
		switch (pass) {
		case 1:
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];   //商品件数
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 2:
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 3:
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 4:
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 5:
			unitprice = 0;
			unitsum = jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 0:              //结束
			p = 1;
			break;
		default:
			printf("不存在此通道，请重新输入");
			break;
		};
	} while (p != 1);
	p = 0;
		printf("共需要%d元，请投币\n", sum);
		int coin;
		int sc = 0;
		while(sum>0){
			scanf_s("%d", &coin);;  //第三步：投币
			if (coin != 1 && coin != 2 && coin != 5) {   //判断硬币面值
				printf("不存在此金额的硬币，请重试");
				continue;
			};
			sc += coin;
			printf("当前已投入%d元\n",sc);
			if (sc == sum) {
				printf("购物结束\n");
				break;
			};
			if (sc > sum) {
				printf(" 购物结束,找零%d\n", sc - sum);  //找零
				break;
			};
		};
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
	printf("此商品单价为%d\n",passP);
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
