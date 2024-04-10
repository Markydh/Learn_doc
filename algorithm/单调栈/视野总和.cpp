#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define MAX_INF 10000001

int main(){
    int n;
    int sum=0;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int mid;
        cin>>mid;
        arr.push_back(mid);
    }
    arr.push_back(MAX_INF);
    stack<int> a;
    for(int i=0;i<(int)arr.size();i++){
        //如果栈为空，并且栈顶元素大于等于要入栈元素
        if(a.empty()||arr[a.top()]>arr[i]){
            //将下标存入
            a.push(i);
        }else{
            while(!a.empty()&&arr[a.top()]<=arr[i]){
                int mid = a.top();
                a.pop();
                sum+=i-mid-1;
            }
            a.push(i);
        }
    }
    cout<<sum<<endl;
}