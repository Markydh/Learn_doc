/**
 * Acwing 2060. 奶牛选美
 * dfs 
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

typedef struct{
    int a;
    int b;
} Point;

vector<Point> first;
vector<Point> second;
int n,m;
char arr[51][51];


//坐标偏移
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void dfs(int x,int y,vector<Point>& cub){
    cub.push_back({x,y});
    arr[x][y]='.';
    for(int i=0;i<4;i++){
        int a = x+dx[i];
        int b = y+dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && arr[a][b] == 'X') {
            dfs(a, b, cub);
        }
    }
}

int main(){

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];

int k=0;
    bool judge = true;
    for(int i=0;i<n&&judge;i++)
    for(int j=0;j<m;j++){
        if(arr[i][j]=='X'){
            dfs(i,j,first);
            judge=false;
            break;
        }   
    }

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        if(arr[i][j]=='X'){
            dfs(i,j,second);
            break;
        }   
    }

    int res = 120;
    for(auto& cub1 : first)
    for(auto& cub2 : second){
        res = min(res, abs(cub1.a-cub2.a)+abs(cub1.b-cub2.b));
    }
    cout<<res-1<<endl;
    return 0;
}