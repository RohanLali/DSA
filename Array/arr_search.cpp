#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool linearsearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return true;
        }
    }
    return false;
}

int binarysearch(int arr[],int n,int x){
    int s=0,e=n-1;
    int mid;
    while(s<=e){
        mid=(s+e)/2;  //optimise - s+(e-s)/2
        if(arr[mid]==x){
            return mid;
        }
        if(x>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }   
    }
    return -1;
}

int main(){
    int n,x;
    cin>>n;
    cin>>x;
    int arr[100];
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }
    cout<<linearsearch(arr,n,x)<<endl;
    cout<<binarysearch(arr,n,x)<<endl;
    return 0;
}