#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getmax(int arr[],int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max=arr[i];
        }
    }
    return max;
}

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reversearr(int arr[],int n){
    int s,e;
    s=0;
    e=n-1;
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    } 
}

void swapalt(int arr[],int n){
    int i;
    for(int i=0;i<n;i+=2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }
}

void movezeros(int arr[],int n){
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printarr(arr,n);
    cout<<getmax(arr,n)<<endl;
    movezeros(arr,n);
    printarr(arr,n);
    reversearr(arr,n);
    printarr(arr,n);
    swapalt(arr,n);
    printarr(arr,n);
    return 0;
}