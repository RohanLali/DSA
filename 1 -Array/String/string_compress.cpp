#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string compress(string s){
    int n=s.length(), ansInd=0, i=0;
    string resultS;
    while(i<n) {
        int j=i+1;
        while(j<n && s[i]==s[j]) j++;
        resultS.push_back(s[i]);
        ansInd++;
        
        int count=j-i;
        if(count>1) {
            string cnt=to_string(count);
            for(char ch: cnt) resultS.push_back(ch), ansInd++;       
        }
        i=j;
    }
    cout<<resultS<<endl;
}

bool checkeql(int a[26],int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

bool inclusion(string s,string f){
    int count[26]={0};
    for(int i=0;i<s.length();i++){
        int index = s[i]-'a';
        count[index]++;
    }
    int i=0;
    int window=s.length();
    int count2[26]={0};
    while(i<window && i<f.length()){
        int index = f[i]-'a';
        count2[index]++;
        i++;
    }
    if(checkeql(count,count2)){
        return 1;
    }
    while(i<f.length()){
        char newchar = f[i];
        int index=newchar-'a';
        count2[index]++;
        char oldchar = f[i-window];
        index = oldchar-'a';
        count2[index]--;
        i++;
        if(checkeql(count,count2)){
        return 1;
    }
    }
    return 0;
}

int main(){
    cout<<"enter now"<<endl;
    string s;
    string f;
    getline(cin,s);
    getline(cin,f);
    compress(s);
    cout<<inclusion(s,f)<<endl;
    return 0;
}
