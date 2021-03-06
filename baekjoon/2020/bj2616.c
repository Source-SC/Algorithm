#include <stdio.h>
#include <stdlib.h>

int tr_main(int answer[][4],int train[],int n,int p,int remain,int now){
    if(now == n && remain == 0){
        return 0;
    }
    if(now > n-1 || remain < 0){
        return float('inf')*(-1);
    }
    if(answer[now][remain] != -1){
        return answer[now][remain];
    }
    int tmp1,tmp2;
    tmp1 = sum(train[now:now+p]) + tr_main(answer,train,n,p,remain-1,now+p)
    tmp2 = tr_main(answer,train,n,p,remain,now+1)
    maximum = max(tmp1, tmp2)
    answer[now][remain] = maximum
    return maximum
}


int main{

int i,j,n,p;
int *train;
int answer[50001][4];

scanf("%d",&n);
train = (int*)malloc(sizeof(int)*(n+1));
scanf("%d",&p);
for(i=1;i<(n+1);i++){
    for(j=0;j<4;j++){
        answer[i][j] = 0;
    }
}

print(tr_main(answer, train,n,p,3,0))

}
// # 500
// # 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 34 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 3410 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 34 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34 10 20 30 10 20 10 19 28 68 58 47 46 57 62 71 24 68 71 24 68 73 26 48 72 34
// # 5