#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void InsertSort(char arr[], int len);
void swap(char *a, char *b);
void reverse(char *str, int start, int end);
int nextPermutation(char *str, int n);
void lexicographicPermute(char *str, char *str2);

bool flag = false;
int sum = 0;

// 交换两个字符
void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

// 反转字符串
void reverse(char *str, int start, int end) {
	while (start < end) {
		swap(&str[start], &str[end]);
		start++;
		end--;
	}
}

void InsertSort(char arr[], int len) {
	for (int i = 0; i < len; i++) {
		char temp = arr[i];
		int j;
		for (j = i; j - 1 >= 0 && (temp - arr[j - 1]) < 0; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

// 找到下一个字典序排列
int nextPermutation(char *str, int n) {
	int i = n - 2;
	while (i >= 0 && str[i] >= str[i + 1]) {
		i--;
	}
	if (i < 0) {
		return 0;
	}
	int j = n - 1;
	while (j > i && str[j] <= str[i]) {
		j--;
	}
	swap(&str[i], &str[j]);
	reverse(str, i + 1, n - 1);
	return 1;
}

// 输出全排列
void lexicographicPermute(char *str, char *str2) {
	int n = strlen(str);
	InsertSort(str, n); // 先排序
	printf("\n排序后: \n");
	printf("%s\n\n", str);
	while (nextPermutation(str, n)) {

		if (flag) {
			printf("第 %d 号: %s\n", sum, str);
			exit(0);
		}
		if (strcmp(str, str2) == 0) {
			flag = true;
		}
		sum++;

	}
}

int main() {

	int Snum;
	printf("请输入你的学号: ");
	scanf("%d", &Snum);
	int n = (Snum % 100) % 5 + 5;
	printf("请输入 %d 个元素: \n", n);

	char arr[n];
	scanf("%s", &arr);

	printf("\n你输入的元素是：\n");
	printf("%s", arr);
	printf("\n");

	char arr2[n];
	strcpy(arr2, arr);
	lexicographicPermute(arr, arr2);
	return 0;
}
