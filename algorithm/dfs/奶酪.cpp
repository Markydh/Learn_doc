/**
 * Acwing 528 奶酪
 * dfs / bfs /并查集
*/

#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

typedef long long ll;

//定义坐标
typedef struct{
    ll x;
    ll y;
    ll z;
} Point;

//记录空洞的三维坐标
Point point[1010];

//高度和半径
ll h,r;
//n表示奶酪数   
int n;

bool myLaw(Point a,Point b){
    return a.z<b.z;
}

bool dfs(int index){
    Point chesses = point[index];
    //目前条件 == 目标条件
    if(chesses.z+r>=h)return true;
    //如果遍历到最高的一块奶酪但是还无法到达顶部的话返回false;
    if(index == n-1)return false;

    for(int j=index+1;j<n;j++){
        //如果当前空洞可以跳转到指定空洞，则遍历下一个空洞
        //求两个圆心的距离
        if(((chesses.x-point[j].x)*(chesses.x-point[j].x)+(chesses.y-point[j].y)*(chesses.y-point[j].y)+(chesses.z-point[j].z)*(chesses.z-point[j].z))<=4LL*r*r&&dfs(j))
            return true;    
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int judge = 0;
        cin>>n>>h>>r;
        for(int i =0 ;i<n;i++){
            cin>>point[i].x>>point[i].y>>point[i].z;
        }

        //z坐标升序排列
        sort(point,point+n,myLaw);
        for(int i=0;i<n;i++){
            if(point[i].z-r<=0&&dfs(i)){
                judge=1;
                break;
            } 
        }
        if(judge)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}



