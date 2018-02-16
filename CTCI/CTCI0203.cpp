
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

struct node{
    int data;
    node *next;
};

void print(node * head);
void deleteMiddle(node * head);


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
    cout<<"\n After Deleting middle element:: \n";
    deleteMiddle(head);
    print(head);

    cout<<"\n";
    
}

void deleteMiddle(node *head)
{
    node *ptr= head,*q =head;
    int i=1,count=0, newCount=0;
    
    while(ptr->next!=nullptr)         //counting total number of elements
    {
        count++;
        ptr = ptr->next;
    }
    
        newCount = count/2;

    while(i<newCount){                //iterating again till middle element
        q = q->next;
        i++;
    }
    
    q->next = q->next->next;
    
}

void print(node * head)
{
    node *ptr = head;
    do
    {
        cout<<ptr->data<<"->"<<" ";
        ptr = ptr->next;
    }while(ptr!=nullptr);
    
}

    

