#include <stdio.h>
#include <limits.h>

#define V 10      // 顶点数量

#define MAXN 1005

void floyd();

int graph[V][V] = { // 邻接矩阵表示图
    {0,   4,   2,   3,   MAXN,MAXN,MAXN,MAXN,MAXN,MAXN},
    {MAXN,   0,MAXN,MAXN,10,  9,   MAXN,MAXN,MAXN,MAXN},
    {MAXN,MAXN,0,   MAXN,6,   7,   10,  MAXN,MAXN,MAXN},
    {MAXN,MAXN,MAXN,0,   MAXN,3,   8,   MAXN,MAXN,MAXN},
    {MAXN,MAXN,MAXN,MAXN,0,   MAXN,MAXN,4,   8,   MAXN},
    {MAXN,MAXN,MAXN,MAXN,MAXN,0,   MAXN,9,   6,   MAXN},
    {MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,0,   5,   4,   MAXN},
    {MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,0,   MAXN,8   },
    {MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,0,   4   },
    {MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,MAXN,0   }
};

int main() {

    floyd();
    
    return 0;
}

void floyd() {

    int dist[V][V], i, j, k;

    // 初始化dist数组
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // dp过程
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != MAXN && dist[k][j] != MAXN
                    && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("最短距离矩阵为:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == MAXN) {
                printf("INF ");
            } else {
                printf("%03d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}
