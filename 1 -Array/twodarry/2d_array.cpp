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

bool find(int a[][100],int n,int m,int x){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==x){
                return 1;
            }
        }
    }
    return 0;
}

void printrowsum(int a[][100],int m,int n){
    cout<<"row wise sum : ";
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=a[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

void printinwave(int a[][100],int m,int n){
    cout<<"wave print :"<<endl;
    for(int i=0;i<n;i++){
        if(i&1){
            for(int j=m-1;j>=0;j--){
                cout<<a[j][i]<<' ';
            }
        }
        else{
            for(int j=0;j<m;j++){
                cout<<a[j][i]<<' ';
            }
        }
    }
    cout<<endl;
}

void rotatearr(int a[][100],int m,int n){
    for(int i=0;i<m;i++){  
        for(int j=i;j<n;j++){  
            int temp = a[i][j];  
            a[i][j] = a[j][i];  
            a[j][i] = temp;  
        }  
    }  
    for(int i=0;i<n;i++){  
        int low = 0, high = n-1;  
        while(low < high){  
            int temp = a[i][low];  
            a[i][low] = a[i][high];  
            a[i][high] = temp;  
            low++;  
            high--;  
        }  
    }  
}

int main(){
    cout<<"enter now"<<endl;
    int m,n;
    cin>>m;
    cin>>n;
    //a[row][col]
    int a[100][100];
    //input rowise (for col i=n,j=m,cin>>a[j][i])
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    //output
    printtwodarr(a,m,n);
    int x;
    cin>>x;
    cout<<find(a,m,n,x)<<endl;
    printrowsum(a,m,n);
    printinwave(a,m,n);
    printtwodarr(a,m,n);
    rotatearr(a,m,n);
    printtwodarr(a,m,n);
    return 0;
}