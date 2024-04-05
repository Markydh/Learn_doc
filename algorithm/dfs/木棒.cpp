/**
 * 木棒
 * dfs
*/
#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;

int n=1;
//记录木棒长度
int sticks[70];
//记录小木块是否被访问
bool Visit[70];
//len表示合并后每一个木棒的长度,sum表示所有木棒加起来的长度
int len,sum;

//num表示结合的木棒数 cur表示目前组合的木棍长度 start表示开始的下标
bool dfs(int num,int cur,int start){
    //如果总数等于总长度，说明方案通过
    if(num*len==sum)return true;
    //如果当前长度等于len，结合下一个木棍
    if(cur==len)return dfs(num+1,0,0);
    if(cur==len&&((sum-(num+1)*len))%len!=0)return false;
    for(int i=start;i<n;i++){
        if(Visit[i])continue;
        //如果长度大于len，返回false;
        if(cur+sticks[i]<=len){
            Visit[i]=true;
            if(dfs(num,cur+sticks[i],i+1))return true;
            Visit[i]=false;
        }
        if(!cur||cur+sticks[i]==len)return false;
        int j=i+1;
        while(j<n&&sticks[i]==sticks[j])j++;
        i=j-1;
    }
    return false;
}

int main(){
    while(cin>>n,n){
        sum=len=0;
        //记录每一节木棒长度
        for(int i=0;i<n;i++){
            cin>>sticks[i];
            sum+=sticks[i];
            //木棒结合后的最小长度>=所有中小木棍最长
            len=max(len,sticks[i]);
        }
        memset(Visit, 0, sizeof Visit);
        sort(sticks,sticks+n,greater<int>());
        while(true){
            if(sum%len==0&&dfs(0,0,0)){
                cout<<len<<endl;
                break;
            }
            len++;
        }
    }

    return 0;
}