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

node* reverseknodes(node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    node* next=NULL;
    node* curr=head;
    node* prev=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next=reverseknodes(next,k);
    }
    return prev;
}



int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertathead(head,15);
    insertathead(head,20);
    insertattail(tail,5);
    insertatposition(head,tail,0,25);
    insertatposition(head,tail,4,0);
    print(head);
    head=reverseknodes(head,3);
    print(head);
    return 0;
}