#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define PI 3.14;   //macro-constant can not be changed occur many time in code so we replace its occurence everywhere in code

//inline func is macro function can contain only single line of code
inline int add2(int a,int b){
    return a+b;
}

//default argument s uses 0 if no value passed only right most can get default
int getsum(int arr[],int n,int s=0){
    int sum=0;
    for(int i=s;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}


int main(){
    cout<<"enter now"<<endl;
    int a=5,b=8;
    cout<<add2(a,b)<<endl;
    int arr[5]={1,2,3,4,5};
    int arr1[5]={1,2,3,4,5};
    cout<<getsum(arr,5)<<endl;
    cout<<getsum(arr1,5,2)<<endl;
    return 0;
}
