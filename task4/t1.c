#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


#define MAXN 12

const int STUNOF = 2100301725%100%3+3;

int place[MAXN] = {0}; 		//每行皇后的列号，初始值为0

int flag[MAXN] = {0};		//标志某列是否被皇后占领，初始值0表示未被占领

int d1[2*MAXN-1] = {0};		//i-j /对角线，初始值0表示未被占领
int d2[2*MAXN-1] = {0};		//i+j \对角线，初始值0表示未被占领

void isValib(int row,int col);
void print(void);
void dfs(int row);
void swap(int *arr,int i, int j);

int main(void) {

	dfs(0);	//从第0行开始放置皇后
	return 0;
}

void swap(int *arr,int i, int j){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    
}

//row 行
void dfs(int row) {
	//col 列
    
    if(row > STUNOF){
        for (int col = 0; col < MAXN; col++) {
            isValib(row,col);
        }
    }else{      
        int col;
        srand((unsigned)time(NULL)); // 使用当前时间作为随机数种子
        int f[MAXN]={0,1,2,3,4,5,6,7,8,9,10,11};
        for(int i=MAXN-1; i>=0; i--){
            swap(f,i,rand()%(i+1));
        }
        for (int col = 0; col < MAXN; col++) {
            isValib(row,f[col]);
        }   
    }
}

void isValib(int row,int col){
    if (flag[col] == 0 && d1[row - col + MAXN-1] == 0 && d2[row + col] == 0) {
                //标记
                place[row] = col;		//第row行的皇后放置在col列
                flag[col] = 1;			//第col列被占领
                d1[row - col + MAXN-1] = 1;		//占领对角线
                d2[row + col] = 1;

                if (row < MAXN-1) {
                    dfs(row + 1);
                } else {
                    print();
                    exit(0);
                }

                //回溯
                flag[col] = 0;
                d1[row - col + MAXN-1] = 0;
                d2[row + col] = 0;
    }
}

void print(void) {

	int table[MAXN][MAXN] = { 0 };
	
	//标明皇后在棋盘上的位置
	for (int i = 0; i < MAXN; i++) {
		table[i][place[i]] = 1;
	}

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
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

