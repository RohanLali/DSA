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

void print(node* &head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reversell(node* &head){
    if(head==NULL || head->next==NULL){
        return;
    }
    node* prev=NULL;
    node* curr=head;
    node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
}

node* recreversell(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* smallhead=recreversell(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallhead;
}

int length(node* head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}

void findmid(node* &head){
    int len=length(head);
    int ans=(len/2);
    node* temp=head;
    int c=0;
    while(c<ans){
        temp=temp->next;
        c++;
    }
    cout<<"mid element: "<<temp->data<<endl;
}

int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertathead(head,15);
    insertathead(head,20);
    insertattail(tail,5);
    insertatposition(head,tail,0,25);
    print(head);
    reversell(head);
    print(head);
    head=recreversell(head);
    print(head);
    findmid(head);
    return 0;
}