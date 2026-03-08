#include<bits/stdc++.h>
using namespace std;

void dfs(int start,vector<vector<int>>&graph,vector<int>&visited,stack<int>&stk){
    visited[start] = 1;
    for(auto i: graph[start]){
        if(!visited[i]){
            dfs(i,graph,visited,stk);
        }
    }
    stk.push(start);
}

vector<int>topologicalSort(vector<vector<int>>&graph){
    int n = graph.size();
    vector<int>visited(n,0);
    stack<int>stk;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,graph,visited,stk);
        }
    }
    vector<int>ans;
    while(!stk.empty()){
        int x = stk.top();
        ans.push_back(x);
        stk.pop();
    }
    return ans;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>graph(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    cout<<endl;
    vector<int>ans = topologicalSort(graph);
    for(auto i: ans){
        cout<<i<<" ";
    }
}