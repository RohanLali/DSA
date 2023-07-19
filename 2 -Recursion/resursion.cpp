#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int factorial(int a){
    //base case
    if(a==0 || a==1){return 1;}
    //recursive call
    int smallans=factorial(a-1);
    //small calculation
    int finalans=a*smallans;


    return finalans;
}

int powerof2(int n){
    if(n==0){
        return 1;
    }
    return 2*powerof2(n-1);
}

//tail recursion
void print1(int m){
    if(m==0){
        return;
    }
    cout<<m<<endl;
    print1(m-1);
}

//head recursion
void print2(int m){
    if(m==0){
        return;
    }
    print2(m-1);
    cout<<m<<endl;
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

void saydigit(int f,string str[]){
    if(f==0){
        return;
    }
    saydigit(f/10,str);
    int digit=f%10;
    cout<<str[digit]<<" ";
    
}

int main(){
    cout<<"enter now"<<endl;
    int a;
    cin>>a;
    cout<<factorial(a)<<endl;
    int n;
    cin>>n;
    cout<<powerof2(n)<<endl;
    cout<<endl;
    int m=6;
    print1(m);
    cout<<endl;
    print2(m);
    cout<<"fibonacci: "<<fibonacci(m)<<endl;
    string str[10]={
        "zero","one","two","three","four","five","six","seven","eight","nine"
    };
    cout<<endl;
    int f;
    cin>>f;
    saydigit(f,str);
    return 0;
}