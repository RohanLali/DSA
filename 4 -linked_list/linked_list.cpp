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

void insertathead(node* &head,int data){
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}

void insertattail(node* &tail,int data){
    node* temp=new node(data);
    tail->next=temp;
    tail=temp;
}

void printdata(node* &head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" "<<temp->next<<" "<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

void insertatposition(node* &head,node* &tail,int pos,int data){
    if(pos==0){
        insertathead(head,data);
        return;
    }
    node* temp = head;
    int c=0;
    while(c<pos){
        temp=temp->next;
        c++;
    } 
    if(temp->next==NULL ){
        insertattail(tail,data);
        return;
    }
    node* newnode = new node(data);
    newnode->next=temp->next;
    temp->next=newnode;
} 

void deletenode(node* &head,node* &tail,int pos){
    if(pos == 0){
        node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        node* prev=NULL;
        node* curr=head;
        int c=0;
        while(c<pos){
            prev=curr;
            curr=curr->next;
            c++;
        }
        if(curr->next==NULL){
            tail=prev;
            prev->next=NULL;
            delete curr;
            return;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(node* &head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    cout<<"enter now"<<endl;
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    print(head);
    insertathead(head,15);
    insertathead(head,20);
    print(head);
    insertattail(tail,5);
    print(head);
    insertatposition(head,tail,2,7);
    print(head);
    print(tail);
    insertatposition(head,tail,4,0);
    insertatposition(head,tail,0,25);
    print(head);
    deletenode(head,tail,0);
    print(head);
    print(tail);
    return 0;
}