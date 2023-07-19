#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void helper(string digit,string op,int index,vector<string>& ans,string mapping[]){
    if(index>=digit.length()){
        ans.push_back(op);
        return;
    }
    int number = digit[index]-'0';
    string value = mapping[number];
    for(int i=0;i<value.length();i++){
        op.push_back(value[i]);
        helper(digit,op,index+1,ans,mapping);
        op.pop_back();
    }
}

vector<string> lettercombo(string digits){
    vector<string> ans;
    if(digits.length()==0){
        return ans;
    }
    string op="";
    int index=0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    helper(digits,op,index,ans,mapping);
    return ans;
}

void solve(vector<int> num,vector<vector<int>>& ans,int index ){
    if(index>=num.size()){
        ans.push_back(num);
        return;
    }
    for(int j=index;j<num.size();j++){
        swap(num[index],num[j]);
        solve(num,ans,index+1);
        //used for backtrack as we update original num so we need to undo the changes so we reverse swap
        swap(num[index],num[j]);
    }
}

vector<vector<int>> permute(vector<int> num){
    vector<vector<int>> ans;
    int index=0;
    cout<<index;
    solve(num,ans,index);
    return ans;
}

int main(){
    cout<<"enter now"<<endl;
    string a;
    cin>>a;
    cout<<a<<endl;
    vector<string> ans1 = lettercombo(a);
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    vector<int> num ={1,2,3};
    vector<vector<int>>ans = permute(num);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

 