
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

struct node{
    int data;
    node *next;
};

void print(node * head);
void duplicateDelete(node * head);
void sort(node *head);

// first sorted the linked list then checked current element with next to delete duplicates
int main() {
 //adding values in linked list
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
    sort(head);
    cout<<"\nSorted:\n";
    print(head);
    duplicateDelete(head);
    cout<<"\nDelted Duplicates:\n";
    print(head);

    cout<<"\n";
    
}

void sort(node *head)
{
    int flag=0;
    node *ptr;
    
    int num;
    
    if(head==nullptr)
        cout<<"\nNothing to sort!\n";
    
    do{
        ptr=head;
        flag=1;
        while(ptr->next!=nullptr)
        {
            if(ptr->data > ptr->next->data)
            {
                num  = ptr->next->data;
                ptr->next->data = ptr->data;
                ptr->data=num;
                
                flag=0;
            }
            ptr=ptr->next;
        }
    }while(flag==0);
    
}

void duplicateDelete(node *head)
{
    node *ptr= head;
    
    while(ptr->next!=nullptr)
    {
        while(ptr->data==ptr->next->data)
            ptr->next=ptr->next->next;
        
        ptr = ptr->next;
        
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

    

