#include<bits/stdc++.h>
using namespace std;

bool dfs(int cur,vector<vector<int>>&graph,vector<int>&visited,vector<int>&path,vector<int>&ans){
    visited[cur] = 1;
    path[cur] = 1;
    for(auto i:graph[cur]){
        if(visited[i]==0){
            if(dfs(i,graph,visited,path,ans)) return true;
        }
        else if(path[i]) return true;
    }
    path[cur] = 0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> path(n,0);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i,graph,visited,path,ans);
        }
    }
    for(int i=0;i<n;i++){
        if(path[i]==0) ans.push_back(i);
    }
    return ans;
}