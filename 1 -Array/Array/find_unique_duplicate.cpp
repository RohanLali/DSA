#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int findUnique(int a[], int n,int k) {
        sort(a,a+n);
        for(int i=0;i<n;i=i+k){
            if(a[i]!=a[i+k-1]){
                return a[i];
            }
        }
}

int findduplicate(int arr[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    for(int i=1;i<n;i++){
        ans=ans^1;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findUnique(arr,n,k)<<endl;
    cout<<findduplicate(arr,n)<<endl;
}