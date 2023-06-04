#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int getpivot(int arr[],int n){
    int s=0,e=n-1;
    int mid;
    while(s<e){
        mid=(s+e)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}

int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<getpivot(arr,n)<<endl;
}