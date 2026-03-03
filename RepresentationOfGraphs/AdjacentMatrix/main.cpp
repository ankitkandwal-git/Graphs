#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj(n+1,vector<int>(n,0));
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}