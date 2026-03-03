#include<bits/stdc++.h>
using namespace std;

void numberOfProvinces(int start, int n, vector<int>&visited ,vector<vector<int>>& adj){
    queue<int>q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto k:adj[cur]){
            if(!visited[k]){
                visited[k]=1;
                q.push(k);
            }
        }
    }
}
int NOP(int n, vector<vector<int>>&adj){
    int num = 0;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            num++;
            numberOfProvinces(i,n,visited,adj);
        }
    }
    return num;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<NOP(n,adj)<<endl;

}