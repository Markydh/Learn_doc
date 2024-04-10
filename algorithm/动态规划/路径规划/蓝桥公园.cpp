/**
 *  蓝桥杯 1121 蓝桥公园
 *  弗洛伊德算法
*/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_INF 1e11+10

int n,m,q;

long long  dist[500][500];

//弗洛伊德算法
void flyd(){
        for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
          }
        }
}


int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(i==j)dist[i][j]=0;
        else{
          dist[i][j]= MAX_INF;
        }
    }

    while(m--){
        int x,y;
        long long w;
        cin>>x>>y>>w;
        //这里不同的是，需要每次更新景点x->y的最短距离
        dist[x][y]=dist[y][x]=min(w,dist[x][y]);      
    }

  while(q--){
     int x,y;
     cin>>x>>y;
     if(dist[x][y]>=MAX_INF)cout<<-1<<endl;
     else cout<<dist[x][y]<<endl;
  }
    return 0;
}