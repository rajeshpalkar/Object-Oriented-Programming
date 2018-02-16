#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

struct node{
    int data;
    node *next;
};

void print(node * head);
void findKth(node * head,int k);


int main() {
 
    node *head;
    node *ptr=nullptr;
    
    head = new node;
    head->data = 5;
    head->next = nullptr;
    
    ptr = head;
    
    ptr->next = new node;
    ptr->data = 2;
    
    ptr = ptr ->next;
    
    ptr->next = new node;
    ptr->data = 4;
    
    ptr = ptr->next;
   
    ptr->next = new node;
    ptr->data = 6;
    
    ptr = ptr->next;
    ptr->next = new node;
    ptr->data = 2;
    
    ptr = ptr->next;
    ptr->next = new node;
    ptr->data = 7;
    
    ptr = ptr->next;
    ptr->next = new node;
    ptr->data = 8;
    
    ptr = ptr->next;
    ptr->next = new node;
    ptr->data = 4;
    
    ptr = ptr->next;
    ptr->next = new node;
    ptr->data = 9;
    
    ptr = ptr->next;
    ptr->next = new node;
    ptr->data = 2;
    
    ptr = ptr->next;
    ptr->next = new node;
    ptr->data = 3;
    
    ptr->next = nullptr;
    
    print(head);
    cout<<"\n 4th element after:: \n";
    findKth(head,4);


    cout<<"\n";
    
}

void findKth(node *head,int k)
{
    node *ptr= head,*qtr;
    
    for(int j=0;j<k;j++)
        ptr = ptr->next;
    
    qtr = ptr;
    
    while(qtr->next!=nullptr)
    {
        cout<<qtr->data<<"->"<<" ";
        qtr = qtr->next;
    }
    
}

void print(node * head)
{
    node *ptr = head;
    while(ptr->next!=nullptr)
    {
        cout<<ptr->data<<"->"<<" ";
        ptr = ptr->next;
    }
    
}

    

