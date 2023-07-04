#include <stdio.h>
#include <stdbool.h>

int place[8] = {0}; 		//每行皇后的列号，初始值为0

int flag[8] = {0};		//标志某列是否被皇后占领，初始值0表示未被占领

int d1[15] = {0};		//i-j /对角线，初始值0表示未被占领
int d2[15] = {0};		//i+j \对角线，初始值0表示未被占领

int count = 0;

void print(void);
void dfs(int row);

int main(void) {

	dfs(0);	//从第0行开始放置皇后
	printf("\n总共：%d 种方案", count);

	return 0;
}

//row 行
void dfs(int row) {
	//col 列
	for (int col = 0; col < 8; col++) {
		if (flag[col] == 0 && d1[row - col + 7] == 0 && d2[row + col] == 0) {
			//标记
			place[row] = col;		//第row行的皇后放置在col列
			flag[col] = 1;			//第col列被占领
			d1[row - col + 7] = 1;		//占领对角线
			d2[row + col] = 1;

			if (row < 7) {
				dfs(row + 1);
			} else {
				count++;
				print();
			}

			//回溯
			flag[col] = 0;
			d1[row - col + 7] = 0;
			d2[row + col] = 0;
		}
	}
}

void print(void) {

	int table[8][8] = { 0 };
	
	printf("No.%d\n", count);

	//标明皇后在棋盘上的位置
	for (int i = 0; i < 8; i++) {
		table[i][place[i]] = 1;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (table[i][j] == 1) {
				printf("M ");
			} else {
				printf("- ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

