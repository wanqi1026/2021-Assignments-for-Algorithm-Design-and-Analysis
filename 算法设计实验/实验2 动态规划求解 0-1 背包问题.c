/*本关任务：给定N个物品和一个背包，背包的容量为W， 假设背包容量范围在[0，15]，第i个物品对应的体积和价值分别为W[i]和v[i]。各种物品的价值和重量如下：
     物品编号   1   2   3   4   5
      重量W    3   4   7   8   9
      价值V    4   5   10  11  13
求: 如何选择装入背包的物品，使得装入背包的物品的总价值为最大.

*/
#include <stdio.h>

int content[6] = {0};
int w[6] = {0};
int v[6] = {0};

int maxWeight = 15;
int maxValue[6][16] = {0};

void findContent(int i, int j) {
	if (i > 0) {
		if (maxValue[i][j] == maxValue[i - 1][j] || j - w[i] < 0) {
			content[i] = 0;
			findContent(i - 1, j);
		} else {
			content[i] = 1;
			findContent(i - 1, j - w[i]);
		}
	}
}

void findMax() {

	int i, j;
	for (i = 1; i < 6; ++i) {
		for (j = 1; j < 16; ++j) {
			if (j < w[i]) {
				maxValue[i][j] = maxValue[i - 1][j];
			}

			else {
				if (maxValue[i - 1][j] > (maxValue[i - 1][j - w[i]] + v[i])) {
					maxValue[i][j] = maxValue[i - 1][j];
				}

				else {
					maxValue[i][j] = maxValue[i - 1][j - w[i]] + v[i];
				}

			}
		}
	}
}

int main(void) {

	int i, j;

	printf("请输入相应物品的重量和价值：\n");
	for (i = 1; i < 6; ++i) {
		scanf("%d %d", &w[i], &v[i]);
	}
	printf("\n");
	printf("w v 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15\n");
	findMax();

	for (i = 0; i < 6; ++i) {
		printf("%d %d ", w[i], v[i]);
		for (j = 0; j < 15; ++j) {
			printf("%d ", maxValue[i][j]);
		}
		printf("%d", maxValue[i][j]);
		printf("\n");
	}
}