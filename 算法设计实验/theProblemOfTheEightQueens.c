#include <stdio.h>

#define NUMS 8

int place[NUMS] = {0}; //皇后位置

int flag[NUMS] ;		
int d1[2 * NUMS - 1];		//定义上对角线
int d2[2 * NUMS - 1]; 		//定义下对角线
int count = 0; 			//记录输出次数

int queen(int n) {
	int col;//列数
	for (col = 0; col < NUMS; col++) {
		if (!flag[col] && !d1[n - col + NUMS - 1] && !d2[n + col]) { //判断皇后是否冲突

			place[n] = col; //放置皇后
			flag[col] = 1;
			d1[n - col + NUMS - 1] = 1;
			d2[n + col] = 1; //将该皇后所在的行、列、对角线设置为被占领

			if (n < NUMS - 1)	{
				queen(n + 1);
			} else {
				count++;
			}
			
			flag[col] = 0; //回溯
			d1[n - col + NUMS - 1] = 0;
			d2[n + col] = 0;
		}
	}
	return count;
}

int main() {
	count = queen(0); 
	printf("%d", count); 
}

