#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;

class node{

public:
    int data;
    node *next,*prev;
    
    node(){
        next = nullptr;
        prev = nullptr;
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
    bool palindrome();
};


void linked_list::print()
{
    node *ptr = head;
    
    while(ptr!=nullptr)
    {
        cout<<" "<<"<-"<<ptr->data<<"->"<<" ";
        ptr = ptr->next;
    }
    
}

void linked_list::make_random(int n,int k)    //make a doubly linked list
{
    node *p;
    
    for(int i=0; i<n; i++)
    {
       
        if(head == nullptr)
        {
            head = new node(rand() % k);
            head->prev = nullptr;
            head->next = nullptr;
        }
        else
        {
            p = head;
            while(p->next!=nullptr)
                p =  p -> next;
            
            p->next= new node(rand() % k);
            p->next->next = nullptr;
            p->next->prev = p;
            
            num_nodes++;
        }
    }
}

bool linked_list::palindrome()
{
    node *ptr=head,*qtr=head;
    int flag =0;
    
    while(qtr->next!=nullptr)
        qtr=qtr->next;
    
    while(ptr!=nullptr & qtr!=nullptr)
    {
        if(ptr->data == qtr->data)       //checked for equal values traversing ptr forward and qtr back
        {
            ptr = ptr -> next;
            qtr = qtr -> prev;
            flag =1;
        }
        else{
            flag=0;
            return false;
        }
    }
    
    if(ptr==nullptr & qtr ==nullptr & flag ==1)
        return true;
    else
        return false;

}

    
int main() {
    
    linked_list l1,l2,l3;
   
    l1.make_random(5, 2);
    
        l1.print();
    bool res1 = l1.palindrome();
    if(res1)
        cout<<"\n String is Palindrome!";
    else
        cout<<"\n String is NOT Palindrome!";
    node *ptr = l1.head;
    ptr->data=ptr->next->data =0;
    cout<<"\n";
   /* while(ptr->next->next!=nullptr)
        ptr=ptr->next;
    
    cout<<"\n";
    ptr->next->data = 3;*/
    
    l1.print();
    cout<<"\n";

    
    bool res2 = l1.palindrome();
    if(res2)
        cout<<"\n String is Palindrome!";
    else
        cout<<"\n String is NOT Palindrome!";
    
    cout<<"\n";
    
}
