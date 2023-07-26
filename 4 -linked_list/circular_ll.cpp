#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertnode(node* &tail,int ele,int data){
    if(tail==NULL){
        node* newnode=new node(data);
        tail=newnode;
        newnode->next=newnode;
        return;
    }
    else{
        node* curr=tail;
        while(curr->data != ele){
            curr=curr->next;
        }
        node* temp=new node(data);
        temp->next=curr->next;
        curr->next=temp; 
    }
}

void print(node* &tail){
    node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail != temp);
    cout<<endl;
}

void deletenode(node* &tail,int d){
    if(tail==NULL){
        return;
    }
    else{
        node* prev=tail;
        node* curr=prev->next;
        while(curr->data!=d){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(curr==prev){
            tail=NULL;
        }
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

bool checkcircular(node* &tail){
    if(tail==NULL){
        return false;
    }
    node* temp=tail->next;
    while(temp!=NULL && temp!=tail){
        temp=temp->next;
    }
    if(temp==tail){
        return true;
    }
    return false;
}

int main(){
    node* tail=NULL;
    insertnode(tail,5,3);
    print(tail);
    insertnode(tail,3,5);
    print(tail);
    insertnode(tail,5,7);
    print(tail);
    insertnode(tail,7,9);
    print(tail);
    insertnode(tail,3,4);
    print(tail);
    // deletenode(tail,3);
    // print(tail);
    if(checkcircular(tail)){
        cout<<"circular"<<endl;
    }
    else{
        cout<<"not circular"<<endl;
    }
    return 0;
}