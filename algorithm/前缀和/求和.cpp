/**
 * 求和
 * 暴力解法
*/
// #include<iostream>
// #include<vector>
// using namespace std;
// typedef long long ll;

// int main(){
//     vector<int> arr;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int temp;
//         cin>>temp;
//         arr.push_back(temp);
//     }
//     vector<ll> mid;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             ll temp = arr[i]*arr[j];
//             mid.push_back(temp);
//         }
//     }
//     ll res;
//     for(int i=0;i<mid.size();i++){
//         res+=mid[i];
//     }
//     cout<<res<<endl;
//     return 0;
// }




/**
 * 求和
 * 前缀和
 * a1*a2 + a1*a3 + ••• + a1*an  = a1*(s[n]-s[1])
 * a2*a3 + ••• a2*an = a2*(s[n]-s[2])
 * 
 * = an-1(s[n]-s[n-1])
*/


#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    arr.push_back(0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    ll s[n+1];
    s[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+arr[i];
    }
    ll res=0;
    for(int i=1;i<=n-1;i++){
        res += arr[i]*(s[n]-s[i]);
    }
    cout<<res<<endl;
    return 0;
}