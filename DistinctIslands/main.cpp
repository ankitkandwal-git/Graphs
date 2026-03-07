#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,int sr ,int sc,vector<pair<int,int>>&v,vector<vector<int>>&grid,vector<vector<int>>&visited){
    int m = grid.size();
    int n = grid[0].size();
    visited[i][j] = 1;
    v.push_back({i-sr,j-sc});
    if(i>0 && grid[i-1][j] == 1 && visited[i-1][j] == 0){
        dfs(i-1,j,sr,sc,v,grid,visited);
    }
    if(i<m-1 && grid[i+1][j] == 1 && visited[i+1][j] == 0){
        dfs(i+1,j,sr,sc,v,grid,visited);
    }
    if(j>0 && grid[i][j-1] == 1 && visited[i][j-1] == 0){
        dfs(i,j-1,sr,sc,v,grid,visited);
    }
    if(j<n-1 && grid[i][j+1] == 1 && visited[i][j+1] == 0){
        dfs(i,j+1,sr,sc,v,grid,visited);
    }
}
int countDistinctIslands(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] && !visited[i][j]){
                vector<pair<int,int>>v;
                dfs(i,j,i,j,v,grid,visited);
                st.insert(v);
            }
        }
    }
    return st.size();
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<countDistinctIslands(grid)<<endl;
    return 0;
}