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

class stack{
    
public:
    int num_nodes,minValue=100000;
    node * top;
    
    stack(){
        num_nodes = 0;
        top = nullptr;
    }
    
    int peek();      //returns top element of stack
    bool isEmpty();
    void push(int x);
    void pop();
    int min();
};


int stack::min(){
    return minValue;
}

int stack::peek()
{
    if(top==nullptr)
        return false;
    return top->data;
}

bool stack::isEmpty()
{
    if(top==nullptr)
        return true;
    else
        return false;
}

void stack::push(int x)
{
    node *p;
    
    p = new node(x);
    p -> next = top;
    top = p;
    
    if(minValue>x)
        minValue = x;
    
    num_nodes++;
    
}

void stack::pop()
{
    if(top==nullptr)
        cout<<"\n Nothing in stack!!";
    else
    {
        
        node *p;
        p = top;
        top = top->next;
        delete p;
    }
}



int main() {
    
    stack s1;
    int x;
    
    for(int i = 4;i<8;i++)
        s1.push(i*i);
    
    s1.pop();
    cout<<"\n";
    

    s1.push(5);
    s1.push(10);
    s1.push(23);
    cout<<"\n";
  
    /* s1.pop();
    s1.pop();
    cout<<"\n";
    x = s1.peek();
    cout<<"\n"<<x;
    bool res =s1.isEmpty();
    if (res) {
        cout<<"\nEmpty Stack!!";
    }
    else{
        cout<<"\nNot empty stack!";
    }
    
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();*/
    
    for(int i = 4;i<10;i++)     //just for displaying elements of stack
    {
        x = s1.peek();
        cout<<" "<<x;
        s1.pop();
    }
    
    cout<<"\n MIN VAlue: "<<s1.min();
    cout<<"\n";
}



