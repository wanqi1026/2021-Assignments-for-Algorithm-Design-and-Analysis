/*********************************************************************
������:
��Ȩ:
����: ������
����: 2023-05-04 17:43
˵��:
*********************************************************************/
#include <stdio.h>

void get(int n);
void print(int arr[]);
void loop(int arr[], int v, int n);

int main() {

	int Snum;
	printf("���������ѧ�ţ�\n");
	scanf("%d", &Snum);
	int n = Snum % 100 % 9 + 9;
	printf("�ܹ��� %d ֻ����\n", n);
	get(n);

	return 0;
}

void get(int n) {

	int i = 0;
	int j = 1;

	if (n % 2 == 1) { //�������������
		n++;
		i = 1;
	}

	int arr[n] ;

	//���鸳ֵ��������Ϊ��������λ��ֵ��������������ֵΪ0
	if (i != 0) {
		arr[0] = 0;
	}
	for (i; i < n; i++) {

		arr[i] = j++;
	}

	for (i = 0; i < n; i++) { //���鸳ֵ��������Ϊ��������λ��ֵ��������������ֵΪ0
		printf("%d ", arr[i]);
	}
	printf("\n");
	loop(arr, n / 2, n); //ѭ�����ſ�ʼ
}

void loop(int arr[], int v, int n) {
	int length = n;
	int fre, end;
	int arr2[length];//arr2����һ��ѭ�����õ���ԲȦ
	arr2[0] = arr[0];//��λ����

	for (int i = 0; i < length - 1; i++) {
		if (arr[0] == 0) {
			fre = 1, end = length - 1;
		} else {
			fre = 0, end = v;
		}

		printf("\n�� %d ��ı�����\n", i + 1);

		while (fre < v) {
			printf("%dvs%d ", arr[fre], arr[end]);
			if (fre == 0)
				end = length;
			fre++;
			end--;
		}
		printf("\n");


		//������ʱ���������Ԫ��
		fre = 2;
		int temp = arr[1]; //����λ��Ϊ 1 ������Ԫ��
		for (; fre < length; fre++) {
			arr2[fre - 1] = arr[fre];
		}
		arr2[fre - 1] = temp;
		arr = arr2;
	}
}