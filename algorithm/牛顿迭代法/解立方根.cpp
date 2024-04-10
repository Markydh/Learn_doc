/**
 * 蓝桥杯 1217 解立方根
 * 牛顿迭代法（求方程的零点）
*/


// 求 N 的立方根
// 设x*x*x=N x^3=N 那么 x^3-N=0 
// 可以转化为求解 g(x)=x^3-N 的零点（浮点数）
// 牛顿迭代法


#include<iostream>
#include<math.h>
using namespace std;

double Newton(double x){
    if(x==0)return 0;   
    double x0 = x;
    double x1;
    while(true){
        x1 = x0-(x0*x0*x0*1.0-x)/(3*x0*x0);
        if(fabs(x1-x0)<0.0001)return x1;
        x0=x1;
    }
    return x1;
}

int main(){
    int n;
    cin>>n;
    double res;
    while(n--){
        int x;
        cin>>x;
        // double res = Newton(x);
        double l=0,r=100000;
        while(l<=r){
          double mid = (l+r)/2;
          if(fabs(mid*mid*mid-x)<1e-4){
            res = mid;
            break;
          }
          if(mid*mid*mid>x){
            r=mid-1e-4;
          }else{
            l=mid+1e-4;
            res=mid;
          }
        }
        printf("%.3lf\n",res);
    }
    return 0;
}