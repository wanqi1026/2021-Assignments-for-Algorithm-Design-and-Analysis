/*********************************************************************
    程序名:
    版权:
    作者: 陶万启
    日期: 2023-05-05 16:56
    说明:
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void copyArray(int arr[], int arr2[], int length);
void generate_random_array(int arr[], int n);
void sort(int arr[], int l, int r, int seq);
int partition(int arr[], int l, int r);
void swap(int arr[], int i, int j);
bool isSeqArray(int arr[], int r);

#define N 50 //数组长度

int main() {
	int Snum;
	printf("请输入你的学号: ");
	scanf("%d", &Snum);

	int arr[N];
	generate_random_array(arr, N);
	printf("\nRandom array:\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	int seq = Snum % 100;
	printf("\n\n第 %d 小的元素： ", seq);
	//为什么是 seq-1？
	//数组下标从0开始
	sort(arr, 0, N - 1, seq - 1);
	printf("\nAfter sort:\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

bool isSeqArray(int arr[], int r) {
	for (int i = 0; i < r; i++) {
		if (arr[i + 1] < arr[i])
			return false;
	}
	return true;
}

void copyArray(int a[], int b[], int length) {
	for (int i = 0; i < length; i++)
		b[i] = a[i];
}

void generate_random_array(int a[], int n) {
	srand((unsigned)time(NULL)); // 使用当前时间作为随机数种子
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 50 + 1; // 生成随机数并赋值给数组元素
	}
}

void sort(int arr[], int l, int r, int seq) {
	if (l >= r)
		return ;

	int p = partition(arr, l, r);
	if (isSeqArray(arr, seq) && p > seq) {
		printf(" %d \n", arr[seq]);
		return ;
	}
	sort(arr, l, p - 1, seq);
	if (isSeqArray(arr, seq) && p > seq)
		return;
	sort(arr, p + 1, r, seq);

}

int partition(int arr[], int l, int r) {
	// arr[l+1...j] < v ; arr[j+1...i] >= v
	int j = l;
	for (int i = l + 1; i <= r; i++)
		if ((arr[i] - arr[l]) < 0) {
			j++;
			swap(arr, i, j);
		}

	swap(arr, l, j);

	return j;
}

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}