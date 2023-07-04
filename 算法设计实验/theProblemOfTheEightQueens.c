#include <stdio.h>

#define NUMS 8

int place[NUMS] = {0}; //�ʺ�λ��

int flag[NUMS] ;		
int d1[2 * NUMS - 1];		//�����϶Խ���
int d2[2 * NUMS - 1]; 		//�����¶Խ���
int count = 0; 			//��¼�������

int queen(int n) {
	int col;//����
	for (col = 0; col < NUMS; col++) {
		if (!flag[col] && !d1[n - col + NUMS - 1] && !d2[n + col]) { //�жϻʺ��Ƿ��ͻ

			place[n] = col; //���ûʺ�
			flag[col] = 1;
			d1[n - col + NUMS - 1] = 1;
			d2[n + col] = 1; //���ûʺ����ڵ��С��С��Խ�������Ϊ��ռ��

			if (n < NUMS - 1)	{
				queen(n + 1);
			} else {
				count++;
			}
			
			flag[col] = 0; //����
			d1[n - col + NUMS - 1] = 0;
			d2[n + col] = 0;
		}
	}
	return count;
}

int main() {
	count = queen(0); 
	printf("%d", count); 
}

