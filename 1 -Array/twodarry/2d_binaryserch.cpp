#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printtwodarr(int a[][100],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool binarysearchmatrix(int a[][100],int m,int n,int x){
    int s=0;
    int e=m*n-1;
    int mid;
    while(s<=e){
        mid=s+e/2;
        //mid/n= row no. mid%n= col no.
        int ele=a[mid/n][mid%n];
        if(ele==x){
            return 1;
        }
        if(ele<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return 0;
}

bool rowcolsortedarrsearch(int a[][100],int m,int n,int x){
    int rowindex = 0;
    int colindex = n-1;
    while(rowindex < m && colindex >= 0){
         int ele=a[rowindex][colindex];
         if(ele == x){
            return 1;
         }
         if(ele < x){
            rowindex++;
         }
         else{
            colindex--;
         }
    }
    return 0;
}

int main(){
    cout<<"enter now"<<endl;
    int m,n;
    cin>>m;
    cin>>n;
    int a[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int x;
    cin>>x;
    cout<<"enter second"<<endl;
    int o,p;
    cin>>o;
    cin>>p;
    int b[100][100];
    for(int i=0;i<o;i++){
        for(int j=0;j<p;j++){
            cin>>b[i][j];
        }
    }
    int y;
    cin>>y;
    // printtwodarr(a,m,n);
    cout<<binarysearchmatrix(a,n,m,x)<<endl;
    cout<<rowcolsortedarrsearch(b,o,p,y)<<endl;
    return 0;
}