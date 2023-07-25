#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void inserthead(node* &head,node* &tail,int data){
    if(head == NULL) {
        node* temp = new node(data);
        head = temp;
        tail = temp;
    }
    else{
        node* temp = new node(data);
        temp->next=head;
        head->prev=temp;
        head=temp; 
        }
}

void inserttail(node* &head,node* &tail,int data){
     if(tail == NULL) {
        node* temp = new node(data);
        tail = temp;
        head = temp;
    }
    else{
        node* temp=new node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        }
}

void insertnode(node* &head,node* &tail,int pos,int data){
    if(pos==0){
        inserthead(head,tail,data);
        return;
    }
    node* temp=head;
    int c=0;
    while(c<pos){
        temp=temp->next;
        c++;
    }
    if(temp->next==NULL){
        inserttail(head,tail,data);
        return;
    }
    node* newnode=new node(data);
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}

int length(node* &head){
    int c=0;
    node*temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

void deletenode(int pos, node* &head) { 
    if(pos == 0) {
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        node* curr = head;
        node* prev = NULL;
        int c = 0;
        while(c < pos) {
            prev = curr;
            curr = curr -> next;
            c++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    node* n1=new node(10);
    node* head = n1;
    node* tail = n1; 
    print(head);
    inserthead(head,tail,15);
    inserthead(head,tail,20);
    inserttail(head,tail,5);
    print(head);
    cout<<length(head)<<endl;
    insertnode(head,tail,2,12);
    print(head);
    deletenode(2,head);
    print(head);
    return 0;
}