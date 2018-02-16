#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;

class node{
    
public:
    int data;
    node *next;
    
    node(){
        next = nullptr;
    }
    node(int x)
    {
        data = x;
        next = nullptr;
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
    void partition(linked_list l1,int p);
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

void linked_list::partition(linked_list l1, int p)
{
    node *ptr = l1.head,*qtr;
    linked_list l2;
    
    while(ptr!= nullptr)
    {
        if(ptr->data >= p)
        {
            qtr = l2.head;
            if(l2.head==nullptr)
                l2.head = new node(ptr->data);
            else
            {
                while(qtr->next!=nullptr)
                    qtr = qtr->next;
                
                qtr->next = new node(ptr->data);
            }
        }
        else
        {
            if(l2.head==nullptr)
                l2.head = new node(ptr->data);
            else
            {
                qtr  = new node(ptr->data);
                qtr->next = l2.head;
                l2.head = qtr;
            }
        }
      //  cout<<"\nLS :";
       // l2.print();
        ptr = ptr->next;
    }
    cout<<"\n After Partition: ";
    l2.print();
}

int main() {
    
    linked_list l1,l2,l3,l4;
    
    l1.make_random(12, 12);

    l1.print();
    
    l1.partition(l1, 5);
   
    cout<<"\n";
    
}

