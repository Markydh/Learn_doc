/**
 * 蓝桥杯 1135 蓝桥幼儿园 
 * 并查集
*/

#include<iostream>
using namespace std;

int n,m;

//记录结点的父亲
int fa[200100];

//并查集初始化,每个结点的父结点都是自己
void init(){
    for(int i=0;i<n;i++){
        fa[i]=i;
    }
}

//查找父结点
int find(int i){
    if(i==fa[i])return i;
    else{
        fa[i]=find(fa[i]);
    }
    return fa[i];
}

//合并
void unin(int x,int y){
    int fa_x = find(x);
    int fa_y = find(y);
    fa[fa_x] = fa_y;
}

int main(){
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            unin(x,y);
        }
        if(op==2){
            int a;
            //属于一个集合则返回1，否则返回0
            a = find(x)==find(y)?1:0;
            if(a)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}