#include<bits/stdc++.h>
using namespace std;

bool bfs(int start,vector<vector<int>>&graph,vector<bool>&visited){
    queue<pair<int,int>>q;
    q.push({start,-1});
    visited[start]=true;
    while(!q.empty()){
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto i :graph[cur]){
            if(!visited[i]){
                visited[i]=true;
                q.push({i,cur});
            }
        }
    }
    return false;
}

bool cycleDetection(vector<vector<int>>&graph){
    int n = graph.size();
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(bfs(i,graph,visited)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>graph(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(cycleDetection(graph)){
        cout<<"Cycle Detected"<<endl;
    }else{
        cout<<"No Cycle Detected"<<endl;
    }
    return 0;
}