#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>nearestZeroes(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>ans(m,vector<int>(n));
    vector<vector<int>>visited(m,vector<int>(n,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();
        ans[r][c] = d;
        if(r>0 && !visited[r-1][c]){
            q.push({{r-1,c},d+1});
            visited[r-1][c]=1;
        }
        if(r+1<m && !visited[r+1][c]){
            q.push({{r+1,c},d+1});
            visited[r+1][c]=1;
        }
        if(c>0 && !visited[r][c-1]){
            q.push({{r,c-1},d+1});
            visited[r][c-1]=1;
        }
        if(c+1<n && !visited[r][c+1]){
            q.push({{r,c+1},d+1});
            visited[r][c+1]=1;
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
    cout<<endl;
    vector<vector<int>>ans = nearestZeroes(grid);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}