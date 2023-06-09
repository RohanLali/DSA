#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getsize(char name[]){
    int ans=0;
    for(int i=0;name[i]!=0;i++){
        ans++;
    }
    return ans;
}

char lowercase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch - 'A'+'a';
        return temp; 
    }
}

void reverse(char name[]){
    int s=0;
    int e=getsize(name)-1;
    while(s<=e){
        swap(name[s],name[e]);
        s++;
        e--;
    }
}

bool palindrome(char name[]){
    int s=0;
    int e=getsize(name)-1;
    while(s<=e){
        if(name[s]!=name[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
        return 1;
    }
}

int main(){
    cout<<"enter now"<<endl;
    char name[20];
    cin>>name;
    char ch;
    cin>>ch;
    cout<<name<<endl;
    cout<<"size: "<< getsize(name) <<endl;
    reverse(name);
    cout<<"reverse string: "<<name<<endl;
    cout<<"palindrome: "<<palindrome(name)<<endl;
    cout<<"lowercase: "<<lowercase(ch)<<endl;
    return 0;
}