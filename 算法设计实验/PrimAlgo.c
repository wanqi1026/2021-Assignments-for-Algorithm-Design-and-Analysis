/*2100301725陶万启*/
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6 // V表示图的结点的数量

int minKey(int key[], bool mstSet[]) ;
void dfs(int parent[], bool visited[], int u);
void printMST(int parent[]) ;
void primMST(int graph[V][V]);

int main() {
    int graph[V][V] = { // 按照指导书中图的数据要求进行输入
        {0, 5, 6, 4, 0, 0},
        {5, 0, 1, 2, 0, 0},
        {6, 1, 0, 2, 5, 3},
        {4, 2, 2, 0, 0, 4},
        {0, 0, 5, 0, 0, 4},
        {0, 0, 3, 4, 4, 0},
    };

    primMST(graph); // 求解最小生成树
    return 0;
}

// 求从集合M到集合V-M的边权重最小的边
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
    }
}

// 深度优先搜索 遍历 最小生成树
void dfs(int parent[], bool visited[], int u) {
    visited[u] = true;
    printf("%c", u + 'A');
    for (int v = 0; v < V; v++) {
        if (parent[v] == u && !visited[v]) {
            printf("-");
            dfs(parent, visited, v);
    }
    }
}

// 打印最小生成树
void printMST(int parent[]) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    dfs(parent, visited, 0);
}

// Prim算法求解最小生成树
void primMST(int graph[V][V]) {
    int parent[V]; // 最小生成树中每个节点对应的父节点
    int key[V]; // 记录每个节点到已选中节点的距离
    bool mstSet[V]; // 标记节点是否已经被加入最小生成树

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0; // 从第一个节点A开始构建最小生成树
    parent[0] = -1; // 根节点没有父节点

    for (int count = 0; count < V-1; count++) { // 最小生成树有V-1条边
        int u = minKey(key, mstSet); // 选取当前距离已选中节点最近的点
        mstSet[u] = true; // 标记该节点已被加入最小生成树

        for (int v = 0; v < V; v++) { // 更新剩余节点到已选中节点的距离
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent); // 打印最小生成树
}
