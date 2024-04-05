/**
 * 蓝桥杯
 * 灭鼠先锋
 * 算法：模拟/博弈
*/


#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;


unordered_map<string,bool> u_map;


bool status(string s){
    int cnt=0;
    for(char ch : s){
        if(ch=='O')cnt++;
    }
    if(cnt==1)return true;
    else return false;
}


/**
 * 后手必胜/必败
*/
bool dfs(string s){
    //如果以及记录他的胜负态，直接返回
    if(u_map.count(s))return u_map[s];
    if(status(s))return  u_map[s] = false;
    
    // 只放一个 
    for(int i=0;i<s.length();i++){
        if(s[i]=='X')continue;
         string temp  = s;
        temp[i]='X';
        if(!dfs(temp))return u_map[s] = true;
    }
    //放入两个
    for(int i=0;i<s.length()-1;i++){
       if(s[i]=='O'&&s[i+1]=='O'&&i!=3){
        string temp = s;
        temp[i]=temp[i+1]='X';
        if(!dfs(temp))return u_map[s] = true;
       }
    }
    return u_map[s]=false;
}



int main(){
    vector<string> arr={"XOOOOOOO","XXOOOOOO","OXOOOOOO","OXXOOOOO"};
    for(string s : arr){
        if(dfs(s))cout<<"L"<<" ";
        else cout<<"V"<<" ";
    }
    cout<<endl;
}