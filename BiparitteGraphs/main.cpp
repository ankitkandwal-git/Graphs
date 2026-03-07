#include<bits/stdc++.h>
using namespace std;

bool bfs(int start,vector<vector<int>>&graph,vector<int>&visited){
    queue<int>q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto i:graph[cur]){
            if(visited[i]==-1){
                q.push(i);
                visited[i]=1-visited[cur];
            }
            else {
                return false;
            }
        }
    }
    return true;
}
bool bipartite(vector<vector<int>>&graph){
    int n = graph.size();
    vector<int>visited(n,-1);
    for(int i=0;i<n;i++){
        if(visited[i]==-1){
            if(!bfs(i,graph,visited)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(bipartite(graph)){
        cout<<"Graph is bipartite"<<endl;
    }
    else {
        cout<<"Graph is not bipartite"<<endl;
    }
}