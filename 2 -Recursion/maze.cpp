#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool safe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>>&m){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] ==0 && m[x][y]==1){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> &m,int n,vector<string> &ans,int x,int y,vector<vector<int>> visited,string path){

if(x==n-1 && y==n-1){
    ans.push_back(path);
    return;
}
visited[x][y]=1;
//down
int newx=x+1;
int newy=y;
if(safe(newx,newy,n,visited,m)){
    path.push_back('D');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();
}
//left
 newx=x;
 newy=y-1;
if(safe(newx,newy,n,visited,m)){
    path.push_back('L');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();
}
//rigth
 newx=x;
 newy=y+1;
if(safe(newx,newy,n,visited,m)){
    path.push_back('R');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();
}
//up
newx=x-1;
 newy=y;
if(safe(newx,newy,n,visited,m)){
    path.push_back('U');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();
}
visited[x][y]=0;
}

vector<string> findpath(vector<vector<int>> &m,int n){
    vector<string> ans;
    if(m[0][0] ==0){
        return ans;
    }
    int x=0;
    int y=0;
    vector<vector<int>> visited=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    string path= "";
    solve(m,n,ans,x,y,visited,path);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    cout<<"enter now"<<endl;
    int n=4;
    vector<vector<int>> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans1 = findpath(m,n);
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
}


// rat in a maze
// 4 moves - up(x-1,y)
//         - down(x+1,y)
//         -left(x,y-1)
//         -right(x,y+1)
// action - 1 - go 
//          0 - no go
//   0 1 2 3 
// 0 1 0 0 0
// 1 1 1 0 1
// 2 1 1 0 0
// 3 0 1 1 1
// source- 0,0 desti - 3,3
// here ans - DDRDRR

