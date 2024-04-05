/**
 * Acwing 687 扫雷
 * dfs
*/
#include<iostream>
#include<string>
using namespace std;

#define N 301

//雷盘规格
int n;
//记录雷盘状态
char str[310][310];
//记录每个点附近雷的数量
int cnt[N][N];

void dfs(int i,int j){
    //中止条件
    if(cnt[i][j]!=0){
        cnt[i][j]=-1;
        return;
    }
    //遍历
    for(int x = i-1;x<=i+1;x++)
    for(int y = j-1;y<=j+1;y++){
        if(x>=0&&x<n&&y>=0&&y<n){
            cnt[i][j]=-1;
            dfs(x,y);
        }
    }

}


int main(){
    int T;
    cin>>T;
    for(int k=1;k<=T;k++){
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
        }

        //记录相邻格子放雷的个数
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            //如果没有雷，则判断雷区
            if(str[i][j]!='*'){
                cnt[i][j]=0;
                //遍历相邻的
                for(int x = i-1;x<=i+1;x++)
                for(int y = j-1;y<=j+1;y++){
                    if(x>=0&&x<n&&y>=0&&y<n){
                        if(str[x][y]=='*')cnt[i][j]++;
                    }
                }
            }else cnt[i][j]=-1;
        }

        int res = 0; 

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(cnt[i][j]==0){
                res++;
                dfs(i,j);
            } 
        }


        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(cnt[i][j]>=1&&cnt[i][j]<=8)res++;
        }

       printf("Case #%d: %d\n", k,res);
    }
    return 0;
}