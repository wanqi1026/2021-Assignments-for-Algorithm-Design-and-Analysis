/*********************************************************************
程序名:
版权:
作者: 陶万启
日期: 2023-05-04 17:43
说明:
*********************************************************************/
#include <stdio.h>

void get(int n);
void print(int arr[]);
void loop(int arr[], int v, int n);

int main() {

	int Snum;
	printf("请输入你的学号：\n");
	scanf("%d", &Snum);
	int n = Snum % 100 % 9 + 9;
	printf("总共有 %d 只队伍\n", n);
	get(n);

	return 0;
}

void get(int n) {

	int i = 0;
	int j = 1;

	if (n % 2 == 1) { //如果队伍是奇数
		n++;
		i = 1;
	}

	int arr[n] ;

	//队伍赋值，若队伍为奇数，首位赋值就跳过，且冗余值为0
	if (i != 0) {
		arr[0] = 0;
	}
	for (i; i < n; i++) {

		arr[i] = j++;
	}

	for (i = 0; i < n; i++) { //队伍赋值，若队伍为奇数，首位赋值就跳过，且冗余值为0
		printf("%d ", arr[i]);
	}
	printf("\n");
	loop(arr, n / 2, n); //循环编排开始
}

void loop(int arr[], int v, int n) {
	int length = n;
	int fre, end;
	int arr2[length];//arr2是下一轮循环所用的新圆圈
	arr2[0] = arr[0];//首位不动

	for (int i = 0; i < length - 1; i++) {
		if (arr[0] == 0) {
			fre = 1, end = length - 1;
		} else {
			fre = 0, end = v;
		}

		printf("\n第 %d 天的比赛：\n", i + 1);

		while (fre < v) {
			printf("%dvs%d ", arr[fre], arr[end]);
			if (fre == 0)
				end = length;
			fre++;
			end--;
		}
		printf("\n");


		//重新逆时针调整数组元素
		fre = 2;
		int temp = arr[1]; //保存位置为 1 的数组元素
		for (; fre < length; fre++) {
			arr2[fre - 1] = arr[fre];
		}
		arr2[fre - 1] = temp;
		arr = arr2;
	}
}