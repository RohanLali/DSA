#include<iostream>
#include<bits/stdc++.h>
#include"oops.h"
using namespace std;

class villan{

    public:
    static int time;
    char name;
    int health;

    //constructor
    villan(){
        cout<<"constructed"<<endl;
    }
    //paramaterised constructor
    villan(int health,char name){
        this->health=health;
        this->name=name;
        cout<<"constructed with parameter"<<endl;
    }
    //copy constructor
    villan(villan &temp){
        char *n=new char;
        *n=temp.name;
        this->health=temp.health;
        this->name=*n;
        cout<<"copy constructed"<<endl;
    }
    //static function can acces only static member
    static int gettime(){
        return time;
    }
    //destructor
    ~villan(){
        cout<<"deleted"<<endl;
    }
    
};

//static data member
int villan::time=5;

int main(){
    cout<<"enter now"<<endl;
    cout<<villan::time<<endl;
    int a=villan::gettime();
    cout<<"a - "<<a<<endl;
    //static
    hero h1;
    //dynamic
    hero *h2 = new hero();
    h1.health=50;
    //access dynamic
    (*h2).health=70;
    h2->name='a';

    //constructor called
    villan v1;
    //paramaterised constructor used
    villan v2(70,'a');
    //copy constructor
    villan v3(v2);
    cout<<v3.health<<endl;
    cout<<v3.name<<endl;
    cout<<v2.name<<endl;
    //shallow copy 
    //deep copy
    v2.name='c';
    cout<<v2.name<<endl;
    cout<<v3.name<<endl;
    //copy assingment
    v1=v3;
    cout<<v1.name<<endl;
    cout<<v1.health<<endl;
    //destroy called auto for static for dynamic:-
    delete h2;

    return 0;
}