#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool valid(char ch){
    if((ch>='a' && ch<='z') || (ch >='A' && ch<='Z') || (ch>='0' && ch<='9')){
        return 1;
    }
    return 0;
}

char tolowercase(char ch){
    if((ch >= 'a' && ch <='z') || (ch >= '0' && ch <= '9')){
        return ch;
    }
    else{
        char temp = ch-'A'+'a';
        return temp;
    }
}

bool checkpalindrome(string a){
    int s=0;
    int e=a.length()-1;
    while(s<=e){
        if(a[s]!=a[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

bool palindrome(string s){
    string temp = "";
    for(int j=0;j<s.length();j++){
        if(valid(s[j])){
            temp.push_back(s[j]);
        }
    }
    for(int j=0;j<temp.length();j++){
        temp[j] = tolowercase(temp[j]);
    }
    return checkpalindrome(temp);
}

char maxoccrchar(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int no=0;
        no=ch-'a';
        arr[no]++;
    }
    int max=-1,ans=0;
    for(int i=0;i<26;i++){
        if(max<arr[i]){
            ans=i;
            max=arr[i];
        }
    }
    char finalans='a'+ans;
    return finalans;
}

void replacespace(string s){
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(s[i]);
        }
    }

    cout<<temp<<endl;
    // int i;
    // for(i=0;temp[i]!='\0';i++){
    //     s[i]=temp[i];
    // }
    // s[i+1]='\0';
}

int main(){
    cout<<"enter now"<<endl;
    string s;
    getline(cin,s);
    cout<<palindrome(s)<<endl;
    cout<<maxoccrchar(s)<<endl;
    replacespace(s);
    return 0;
}