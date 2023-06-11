#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int firstOccr(int arr[],int n,int x)
   {
       int s=0;
       int e=n-1;
      int mid=s+(e-s)/2;
          int store2=-1;
         while(s<=e)
          {
            if(arr[mid]==x)
              {
                   store2=mid;
                      e=mid-1;
              }
              else if( x > arr[mid]) //right me jao
              {
                
                 s=mid+1;
              }
              else
              {
                   e=mid-1;
                  
              }
             mid=s+(e-s)/2;
          }
          return store2;
   }
   
   int lastOccr(int arr[],int n,int x)
   {
       int s=0;
       int e=n-1;
       
         int mid=s+(e-s)/2;
          int store1=-1;
         while(s<=e)
          {
              if(arr[mid]==x)
              {
                   store1=mid;
                   s=mid+1;;
              }
              else if(x > arr[mid]  )
              {
                 
                 s=mid+1;
              }
              else
              {
                  e=mid-1; 
              }
             mid=s+(e-s)/2;
          }
          return store1;
   }

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<firstOccr(arr,n,x)<<endl;
    cout<<lastOccr(arr,n,x)<<endl;
}