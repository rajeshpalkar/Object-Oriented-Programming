#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>




class MyQueue{
    
public:
    int num_nodes;
    stack<int> s1;
    stack<int> s2;

    
    MyQueue(){
        num_nodes = 0;
    
    }
    
    int size();      //returns top element of stack
    bool isEmpty();
    void enque(int x);
    int front();
    int back();
    int dequeue();
};

int MyQueue::size(){
   return s1.size();
}

bool MyQueue::isEmpty(){
    if(s1.empty())
        return true;
    else
        return false;
}
int MyQueue::back(){
    return s1.top();
}

int MyQueue::front(){
    while(!s1.empty())
    {
        int x = s1.top();
        s2.push(x);
        s1.pop();
    }
    
    int dq = s2.top();
    
    while(!s2.empty())
    {
        int x = s2.top();
        s1.push(x);
        s2.pop();
    }
    
    return dq;
}

void MyQueue::enque(int x)
{
    s1.push(x);
}

int MyQueue::dequeue()
{
    while(!s1.empty())
    {
        int x = s1.top();
        s2.push(x);
        s1.pop();
    }
    
    int dq = s2.top();
    s2.pop();
    
    while(!s2.empty())
    {
        int x = s2.top();
        s1.push(x);
        s2.pop();
    }
    
    return dq;
}





int main() {

    std::queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    q.pop();
    cout<<"\nFront: "<<q.front();
     cout<<"\nBack: "<<q.back();
    q.push(12);
    cout<<"\nFront: "<<q.front();
     cout<<"\nBack: "<<q.back();
    cout<<"\n";
    
    for(int i=0;i<6;i++)
    {
       cout<<" "<<q.front();
        q.pop();
    }
    
    cout<<"\nMyQueue:\n";
    
    MyQueue m1;
    m1.enque(1);
    m1.enque(2);
    m1.enque(3);
    m1.enque(4);
    m1.enque(5);
    m1.enque(6);
    
    m1.dequeue();
    cout<<"\nFront: "<<m1.front();
    cout<<"\nBack: "<<m1.back();
    m1.enque(12);
    cout<<"\nFront: "<<m1.front();
    cout<<"\nBack: "<<m1.back();
    cout<<"\n";
    
    for(int i=0;i<6;i++)
    {
        cout<<" "<<m1.front();
        m1.dequeue();
    }
    
    cout<<"\n";

}

