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
    if(head==NULL){
        cout<< "NULL"<<endl;
    }
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//floyd cycle detection
node* checkcycle(node* &head){
    if(head==NULL){
        return NULL;
    }
    node* slow=head;
    node* fast=head;
    while(slow != NULL && fast != NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            cout<<"loop at: "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

node* loopbegin(node* head){
    if(head==NULL){
        return NULL;
    }
    node* inter=checkcycle(head);
    if(inter==NULL){
        return NULL;
    }
    node* slow =head;
    while(slow!=inter){
        slow=slow->next;
        inter=inter->next;
    }
    return slow;
}

void removeloop(node* head){
    if(head==NULL){
        return;
    }
    node* begin = loopbegin(head);
    if(begin==NULL){
        return;
    }
    node* temp = begin;
    while(temp->next != begin){
        temp=temp->next;
    }
    temp->next = NULL;
}

int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertathead(head,15);
    insertathead(head,20);
    insertattail(tail,5);
    print(head);
    //making cycle
    tail->next=head->next;
    //print(head);
    if(checkcycle(head)!=NULL){
        cout<<"loop in ll"<<endl; 
    }
    else{
        cout<<"no loop"<<endl;
    }
    node* temp=loopbegin(head);
    cout<<"loop begin at: "<<temp->data<<endl;
    removeloop(head);
    print(head);
    return 0;
}