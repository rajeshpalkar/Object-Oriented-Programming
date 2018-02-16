#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;

class node{
    
public:
    int data,index;
    node *next;
    
    node(){
        next = nullptr;
    }
    node(int x)
    {
        data = x;
    }
};

class linked_list{
    
public:
    int num_nodes;
    node * head;
    
    linked_list(){
        num_nodes = 0;
        head = nullptr;
    }
    
    void print();
    void make_random(int n, int k);
    void intersection(linked_list l1, linked_list l2);
};


void linked_list::print()
{
    node *ptr = head;
    
    while(ptr!=nullptr)
    {
        cout<<ptr->data<<"->"<<" ";
        ptr = ptr->next;
    }
    
}

void linked_list::make_random(int n,int k)
{
    node *p;
    
    for(int i=0; i<n; i++)
    {
        p = new node(rand() % k);
        p -> next = head;
        head = p;
        num_nodes++;
    }
}

void linked_list::intersection(linked_list l1, linked_list l2)
{
    int intersection;
    node *ptr = l1.head,*qtr=l2.head;
    
    while(ptr!=nullptr & qtr!=nullptr)
        {
            if(ptr == qtr)
                goto a;
            
            qtr  = qtr->next;
            ptr = ptr ->next;
        }
    if(ptr==nullptr & qtr ==nullptr)
    cout<<"\nNo intersection point!";
    
a:
    cout<<"\nIntersection Point: "<<ptr->data<<" "<<qtr<<" "<<ptr;
}

int main() {
    
    linked_list l1,l2,l3,l4;
    
    l1.make_random(8, 12);
    l2.make_random(4, 34);
    l3.make_random(4, 55);
    l1.print();
    cout<<"\n";
    l2.print();
    cout<<"\n";
    l3.print();
    

    //creating third linked list to join first two linked lists to form Y shape
    node *p = l1.head;
    while(p->next!=nullptr)
    p = p->next;

    p->next = l3.head;
    cout<<"\nAfter concat l1: ";
    l1.print();
    
    node *q = l2.head;
    while(q->next!=nullptr)
    q = q->next;
    
    q->next = l3.head;
    cout<<"\nAfter concat l2: ";
    l2.print();
    
    l4.intersection(l1, l2);
   

   
    cout<<"\n";
    
}

