#include <stdio.h>

int t[100], q[100];//t是田忌的马,q是齐王的马
void InsertSort(int arr[], int n);
int solve(int arr[], int arr2[], int n);

int main() {
	int n;
	while (1 ) {
		printf("请输入n：");
		scanf("%d", &n);
		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			scanf("%d", &t[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &q[i]);

		InsertSort(t, n);
		InsertSort(q, n);
		printf("\n");

		printf("%d \n\n", solve(t, q, n));
	}
	return 0;
}

int solve(int arr[], int arr2[], int n) {
	int ans = 0;
	int leftA = 0, leftB = 0;
	int rightA = n - 1, rightB = n - 1;

	while (leftA <= rightA) {
		if (arr[rightA] > arr2[rightB]) { //田忌最快的马比齐威王的最快的马快 两者比赛
			rightA--;
			rightB--;
			ans += 200;
		} else if (arr[rightB] < arr2[rightB]) { //田忌最快的马比齐威王的最快的马慢
			leftA++; // 让田忌最慢的马和威王的最快的马比赛
			rightB--;
			ans -= 200;
		} else {//田忌最快的马和齐威王最快的马的速度相同
			if (arr[leftA] > arr2[leftB]) { // 田忌最慢的马比齐威王的最慢的马块，两者比赛
				ans += 200;
				leftA++;
				leftB++;
			} else {// 否则用田忌最慢的马和田忌最快的马进行比赛
				if (arr[leftA] < arr2[rightB]) {
					ans -= 200;
				}
				leftA++;
				rightB--;
			}
		}
	}
	return ans;
}

void InsertSort(int arr[], int len) {

	for (int i = 0; i < len; i++) {
		int temp = arr[i];
		int j;
		for (j = i; j - 1 >= 0 && temp - arr[j - 1] < 0; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}
