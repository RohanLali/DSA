#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sqrt(int n){
    int s=0,e=n;
    int mid;
    int ans=-1;
    while(s<=e){
        mid=(s+e)/2;  
        int sq = mid*mid;
        if(sq==n){
            return mid;
        }  
        if(sq<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}



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
    int x;
    cin>>x;
    cout<<getpivot(arr,n)<<endl;
    cout<<sqrt(x);
}