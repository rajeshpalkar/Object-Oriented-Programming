#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
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
    bool circular(linked_list l1);
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

bool linked_list::circular(linked_list l1)
{
    node *ptr = l1.head,*qtr=l1.head;

  
    while(qtr->data!= 10)
        qtr = qtr -> next;
    

    
    while(ptr->next!=nullptr)
        ptr = ptr -> next;
    
    ptr->next = qtr;             //creating the circular linked list by creating a circular loop
    
    node *r=l1.head, *s=l1.head;
     // l1.print();

     // checking the loop in the linked list by traversing one iterator with one hop
     // another iterator with two hops

    while(1)       
    {
            r = r->next;
        
        if(s->next!=nullptr)
            s = s->next->next;
        else
            return false;
        
        if(r==nullptr || s==nullptr)
            return false;
        
        if(r == s)       // on this condition if both the iterators meet again then there is loop
        {
            return true;
        }
      
    }
    
  

}

int main() {
    
    linked_list l1,l2,l3,l4;
    
    l1.make_random(6, 32);

    l1.print();
    
    bool res = l1.circular(l1);
   
    if(res)
    {
        cout<<"\n There is loop in linked list!!";
        
        map<int,int> mp;
        
        node *p=l1.head;
        
        //storing the element in vector array to check if the number is repeated
        vector<int> vc;
        while(p!=nullptr)
        {
            for (std::vector<int>::iterator it = vc.begin() ; it != vc.end(); it++)
            {
                if(*it==p->data)
                {
                    cout<<"\nLoop point :"<<*it;
                    goto exit;
                }
            }
                    vc.push_back(p->data);

            p = p ->next;
        }
    }
    else
        cout<<"\n There is No loop in linked list!!";
        
exit:
    cout<<"\n";
    
}

