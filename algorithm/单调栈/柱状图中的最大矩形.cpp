/**
 * 柱状图的最大矩形
 * 单调栈(单调递增栈)
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define MIN_INT -1

int main(){ 
    int n,top;
    cin>>n;
    vector<int>arr;
    stack<int> s;
    int res = 0;
    for(int i=0;i<n;i++){
        int mid;
        cin>>mid;
        arr.push_back(mid);
    }

    //将最小的数压入栈，确保所有元素都记录
    arr.push_back(MIN_INT);
    //依次入栈
    for(int i=0;i<(int)arr.size();i++){
        if(s.empty()||arr[s.top()]<=arr[i]){
            s.push(i);
        }else{
            while(!s.empty()&&arr[s.top()]>arr[i]){
                /*
                * mid记录要出栈下标
                * h 记录此时的高度
                * w为宽度
                * w = i - mid出栈后的栈顶元素的下标值-1   或者栈为空 也就是 i
                * 出栈矩形扫过的面积 w*h
                */
                int mid = s.top();
                int h = arr[mid];
                int w;
                s.pop();
                if(s.empty()){
                    w = i;
                }else{
                    w = i - s.top() -1;
                }
                res = max(res , w*h);
            }
            s.push(i);
        }
    }
    cout<<res<<endl;
    return 0;
}