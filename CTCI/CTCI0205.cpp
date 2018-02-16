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
    linked_list add(linked_list l1, linked_list l2);
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

linked_list linked_list::add(linked_list l1, linked_list l2)
{
    node *ptr = l1.head;
    node *qtr = l2.head;
    int num1=0,i=0,num2=0,res = 0;
    
    while(ptr!=nullptr & qtr!= nullptr)
    {
       // cout<<ptr->data<<"->"<<" "<<qtr->data<<"->";
        if(i!=0)
        {
            num1 = num1 + pow(10, i) * ptr->data;
            num2 = num2 + pow(10, i) * qtr->data;
        }
        else
        {
            num1 = num1 + ptr->data;
            num2 = num2 + qtr->data;
        }
            ptr = ptr->next;
            qtr = qtr->next;
            i++;

      //  cout<<"\nNum1 :"<<num1<<"\n";
       // cout<<"\nNum2 :"<<num2<<"\n";
    }
    
    res= num1+ num2;
    
    string s = (to_string(res));
    int len = (int)s.length();
    
    linked_list l4;
    node *p;

   /*while(len!=0)                               //for displaying (res)addition of list in reverse order
    {
      //  cout<<"\nRES "<<res%10;
        p = new node(res%10);
        p -> next = l4.head;
        l4.head = p;
        res = res/10;
        len--;
   
    }*/
    
    while(len!=0)                               //displaying (res)addition of list in forward order
    {
        //cout<<"\nRES "<<res%10;
        if(l4.head==nullptr)
            l4.head = new node(res%10);
        else
        {
            p = l4.head;
            while(p->next!=nullptr)
                p = p->next;
            p->next = new node(res%10);
        }
        res = res/10;
        len--;
        
    }
    
    cout<<"\n";
    return  l4; // l4.print();
    
    
}
    
int main() {
    
    linked_list l1,l2,l3,l4;
   
    l1.make_random(3, 9);
    l2.make_random(3, 4);
    
    l1.print();
    cout<<"\n";
    l2.print();
    cout<<"\n";
    l4 = l3.add(l1,l2);
    cout<<"\nAfter Addition:: \n";
    l4.print();
    cout<<"\n";
    
}
