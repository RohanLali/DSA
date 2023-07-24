#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class human{
    public:
    int age;
    int weight;

    int getage(){
        return this->age;
    }
    void setage(int age){
        this->age=age;
    }  

};

class male: public human{
    public:
    int height;
    void setheight(int height){
        this->height = height;
    }
    int getheight(){
        return this->height;
    }
};


//multiple inheritance
class pet: public male,public human{
    public:
    string type;
};


int main(){
    cout<<"enter now"<<endl;
    male m1;
    m1.age=10;
    m1.weight-30;
    m1.height=12;
    cout<<m1.getage()<<endl;
    cout<<m1.getheight()<<endl;
    m1.setage(15);
    cout<<m1.getage()<<endl;
    return 0;
}


// inheritance table
// base_class      inheritance
//     -           public     protected   private
//   public        public     protected   private
//   protected     protected  protected   private    
//   private       NA         NA          NA
