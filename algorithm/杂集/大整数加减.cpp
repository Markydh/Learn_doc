/**
 * 大整数加法
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//存储超大整数
int c[20];

void sumA(int a){
    string s = to_string(a);
    //记录整数的长度
    int len  = s.length();
    reverse(s.begin(),s.end());
    for(int i=0;i<len;i++){
        c[i]+=(s[i]-'0');
        if(c[i]>=10){
            c[i]-=10;
            c[i+1]++;
        }
    }
    for(int i = len ; i<20;i++){
        if(c[i]>=10){
            c[i]-=10;
            c[i+1]++;
        }
    }
}

int main(){
    memset(c,0,sizeof(c));
    for(int i=1;i<=20230408;i++){
        sumA(i);
    }
    int judge=0;
    for(int i=19;i>=0;i--){
        if(c[i]!=0){
            cout<<c[i];
            judge=1;
        }
        if(c[i]==0){
            if(judge)cout<<0;
        }
    }
    cout<<endl;
    return 0;
}




/**
 * 大整数减法
*/

#include<iostream>
using namespace std;

//记录大整数1
int a1[30];
//记录大整数2
int a2[30];

int main(){
    string s1;
    string s2;
    //假设两个都是正数
    cin>>s1>>s2;
    //翻转两个整数
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int len1 = s1.size();
    int len2 = s2.size();
    //将两个大整数存储在整形数组中
    if(len1>len2||(len1==len2&&s1>s2)){
        for(int i=len1-1;i>=0;i--){
            a1[i]=s1[i]-'0';
        }
        for(int i=len2-1;i>=0;i--){
            a2[i]=s2[i]-'0';
        }
    }else{
         for(int i=len2-1;i>=0;i--){
            a1[i]=s2[i]-'0';
        }
        for(int i=len1-1;i>=0;i--){
            a2[i]=s1[i]-'0';
        }
    }


    for(int i=0;i<30;i++){
        a1[i]-=a2[i];
        if(a1[i]<0){
            a1[i]=10+a1[i];
            a1[i+1]--;
        }
    }

    int judge=0;
    for(int i=29;i>=0;i--){
        if(a1[i]!=0){
            judge=1;
            cout<<a1[i];
        }
        if(a1[i]==0){
            if(judge)cout<<0;
        }
    }

    cout<<endl;
    return 0;
}