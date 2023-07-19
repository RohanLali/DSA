#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> ans){
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }
}

void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>> &ans){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    solve(nums,output,index+1,ans);
    int ele = nums[index];
    output.push_back(ele);
    solve(nums,output,index+1,ans);
}

vector<vector<int>> subset(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);
    return ans;
}

void solve2(string str,string output,int index,vector<string>&ans){
    if(index >=str.length()){
        if(output.length()>0){
            ans.push_back(output);
        }
        return;
    }
    solve2(str,output,index+1,ans);
    char ele = str[index];
    output.push_back(ele);
    solve2(str,output,index+1,ans);
}

vector<string> subsequence(string str){
    vector<string> ans;
    string output ="";
    int index=0;
    solve2(str,output,index,ans);
    return ans;
}

int main(){
    cout<<"enter now"<<endl;
    vector<int> nums ={1,2,3};
    vector<vector<int>> ans= subset(nums);
    print(ans);
    cout<<endl;
    string chars ="abc";
    vector<string> ans2=subsequence(chars);
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" "; 
    }
    return 0;
}