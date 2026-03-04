#include<bits/stdc++.h>
using namespace std;

int rottenOrange(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto x = q.front();
        int r = x.first.first;
        int c = x.first.second;
        int t = x.second;
        ans = max(ans,t);
        q.pop();
        if(r>0 && grid[r-1][c]==1 && visited[r-1][c]==0){
            q.push({{r-1,c},t+1});
            visited[r-1][c]=1;
        }
        if(r<m-1 && grid[r+1][c]==1 && visited[r+1][c]==0){
            q.push({{r+1,c},t+1});
            visited[r+1][c]=1;
        }
        if(c>0 && grid[r][c-1]==1 && visited[r][c-1]==0){
            q.push({{r,c-1},t+1});
            visited[r][c-1]=1;
        }
        if(c<n-1 && grid[r][c+1]==1 && visited[r][c+1]==0){
            q.push({{r,c+1},t+1});
            visited[r][c+1]=1;
        }
    }
     for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1 && !visited[i][j])
                return -1;
        }
    }
    return ans;
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
    cout<<rottenOrange(grid)<<endl;
}