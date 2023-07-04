#include <stdio.h>

#define N 1010

int n, m;
int v[N], w[N];
int f[N][N];

int max(int a, int b){
    if(a>=b){
        return a;
    }
    return b;
}


int main() {

    scanf("%d%d",&n,&m);

    for (int i = 1; i <= n; i++){
        scanf("%d%d",&v[i],&w[i]);
    }

    for (int i = 1; i <= n; i++){
         for(int j = 1; j <=m; j++) {
            if(j<v[i]){
                f[i][j]=f[i-1][j];
            }else{
                f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
            }
         }    
    } 
    printf("\n");
    for(int i=1; i<=n; i++){
        printf("X[%d] = %d \n",i,f[i][m]);
    }
       
    return 0;    
}
