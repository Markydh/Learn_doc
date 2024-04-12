// #include<iostream>
// #include<vector>
// using namespace std;

// typedef pair<int,int> PII;

// int main(){
//     vector<PII> ans;
//     int a[100100];
//     int n,m,x;
//     cin>>n>>m>>x;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=0;i<n;i++){
//         int res = a[i]^x;
//         for(int j=i+1;j<n;j++){
//             if(a[j]==res){
//                ans.push_back({i,j});
//             }
//         }
//     }

//     while(m--){
//         int s,e;
//         cin>>s>>e;
//         s--,e--;
//         int judge=0;
//         for(int i=0;i<(int)ans.size();i++){
//             if(s<=ans[i].first&&e>=ans[i].second){
//                 judge=1;
//                 break;
//             }
//         }
//         if(judge)cout<<"yes"<<endl;
//         else cout<<"no"<<endl;
//     }
//     return 0;
// }





/**
 * 2081 蓝桥别 选数异或
 * 动态规划
*/

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;

//值为i的左端的，使得d[i]-i 满足存在a^b = x
int dp[100020];

//记录值为i出现在最后的位置
unordered_map<int,int> u_map;


int main(){
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++){
        int data;
        cin>>data;
        dp[i]=max(dp[i-1],u_map[data^x]);
        u_map[data]=i;
    }

    while(m--){
        int l,r;
        cin>>l>>r;
        if(dp[r]>=l){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}