#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<vector<int>>&grid,int start,int newColor){
    int m = grid.size();
    int n = grid[0].size();
    grid[i][j] = newColor;
    if(i>0 && grid[i-1][j]==start){
        dfs(i-1,j,grid,start,newColor);
    }
    if(i+1<m && grid[i+1][j]==start){
        dfs(i+1,j,grid,start,newColor);
    }
    if(j>0 && grid[i][j-1]==start){
        dfs(i,j-1,grid,start,newColor);
    }
    if(j+1<n && grid[i][j+1]==start){
        dfs(i,j+1,grid,start,newColor);
    }
}

vector<vector<int>>floodFill(vector<vector<int>>&grid,int r,int c,int newColor){
    int m = grid.size();
    int n = grid[0].size();
    int start = grid[r][c];
    if(start == newColor) return grid;
    dfs(r,c,grid,start,newColor);
    return grid;
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
    int r,c,newColor;
    cin>>r>>c>>newColor;
    vector<vector<int>>ans = floodFill(grid,r,c,newColor);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}