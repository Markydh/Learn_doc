/**
 * 蓝桥杯 1276 小明的彩灯
 * 差分
*/
#include<iostream>

using namespace std;

#define Max_INF 500010

long long a[Max_INF];


//记录每次操作的结果
long long b[Max_INF];

long long sum[Max_INF];


void insert(int l,int r,int v){
    b[l]+=v;
    b[r+1]-=v;
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l,r,v;
    while(q--){
        cin>>l>>r>>v;
        insert(l,r,v);
    }

    for(int i=1;i<=n;i++){
        sum[i]= sum[i-1]+b[i];
    }

    for(int i=1;i<=n;i++){
        a[i]+=sum[i];
        if(a[i]<0)cout<<0<<" ";
        else cout<<a[i]<<" ";
    }
    return 0;
}