#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n)
    {
       // Your code here
          int s=0;
        int e = n-1;
        while(s<e){
            int mid = s + (e-s)/2;
            if(arr[mid]<arr[mid+1]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }    

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void rightRotateByOne(int arr[], int n)
{
    int last = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
 
    arr[0] = last;
}

void rotatearr(int arr[],int  n,int k){
    if (k < 0 || k >= n) {
        return;
    }
 
    for (int i = 0; i < k; i++) {
        rightRotateByOne(arr, n);
    }
}

int main(){
    cout<<"enter now"<<endl;
    int n,k;
    cin>>n;
    cin>>k;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printarr(arr,n);
    rotatearr(arr,n,k);
    printarr(arr,n);
    cout<<peakElement(arr,n)<<endl;
}