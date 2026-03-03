#include<bits/stdc++.h>
using namespace std;

vector<int>BFS(int n,vector<vector<int>>&adj){
    queue<int>q;
    q.push(0);
    int visited[n] = {0};
    vector<int>ans;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto i:adj[cur]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<endl;
    vector<int>ans = BFS(m,adj);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}