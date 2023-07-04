#include <stdio.h>
#include <string.h>

int len[100][100];
int dis[100][100];	//1代表两个都是，2代表行是左，3代表列是上
char x[100] = "2100301725";//2100301725陶万启
char y[100] = "20220528";

void show(int, int);

int main() {
	int n = strlen(x);
	int m = strlen(y);
	printf("%d  %d\n", n, m);

	int i, j, k;

	for (i = 0; i <= n; i++){
		len[i][0] = 0;
	}
		

	for (i = 0; i <= m; i++){
		len[0][i] = 0;
	}
		

	for (i = 1; i <= n; i++) {

		for (j = 1; j <= m; j++) {

			if (x[i - 1] == y[j - 1]) {
				len[i][j] = len[i - 1][j - 1] + 1;
				dis[i][j] = 1;

			} else if (len[i - 1][j] >= len[i][j - 1]) {
				len[i][j] = len[i - 1][j];
				dis[i][j] = 3;

			} else {
				len[i][j] = len[i][j - 1];
				dis[i][j] = 2;
			}
		}
	}
	printf("\n最大子序列长度:%d  \n", len[n][m]);

	printf("\n  ");

	for (int l = 0 ; l < m; l++) {
		printf("%c ", y[l]);
	}
	printf("\n");

	for (i = 1; i <= n; i++) {
		printf("%c ", x[i - 1]);
		for (j = 1; j <= m; j++) {
			printf("%d ", dis[i][j]);
		}
		puts("");
	}
	puts("\n子序列为: ");
	show(n, m);
}

void show(int i, int j) {

	if (i == 0 || j == 0){
		return;
	}

	if (dis[i][j] == 1) {
		show(i - 1, j - 1);
		printf("%c ", x[i - 1]);

	} else if (dis[i][j] == 3) {
		show(i - 1, j);
		
	} else {
		show(i, j - 1);
	}
}
