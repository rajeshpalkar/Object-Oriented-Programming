#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class node{
    
public:
    string data;
    node *next,*prev;
    
    node(){
        next = nullptr;
        prev = nullptr;
    }
    node(string x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};


class Queue{
    
public:
    int num_nodes;
    node *front,*back;
    
    
    Queue(){
        num_nodes = 0;
        front = nullptr;
        back = nullptr;
        
    }
    
    int size();      //returns top element of stack
    bool isEmpty();
    void enque(string s);
    string frontElement();
    string backElement();
    string dequeueAny();
    string dequeueDog();
    string dequeueCat();
    
    void display();
};

int Queue::size(){
    int count= 0;
    
    node *current = front;
    while(current!=back){
        current = current->next;
        count++;
    }
    
    return count;
}

bool Queue::isEmpty(){
    if(front==nullptr & back ==nullptr)
        return true;
    else
        return false;
}
string Queue::backElement(){
    return back->data;
}

string Queue::frontElement(){
    return front->data;
}

void Queue::enque(string s)
{
    node *p;
    if(front==nullptr & back==nullptr)
    {
        p = new node(s);
        front = p;
        back  = p;
        front->prev = nullptr;
        back->next =nullptr;
    }
    else{
        p = new node(s);
        p->next = front;
        p->next->prev = p;
        front = p;
    }

}

string Queue::dequeueAny()
{
    string oldestAnimal;
    if(back==nullptr){
        cout<<"\n Nothing to adopt!";
        return "NULL";
    }
    else{
        oldestAnimal = back->data;
        back = back->prev;
    }
    
    return oldestAnimal;

}

string Queue::dequeueCat(){
    node *p=nullptr;
    string oldestCat = " ";
    
    if(back==nullptr){
        cout<<"\n No Cat to adopt!";
        return "NULL";
    }
    else{
        if(back->data.substr(0,1)=="c")
        {
            oldestCat = back->data;
            back = back->prev;
            goto a;
        }
        else{
            p = back;
            while(p!=front){
                if(p->prev->data.substr(0,1) == "c")
                {
                    oldestCat = p->prev->data;
                    p->prev = p->prev->prev;
                    if(p->prev!=nullptr)
                    p->prev->next = p;
                    else
                    front = p;
            
                    goto a;
                }
                p = p->prev;
            }
            return "\n No Cat to adopt!";
        }
    }
a:
    return oldestCat;
}

string Queue::dequeueDog(){
    node *p=nullptr;
    string oldestDog = " ";
    
    if(back==nullptr){
        cout<<"\n No Dog to adopt!";
        return "NULL";
    }
    else{
        if(back->data.substr(0,1)=="d")
        {
            oldestDog = back->data;
            back = back->prev;
            goto a;
        }
        else{
        p = back;
        while(p!=front){
            if(p->prev->data.substr(0,1) == "d")
            {
                oldestDog = p->prev->data;
                p->prev = p->prev->prev;
                if(p->prev!=nullptr)
                p->prev->next = p;
                else
                front = p;
                goto a;
            }
            p = p->prev;
        }
            return "\n No Dog to adopt!";
        }
    }
a:
    return oldestDog;
}


void Queue::display()
{
    cout<<"\nAnimalss: ";
    node *p=back;
    
        while(p!=nullptr)
        {
            cout<<" "<<p->data;
            p = p->prev;
        }
 
}

int main() {
    
    string s = "c1";
    cout<<"\nstring : "<<s.substr(0,1);
    
    Queue q;
     q.enque("c1");    //oldest
     q.enque("d1");
     q.enque("d2");
     q.enque("c2");
     q.enque("d3");
     q.enque("c3");
     q.enque("d4");
     q.enque("d5");
    
     q.enque("d6");
     q.enque("c4");
     q.enque("d7");
     q.enque("c5");   //newest
    
    q.display();
    
    string any = q.dequeueAny();
    cout<<"\nAny :"<<any;
    string cat = q.dequeueCat();
    cout<<"\noldest cat :"<<cat;
  /*  string cat2 = q.dequeueCat();
    cout<<"\noldest cat :"<<cat2;*/
    q.display();
    string dog = q.dequeueDog();
    cout<<"\ndog :"<<dog;
    string dog2 = q.dequeueDog();
    cout<<"\ndog :"<<dog2;
  /*  string cat = q.dequeueCat();
    cout<<"\noldest cat :"<<cat;*/
    string cat2 = q.dequeueCat();
    cout<<"\noldest cat :"<<cat2;
    q.display();
    string cat3 = q.dequeueCat();
    cout<<"\noldest cat :"<<cat3;
    string cat4 = q.dequeueCat();
    cout<<"\noldest cat :"<<cat4;
    string cat5 = q.dequeueCat();
    cout<<"\noldest cat :"<<cat5;
    q.display();
    
     string dog6 = q.dequeueDog();
     string dog7 = q.dequeueDog();
     string dog8 = q.dequeueDog();
     string dog9 = q.dequeueDog();
       string dog10 = q.dequeueDog();
    string dog11 = q.dequeueDog();


    
    cout<<"\n";
}

