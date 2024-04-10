/**
 * 蓝桥杯 1216 走迷宫
 * bfs
*/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int ,int> point;
//记录每个点到初始点的最短距离
int dist[110][110];

//记录迷宫状态
int b[110][110];

int n,m;

int x,y,x2,y2;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int bfs(){
    queue<point> q;
    q.push({x,y});
    while(!q.empty()){
        point a = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx=dx[i]+a.first;
            int yy=dy[i]+a.second;
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&b[xx][yy]!=0&&dist[xx][yy]==-1){
                dist[xx][yy]=dist[a.first][a.second]+1;
                q.push({xx,yy});
            }
        }
    }
    return dist[--x2][--y2];
}

int main(){
    cin>>n>>m;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    cin>>x>>y>>x2>>y2;
    memset(dist,-1,sizeof(dist));
    dist[--x][--y]=0;
    cout<<bfs()<<endl;
    return 0;
}