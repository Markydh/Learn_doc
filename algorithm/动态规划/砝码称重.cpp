

/**
 * 蓝桥杯 1447 砝码称重
 * 动态规划 
*/
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int w[110];
//前i个砝码构成重量为j可能性
int dp[110][100100];

int main(){
    int n;
    cin>>n;
    //m为最大重量
    int m=0;
    int res=0;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        m+=w[i];
    }

    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //不放第i个 ｜ 放在左边 ｜放右边
            dp[i][j] = dp[i-1][j] + dp[i-1][abs(j-w[i])]+dp[i-1][j+w[i]];
        }
    }

    for(int i = 1;i<=m;i++){
        if(dp[n][i]){
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}