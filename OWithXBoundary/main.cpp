#include<bits/stdc++.h>
using namespace std;

void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&visited){
    int m = grid.size();
    int n = grid[0].size();
    visited[r][c] = 1;
    if(r>0 && grid[r-1][c] == 'O' && !visited[r-1][c]){
        dfs(r-1,c,grid,visited);
    }
    if(r<m-1 && grid[r+1][c] == 'O' && !visited[r+1][c]){
        dfs(r+1,c,grid,visited);
    }
    if(c>0 && grid[r][c-1] == 'O' && !visited[r][c-1]){
        dfs(r,c-1,grid,visited);
    }
    if(c<n-1 && grid[r][c+1] == 'O' && !visited[r][c+1]){
        dfs(r,c+1,grid,visited);
    }
}

void surrondWithX(vector<vector<char>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));
    for(int j=0;j<n;j++){
        if(grid[0][j]=='O' && visited[0][j]==0){
            dfs(0,j,grid,visited);
        }
        if(grid[m-1][j]=='O' && visited[m-1][j]==0){
            dfs(m-1,j,grid,visited);
        }
    }
    for(int i=0;i<m;i++){
        if(grid[i][0]=='O' && visited[i][0]==0){
            dfs(i,0,grid,visited);
        }
        if(grid[i][n-1]=='O' && visited[i][n-1]==0){
            dfs(i,n-1,grid,visited);
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]=='O' && !visited[i][j]){
                grid[i][j] = 'X';
            }
        }
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>>grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    surrondWithX(grid);
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}