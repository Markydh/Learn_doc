/**
 *  Acwing 1402 星空之夜
 *  dfs Flood Fill  哈希存值
*/


#include <iostream>
using namespace std;

//宽度为w，h为高度
int w,h;
//记录每个星群的星星个数
int top;
//记录01序列夜空矩阵
char arr[110][110];

//记录每个星群的哈希值
double hash_val[30];
int cnt=0;
const double eps = 1e-8;

//记录每个星群中星星的坐标
typedef struct {
    int x;
    int y;
}Star;

Star star[170];


double get_hash(){
    double sum=0;
    for(int i=0;i<top;i++){
        for(int j = i+1;j<top;j++){
            sum+=(star[i].x-star[j].x)*(star[i].x-star[j].x)+(star[i].y-star[j].y)*(star[i].y-star[j].y);
        }
    }
    return sum;
}

char get_ch(){
    double val = get_hash();
    for(int i=0;i<cnt;i++){
        if(fabs(hash_val[i]-val)<eps){
            return 'a'+i;
        }
    }
    hash_val[cnt++] = val;
    return 'a'+cnt-1;
}


//Flood Fill 方法 遍历同一个星群
void dfs(int a,int b){
    star[top].x=a;
    star[top].y=b;
    top++;
    arr[a][b]='0';
    for(int x = a-1;x<=a+1;x++)
    for(int y = b-1;y<=b+1;y++){
        if(x>=0&&x<h&&y>=0&&y<w&&arr[x][y]=='1')
           dfs(x,y);
        }
}


int main(){
    cin>>w>>h;
    //输入01序列矩阵
    for(int i=0;i<h;i++){
        cin>>arr[i];
    }

    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++){
        //如果是星星，则用Flood fill法 查找星群
        if(arr[i][j]=='1'){
            top=0;
            dfs(i,j);
            char ch = get_ch();
            for(int k=0;k<top;k++){
                arr[star[k].x][star[k].y]=ch;
            }
        }
    }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}