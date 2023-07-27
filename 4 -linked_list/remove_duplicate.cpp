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

void split(node* source,node* &a,node* &b){
    node* slow=source;
    node* fast=source->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    a=source;
    b=slow->next;
    slow->next=NULL;
}

node* mergell(node* &a,node* &b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    node* res = NULL;
    if(a->data <= b->data){
        res=a;
        res->next=mergell(a->next,b);
    }
    else{
        res=b;
        res->next=mergell(a,b->next);
    }
    return res;
}

void mergesortll(node* &head){
    node* temp=head;
    node* a;
    node* b;
    if(temp == NULL || temp->next==NULL){
        return;
    }
    split(temp,a,b);
    mergesortll(a);
    mergesortll(b);
    head=mergell(a,b);
}

node* removeduplicate(node* &head){
    if(head==NULL){
        return NULL;
    }
    node* curr=head;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data){
            node* n=curr->next->next;
            node* todel = curr->next;
            delete(todel);
            curr->next=n;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    node* node1 = new node(7);
    node* head = node1;
    node* tail = node1;
    insertattail(tail,3);
    insertattail(tail,8);
    insertattail(tail,2);
    insertattail(tail,7);
    print(head);
    mergesortll(head);
    print(head);
    removeduplicate(head);
    print(head);
    return 0;
}