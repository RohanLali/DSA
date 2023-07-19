#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[], int s, int e)
{
    int mid=(s+e)/2;
    int n1 = mid - s + 1;
    int n2 = e - mid;
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[s + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
	int i=0,j=0,k=s;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergesort(int arr[], int s,int e){
    int mid = (s+e) / 2;
    if ( s >= e ) {
        return;
    }
    mergesort(arr,s, mid);
    mergesort(arr , mid+1,e);
    merge(arr, s, e);
    
}

int partition(int arr[],int s,int e){
    int pivot = arr[s];
    int c=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            c++;
        }
    }
    int pivoti=s+c;
    swap(arr[pivoti],arr[s]);
    int i=s,j=e;
    while(i<pivoti && j>pivoti){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivoti && j>pivoti){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivoti;
}

void quicksort(int arr[],int s,int e){
    if(s>=e){
        return;
        }
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main(){
    cout<<"enter now"<<endl;
    int arr[6]={3,4,5,2,7,8};
    int n=6;
    int arr2[6]={9,5,3,6,1,7};
    print(arr,n);
    mergesort(arr,0,n-1);
    print(arr,n);
    cout<<endl;
    print(arr2,n);
    quicksort(arr2,0,n-1);
    print(arr2,n);
    return 0;
}