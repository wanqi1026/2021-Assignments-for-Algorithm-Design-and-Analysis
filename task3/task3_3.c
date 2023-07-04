#include <stdio.h>
#include<limits.h> 
#define MAX_N 7

int r[MAX_N] = {5, 10, 3, 12, 5, 50, 6}; // 给出矩阵的维数
int m[MAX_N][MAX_N]; // 存储最少乘法次数
int s[MAX_N][MAX_N]; // 存储最优连乘方式中断点的位置

void matrixChainOrder(int n) {
    int i, j, k, l;

    // 初始化
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // 动态规划转移
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n-l+1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j-1; k++) {
                int q = m[i][k] + m[k+1][j] + r[i-1]*r[k]*r[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(int i, int j) {

    if (i == j) {
        printf("A%d", i);
        
    } else {
        printf("(");
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j]+1, j);
        printf(")");
    }
}

int main() {
    int n = 6; // 矩阵数量为6

    matrixChainOrder(n);
    printf("最少乘法次数：%d\n", m[1][n]);
    printf("六个矩阵最佳连乘次序: ");
    printOptimalParens(1, n);
    printf("\n");

    return 0;
}
