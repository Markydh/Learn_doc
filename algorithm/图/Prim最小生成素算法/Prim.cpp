/**
 * @author: mark_ydh
 * @desc：Prim 最小生成树
 * @date: 2024-09-01 10:42:09
 * @Email：2247654142@qq.com
 */

/**
 * 思想
 * 通过切片定理 
 * 1.先初始一个节点 将他的邻接边全部放入优先队列中（按权值从小到大排序）
 * 2.然后从优先队列弹出边（权值最小）将新的节点重新进行 1 的操作 知道队列为空
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Edge{   
    public:
        int to;
        int weight; 
};

class Graph{
    private:
        vector<vector<Edge>>graph;
    public:
        Graph(int n){
            graph.resize(n);
        }
        void addEdge(int from,int to,int weight){
            graph[from].push_back({to,weight});
            graph[to].push_back({from,weight});
        }
        vector<Edge> nearby(int n){
            return graph[n];
        }
};

//优先队列自定义类
class cmp{
    public:
        bool operator()(vector<int>& a,vector<int>&b){
            return a[2]>b[2];
        }
};

priority_queue<vector<int>,vector<vector<int>>,cmp>que;
vector<bool>visited;
int res =0;


//对节点n进行切片，把他的邻接边放入优先队列中（对方节点已存在生成树内的边忽略）
void cut(int n,Graph g){
    for(auto i:g.nearby(n)){
        if(visited[i.to]==true)continue;
        que.push({n,i.to,i.weight});
    }
}

void bfs(Graph& g){
    visited[1]=true;
    cut(1,g);
    while(!que.empty()){
        auto edge = que.top();
        que.pop();
        if(visited[edge[1]])continue;
        res+=edge[2];
        visited[edge[1]]=true;
        cut(edge[1],g);
    }
}

int minimumCost(int n,vector<vector<int>>& connections){
    Graph g(n+1);
    for(int i=0;i<connections.size();i++){
        g.addEdge(connections[i][0],connections[i][1],connections[i][2]);
    }
    bfs(g);
    for(int i=1;i<=n;i++){
        if(visited[i]==false)return -1;
    }
    return res;
}

int main() {
    int n=3;
    visited.resize(n+1,false);
    vector<vector<int>>conections = {{1,2,5},{2,3,6},{2,3,2},{1,3,1}};
    cout<<minimumCost(n,conections)<<endl;
    return 0;
}

