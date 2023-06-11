#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

void sum(int arr1[],int n,int arr2[],int m){
    int i=n-1;
    int j=m-1;
    int carry=0;
    int k=0;
    int ans[1000];
    while(i>=0 && j>=0){
        int val1 = arr1[i];
        int val2 = arr2[j];
        int sum = val1 + val2 + carry;
        carry = sum/10;
        sum = sum%10;
        ans[k]=sum;
        k++;
        i--;
        j--;
    }
    while(i>=0){
        int sum = arr1[i]+carry;
        carry = sum/10;
        sum = sum%10;
        ans[k]=sum;
        k++;
        i--;
    }
    while(j>=0){
        int sum = arr2[j]+carry;
        carry = sum/10;
        sum = sum%10;
        ans[k]=sum;
        k++;
        j--;
    }
    while (carry != 0){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans[k]=sum;
        k++;
    }
    reversearr(ans,k);
    printarr(ans,k);
}

int main(){
    cout<<"enter now"<<endl;
    int n,m;
    cin>>n;
    cin>>m;
    int arr1[1000];
    int arr2[1000];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    sum(arr1,n,arr2,m);
    return 0;
}