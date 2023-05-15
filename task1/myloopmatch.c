// loop match schedule, thougt by Chen Yuxiao, designed by Liu Shaobing.
// version 1.0   --2023-05-15----
#include <stdio.h>
#define N	9
void InitSchedule(int**,int,int);  // set schedule to 0
void OutputSchedule(int**,int,int); // output arranged schedule
void ArrangeSchedule(int*,int*,int**,int,int); // main arrange 
void InitTeamNo(int*,int*,int);// initialize team Number
void TurnTeam(int*,int*,int); // turn around, team10-means no game.
int main(void)
{
	int schedule[N+2][N+2];// if N is even, then only+1, array[0] not used.
	int **psch;
	int teamA[(N+1)/2+1],teamB[(N+1)/2+1];// two column pears.

	InitTeamNo(teamA,teamB,(N+1)/2+1);
	psch=(int **) schedule;
	InitSchedule(psch,N+2,N+2);

	ArrangeSchedule(teamA,teamB,psch,N+2,N+2);
	printf("after arrange,the match schedule is:\n");
	OutputSchedule(psch,N+2,N+2);
}
void ArrangeSchedule(int teamA[],int teamB[],int** psch,int m,int n)
{
	int day,i,j;
	for(day=1;day<m-1;day++)
	{
		TurnTeam(teamA,teamB,n);
		*((int *)psch+day*n+1)=teamB[1];
		*((int *)psch+day*n+2)=teamB[n/2];
		for(i=1,j=2;i<n/2-1;i++,j++)
		{
			*((int *)psch+day*n+2*i+1)=teamA[i];
			*((int *)psch+day*n+2*i+2)=teamB[j];
		}
		*((int *)psch+day*n+2*i+1)=teamA[i];
		*((int *)psch+day*n+2*i+2)=teamA[i+1];
	}
}
void TurnTeam(int teamA[],int teamB[],int n)
{
	int j;
	for(j=0;j<n/2;j++) teamA[j]=teamA[j+1];
	teamA[n/2]=teamB[n/2-1];
	teamB[0]=teamA[0];
	for(j=n/2-1;j>0;j--) teamB[j]=teamB[j-1];
	// test begin here.......want to see if turn rightly.
	printf("teamA...\n");
	for(j=0;j<=n/2;j++)
		printf("%4d",teamA[j]);
	printf("\n");
	printf("teamB...\n");
	for(j=0;j<=n/2;j++)
		printf("%4d",teamB[j]);
	printf("\n");
	// test end here......
}
void InitSchedule(int** psch,int m,int n)
{
	int row,col;
	for(row=0;row<m;row++)
		for(col=0;col<n;col++)
			*((int *)psch+row*n+col)=0;
}
void OutputSchedule(int** psch,int m,int n)
{
	int row,col;
	for(row=1;row<m-1;row++)
	{
		for(col=1;col<n;col++)
			printf("%4d",*((int *)psch+row*n+col));
		printf("\n");
	}
}
void InitTeamNo(int teamA[],int teamB[],int n)
{
	int teamNo;
	for(teamNo=0;teamNo<n;teamNo++)
	{
		teamA[teamNo]=teamNo;
		teamB[teamNo]=teamNo+n-1;
	}
}