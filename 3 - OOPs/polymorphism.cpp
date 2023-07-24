#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//COMPILE TIME POLYMORPHISM
//function overloading 
//same function name but diff arguments
class A{
    public:
    void hello(){
        cout<<"hello"<<endl;
    }
    void hello(int n){
        cout<<n<<"hello"<<endl;
    }
    int hello(int a,int b){
        return a+b;
    }
};

//polymorphism - operator overloading 
class B{
    public:
    int a;
    int b;
    int add(){
        return a+b;
    }

    void operator+ (B &obj){
        int val1 = this->a;
        int val2 = obj.a;
        cout<<val1-val2<<endl;
    }
    void operator() (){
        cout<<"() overloaded - "<<this->a<<endl;
    } 
};

//RUN TIME POLYMORPHISM
//function overriding
//child and parent have their own implementation of a method
class animal{
    public:
    void speak(){
        cout<<"speak"<<endl;
    }
};
class dog: public animal{
    public:
    void speak(){
        cout<<"bark"<<endl;
    }
};

int main(){
    cout<<"enter now"<<endl;
    B obj1,obj2;
    obj1.a=7;
    obj2.a=4;
    obj1+obj2;
    obj1();
    dog bless;
    bless.speak();
    return 0;
}