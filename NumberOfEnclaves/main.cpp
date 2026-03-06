#include<bits/stdc++.h>
using namespace std;

void dfs(int r , int c,vector<vector<int>>&grid,vector<vector<int>>&visited){
    int m = grid.size();
    int n = grid[0].size();
    visited[r][c] = 1;
    if(r>0 && grid[r-1][c] == 1 && !visited[r-1][c]){
        dfs(r-1,c,grid,visited);
    }
    if(r<m-1 && grid[r+1][c] == 1 && !visited[r+1][c]){
        dfs(r+1,c,grid,visited);
    }
    if(c>0 && grid[r][c-1] == 1 && !visited[r][c-1]){
        dfs(r,c-1,grid,visited);
    }
    if(c<n-1 && grid[r][c+1] == 1 && !visited[r][c+1]){
        dfs(r,c+1,grid,visited);
    }
}

int numberOfEnclaves(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));
    for(int j=0;j<n;j++){
        if(grid[0][j] == 1 && !visited[0][j]){
            dfs(0,j,grid,visited);
        }
        if(grid[m-1][j]==1 &&1  && !visited[m-1][j]){
            dfs(m-1,j,grid,visited);
        }
    }
    for(int i=0;i<m;i++){
        if(grid[i][0] == 1 && !visited[i][0]){
            dfs(i,0,grid,visited);
        }
        if(grid[i][n-1] == 1 && !visited[i][n-1]){
            dfs(i,n-1,grid,visited);
        }
    }
    int count = 0;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                count++;
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
    cout<<numberOfEnclaves(grid)<<endl;
    return 0;
}