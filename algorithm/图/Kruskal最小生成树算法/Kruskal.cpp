/**
 * @author: mark_ydh
 * @desc：Kruscal 最小生成树
 * @date: 2024-08-31 11:33:30
 * @Email：2247654142@qq.com
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class UF{
    private:
        vector<int>parent;
         int cnt;
    public:
        UF(int n){
            parent.resize(n+1);
            for(int i=1;i<=n;i++)parent[i]=i;
            cnt = n;
        }
        int find(int q){
            if(parent[q]!=q){
                parent[q]=find(parent[q]);
            }
            return parent[q];
        }
        void Union_(int p,int q){
            int rootP = find(p);
            int rootQ = find(q);
            if(rootP==rootQ) return;
            parent[rootP]=rootQ;
            cnt--;
        }
        bool connect(int p,int q){
            return find(p)==find(q);
        }
        int count(){
            return cnt;
        }
};

class cmp{
    public:
        bool operator()(vector<int>&a,vector<int>&b){
            return a[2]>b[2];
        }
};

//优先队列 
priority_queue<vector<int>,vector<vector<int>>,cmp> q;

//对每条边进行堆排序 权值从小到大
void sortEdge(vector<vector<int>>& connections){
    for(auto i : connections){
        q.push(i);
    };
}


int minimumCost(int n,vector<vector<int>>& connections){
    UF uf(n);
    int res=0;
    sortEdge(connections);
    while(!q.empty()){
        auto i = q.top();
        q.pop();
        if(uf.connect(i[0],i[1]))continue;
        uf.Union_(i[0],i[1]);
        res+=i[2];
    }
    if(uf.count()!=1)return -1;
    else return res;
}

int main() {
    int n=5;
    vector<vector<int>> connections{{1,2,1},{1,4,7},{2,4,7},{2,3,6},{3,4,3},{4,5,8}};
    cout<<minimumCost(n,connections)<<endl;
    return 0;
}
