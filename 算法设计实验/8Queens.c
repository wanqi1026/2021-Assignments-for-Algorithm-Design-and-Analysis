#include <stdio.h>
#include <stdbool.h>

int place[8] = {0}; 		//ÿ�лʺ���кţ���ʼֵΪ0

int flag[8] = {0};		//��־ĳ���Ƿ񱻻ʺ�ռ�죬��ʼֵ0��ʾδ��ռ��

int d1[15] = {0};		//i-j /�Խ��ߣ���ʼֵ0��ʾδ��ռ��
int d2[15] = {0};		//i+j \�Խ��ߣ���ʼֵ0��ʾδ��ռ��

int count = 0;

void print(void);
void dfs(int row);

int main(void) {

	dfs(0);	//�ӵ�0�п�ʼ���ûʺ�
	printf("\n�ܹ���%d �ַ���", count);

	return 0;
}

//row ��
void dfs(int row) {
	//col ��
	for (int col = 0; col < 8; col++) {
		if (flag[col] == 0 && d1[row - col + 7] == 0 && d2[row + col] == 0) {
			//���
			place[row] = col;		//��row�еĻʺ������col��
			flag[col] = 1;			//��col�б�ռ��
			d1[row - col + 7] = 1;		//ռ��Խ���
			d2[row + col] = 1;

			if (row < 7) {
				dfs(row + 1);
			} else {
				count++;
				print();
			}

			//����
			flag[col] = 0;
			d1[row - col + 7] = 0;
			d2[row + col] = 0;
		}
	}
}

void print(void) {

	int table[8][8] = { 0 };
	
	printf("No.%d\n", count);

	//�����ʺ��������ϵ�λ��
	for (int i = 0; i < 8; i++) {
		table[i][place[i]] = 1;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
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

