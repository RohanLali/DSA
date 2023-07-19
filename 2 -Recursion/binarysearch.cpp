#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool issorted(int arr[],int s){
    if(s==0 || s==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        issorted(arr+1,s-1);
    }
}

int getsum(int arr[],int s){
    if(s==0){
        return 0;
    }
    if(s==1){
        return arr[0];
    }
    int sum=arr[0]+getsum(arr+1,s-1);
    return sum;
}

bool linearsearch(int arr[],int s,int x){
    if(s==0){
        return false;
    }
    if(arr[0]==x){
        return true;
    }
    else{
        return linearsearch(arr+1,s-1,x);
    }
}

bool binarysearch(int arr[],int s,int e,int x){
    int mid=(s+e)/2;
    if(s>e){
        return false;
    }
    if(arr[mid]==x){
        return true;
    }
    if(arr[mid]<x){
        binarysearch(arr,mid+1,e,x);
    }
    else{
        binarysearch(arr,s,mid-1,x);
    }
}

int main(){
    cout<<"enter now"<<endl;
    int arr[6]={2,4,6,9,11,13};
    cout<<issorted(arr,6)<<endl;
    cout<<getsum(arr,6)<<endl;
    cout<<linearsearch(arr,6,9)<<endl;
    cout<<binarysearch(arr,0,6,1)<<endl;
    return 0;
}