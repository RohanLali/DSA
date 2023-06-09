#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(arr[j] > temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[minindex],arr[i]);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"given arr: ";
    printarr(arr,n);
    // selectionsort(arr,n);
    // bubblesort(arr,n);
    insertionsort(arr,n);
    cout<<"sorted arr: ";
    printarr(arr,n);
    return 0;
}