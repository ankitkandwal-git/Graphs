#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j,vector<vector<int>>&grid,vector<vector<int>>&visited){
    int m = grid.size();
    int n = grid[0].size();
    visited[i][j] = 1;
    if(i>0 && grid[i-1][j]==1 && visited[i-1][j]==0){
        dfs(i-1,j,grid,visited);
    }
    if(i+1<m && grid[i+1][j]==1 && visited[i+1][j]==0){
        dfs(i+1,j,grid,visited);
    }
    if(j>0 && grid[i][j-1]==1 && visited[i][j-1]==0){
        dfs(i,j-1,grid,visited);
    }
    if(j+1<n && grid[i][j+1]==1 && visited[i][j+1]==0){
        dfs(i,j+1,grid,visited);
    }
}

int numberOfIslands(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));
    int count = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && visited[i][j]==0){
                count++;
                dfs(i,j,grid,visited);
            }
        }
    }
    return count;
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
    cout<<endl;
    cout<<"The number of Islands is: "<<numberOfIslands(grid)<<endl;
    return 0;
}