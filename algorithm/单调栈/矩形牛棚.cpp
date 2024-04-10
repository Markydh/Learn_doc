/**
 * Acwing 1413 矩形牛棚
 * 单调栈
*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

#define Max_INF 3000



int r,c,p;

int res =0;//记录最大的可能面积

//记录土地是否被破坏
int P[Max_INF+5][Max_INF+5];
//记录每个格子的高度
int h[Max_INF+5][Max_INF+5];


int f(int *h){
    stack<int> st;
    int temp =0 ;
    for(int i=1;i<=c+1;i++){
        //如果栈为空 或者 栈顶元素<=入栈元素，说明还能向右扩展，元素入栈
        if(st.empty()||h[st.top()]<=h[i]){
            st.push(i);
        }else{  
            while(!st.empty()&&h[st.top()]>h[i]){
                //记录出栈元素的下标
                int mid = st.top();
                //矩形的高度
                int hight = h[mid];
                //矩形的宽度
                int w;
                st.pop();
                //如果st
                if(st.empty()){
                    w=i-1;
                }else{
                    w = i- st.top()-1;
                }
                temp = max(temp,w*hight);
            }
            st.push(i);
        }
    }
    return temp;
}


int main(){
    cin>>r>>c>>p;
    while(p--){
        int x,y;
        cin>>x>>y;
        //记录被破坏的土地下标
        P[x][y]=1;
    }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            if(P[i][j]==0){
                h[i][j]=h[i-1][j]+1;
            }
        }
    for(int i=1;i<=r;i++){
        h[i][c+1]=-1;
        res = max(res,f(h[i]));
    }
    cout<<res<<endl;
    return 0;
}