#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int increase(int *p){
    *p=*p+1;
}

int inc(int **p2){
    **p2=**p2+1;
}

int incr(int &o){
    return o++;
}

int main(){
    cout<<"enter now"<<endl;
    int n=5,i=10;
    cout<<"address of n: "<<&n<<endl;
    int *ptr=&i;
    cout<<"address of i: "<<ptr<<endl;
    cout<<"value of i: "<<*ptr<<endl;
    cout<<sizeof(n)<<endl;
    cout<<sizeof(ptr)<<endl;
    *ptr++;
    cout<<"value of i: "<<*ptr<<endl;
    int z=5;
    int *p=&z;
    int **p2=&p;
    cout<<z<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;
    cout<<&z<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;
    int *m;
    cout<<sizeof(m)<<endl;
    //reference variable
    int o=5;
    int& o1= o;
    cout<<"val of o "<<o<<endl;
    cout<<"val of o1 "<<o1<<endl;
    incr(o);
    cout<<"val of increased o "<<o<<endl;
    //dynamic allocation 
    int v;
    cin>>v;
    int *arr = new int[v];
    for(int i=0;i<v;i++){
        cin>>arr[i];
    }
    for(int i=0;i<v;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete []arr;

    //2d arry using pointers 
    int g,h;
    cin>>g;
    cin>>h;
    //creating
    //making a arry of poinerts pointing arry of col
    int **arr2d = new int*[g];
    //making diffrent arry acc to row
    for(int i=0;i<g;i++){
        arr2d[i]=new int[h];
    }
    //taking input
    for(int i=0;i<g;i++){
        for(int j=0;j<h;j++){
            cin>>arr2d[i][j];
        }
    }
    //printing arry
    for(int i=0;i<g;i++){
        for(int j=0;j<h;j++){
            cout<<arr2d[i][j]<<" ";
        }
        cout<<endl;
    }
    //delete
    for(int i=0;i<g;i++){
        delete [] arr2d[i];
    }
    delete[]arr2d;
    return 0;
}