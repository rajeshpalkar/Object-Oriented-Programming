// Name: Rajesh Palkar
// SUID: 956903134
//  main.cpp
//  CPP04
//
//  Created by Rajesh Palkar on 10/21/17.
//  Copyright © 2017 Rajesh Palkar. All rights reserved.

//HW4: Implement a generic bag using template
//Due: Oct. 23 (Monday) at 11:59pm
//Note that for class linked_list and bag, you need to also include destructor, copy constructor, move constructor, left ref operator=, and right ref operator=

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;



template <class T> class ThreeD {
public:
    T ht;
    T wid;
    T dep;
    ThreeD() { ht = wid = dep = 0; }
    ThreeD(T i) { ht = wid = dep = i; }
    ThreeD(T a, T b, T c) { ht = a; wid = b; dep = c; }
    
    //template <class T> friend    ostream & operator<<(ostream &s, const ThreeD<T> &t);
   template <class R> friend    ostream & operator<<(ostream &s, const ThreeD<T> &t);
};



template <class T> class node {
public:
    T value;
    node<T> * next;
    node<T>() { next = nullptr; }
    node<T>(T v) { value = v; next = nullptr; }
};

template <class T> class linked_list {
public:
    //You need to implement this part.
    node<T> *head;
    
    linked_list(){
        head = nullptr;
    }
    
    linked_list(const linked_list &L1){
        head = nullptr;
        node<T> *temp = L1.head;
        node<T> *last = nullptr;
        
        while(temp!=nullptr)
        {
            node<T> *ptr = new node<T>(temp->value);
            
            if(head == nullptr)
            {
                head = ptr;
                last = ptr;
            }
            else
            {
                last->next = ptr;
                last = ptr;
            }
            
            temp = temp->next;
        }
        
        
    }
    
    //Linked list Destructor
    ~linked_list(){
        node<T> *temp;
        while(head!=nullptr){
            temp = head->next;
            delete head;
            head = temp;
        }
    }
    
    void operator=(linked_list<T> &L1)
    {
        head = nullptr;
        node<T> *temp = L1.head;
        node<T> *last = nullptr;
        
        while(temp!=nullptr)
        {
            node<T> *ptr = new node<T>(temp->value);
            
            if(head == nullptr)
            {
                head = ptr;
                last = ptr;
            }
            else
            {
                last->next = ptr;
                last = ptr;
            }
            
            temp = temp->next;
        }
    }
    
    
    linked_list(linked_list<T> &&L1)
    {
        head = L1.head;
    }
    void operator=(linked_list<T> &&L1)
    {
        head = L1.head;
    }
    
    void push_back(T l);  //insert an item with value v to the back of the bag
    void push_front(T l);
    
    
};

template<class T> void linked_list<T>::push_front(T l)
{
    node<T> *newNode;
    newNode = new node<T>(l);
    
    if(head==nullptr)
    {
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    
    
}
/*
template<class T> void linked_list<T>::push_back(T l)
{
    node<T> *temp,*newNode;
    newNode = new node<T>(l);
    
    if(head==nullptr)
    {
        head = newNode;
    }
    else{
        temp = head;
        while(temp->next!=nullptr) temp = temp->next;
        temp->next = newNode;
    }
    
}
 */


template <class X> class item {
public:
    X value;
    item<X> *next;
    item<X> *previous;
    item<X>(X v) { value = v; next = nullptr; previous = nullptr; }
};

template <class X> class bag {
public:
    item<X> *last;
    item<X> *first;
    int num_items;
    int size() { return num_items; }
    void show_bag();//Print all items in the bag
    bag() { last = nullptr; first = nullptr; num_items = 0; } //default constructor for bag class
    void push_back(X v);  //insert an item with value v to the back of the bag
    void push_front(X v); //insert an item with value v to the front of the bag
    void pop_back(); //delete the last item in the bag
    void pop_front(); //delete the first item in the bag
    X &operator[](int i); //Access bag item with index.
    X front() {  //it returns the value of the first item in the bag.
        //In real applicaitons, we need to check if the bag is empty.  We are skipping this here.
        return first->value;
    }
    X back() { //it returns the value of the last item in the bag
        //In real applicaitons, we need to check if the bag is empty.  We are skipping this here.
        
        return last->value;
    }
    void clear(); //Delete all items in the bag
    
    //Move Constructor
    bag(bag<X> &&B1){
        first = B1.first;
        last = B1.last;
        num_items = B1.num_items;
    }
    
    //Right reference operator =
    void operator=(bag<X> &&B1)
    {
        first = B1.first;
        last = B1.last;
        num_items = B1.num_items;
    }
    
    //bag copy contructor
    bag(const bag<X> &B1){

        item<X> *temp = B1.first;
        
        while(temp!=nullptr)
        {
            item<X> *ptr = new item<X>(temp->value);
            
            if(first == nullptr)
            {
                first = ptr;
                last = ptr;
            }
            else
            {
                last->next = ptr;
                ptr->previous = last;
                last = ptr;
            }
            
            temp = temp->next;
        }
        num_items = B1.num_items;
    }
    
    //left reference operator =
    void operator=(bag<X> &B1)
    {
        item<X> *temp = B1.first;
        
        while(temp!=nullptr)
        {
            item<X> *ptr = new item<X>(temp->value);
            
            if(first == nullptr)
            {
                first = ptr;
                last = ptr;
            }
            else
            {
                last->next = ptr;
                ptr->previous = last;
                last = ptr;
            }
            
            temp = temp->next;
        }
        num_items = B1.num_items;
    }
    
    //Bag Destructor
    ~bag()
    {
        item<X> *temp;
        while(first!=nullptr)
        {
            temp = first;
            first = first -> next;
            delete temp;
        }
        first = nullptr;
        last = nullptr;
        num_items = 0;
    }
    
    
};

template<class X> void bag<X>::push_front(X v) {
    
    item<X> *temp;
    temp = new item<X>(v);
    
    if(first==nullptr)
    {
        first = temp;
        last = first;
        num_items++;
    }
    else
    {
        temp->next = first;
        first->previous = temp;
        first = temp;
        num_items++;
    }
    
}

template<class X> void bag<X>::push_back(X v) {
    
    item<X> *temp;
    temp = new item<X>(v);
    
    if(last==nullptr)
    {
        last = temp;
        first = last;
        num_items++;
    }
    else
    {
        temp->previous = last;
        last->next = temp;
        last = temp;
        num_items++;
    }
    
}

template<class X> void bag<X>::pop_back() {
    
    item<X> *temp,*secondLast;
    
    if(first==last)
    {
        delete last;
        last = nullptr;
        first = nullptr;
        num_items--;
    }
    else
    {
        temp = last;
        secondLast = temp->previous;
        secondLast->next = nullptr;
        last = secondLast;
        delete temp;
        num_items--;
    }
    
}
template<class X> void bag<X>::pop_front() {
    
    item<X> *temp,*second;
    
    if(first==last)
    {
        delete first;
        first = nullptr;
        last = nullptr;
        num_items--;
    }
    else
    {
        temp = first;
        second = temp->next;
        second->previous = nullptr;
        first = second;
        delete temp;
        num_items--;
    }
}

template<class X> void bag<X>::show_bag() {
    // You need to implement this.
    
    item<X> *temp;
    
    temp=first;
    while(temp!=nullptr)
    {
        cout<<temp->value<<" ";
        temp = temp ->next;
    }
}

template<class X> X& bag<X>::operator[](int i) {
    //In real application, we need to check if index i is in the valid range, we are skipping it here.
    //We assume that is is in the valid range
    
    item<X> *temp=first;
    
    int j=0;
    if(i==0) return first->value;
    else{
        while(j<i) {
            temp = temp->next;
            j++;
        }
        return temp->value;
    }
    
}

template<class X> void bag<X>::clear() {
    item<X> *temp,*tempNext;
    temp = first;
    
    while(temp!=nullptr)
    {
        tempNext = temp->next;
        delete temp;
        temp = tempNext;
        num_items--;
    }
    first = last = nullptr;
}





template <class T> ostream & operator<<(ostream &s, const ThreeD<T> &t) {//ostream & operator<<(ostream &s, ThreeD t) will also work.
    s <<"( " << t.ht << ", " << t.wid << ", " << t.dep << " )";
    return s;
}



template <class T> ostream & operator<<(ostream &s, const linked_list<T> &L) {
    
    node<T> *temp;
    temp = L.head;
  //  s <<"( ";
    while(temp!=nullptr){
        s << temp->value<<" ";
        temp = temp -> next;
    }
  //  s << " )";
    return s;
}

int main() {
    bag<double> bag_d;
    bag_d.push_back(5.5);
    bag_d.push_back(6.6);
    bag_d.push_front(4.4);
    bag_d.push_front(3.3);
    bag_d.pop_front();
    bag_d.pop_back();
    bag_d.show_bag();
    cout << endl;
    
    
    bag<int> bag_i;
    bag_i.push_back(5);
    bag_i.push_back(6);
    bag_i.push_front(4);
    bag_i.push_front(3);
    bag_i.pop_front();
    bag_i.pop_back();
    bag_i.show_bag();
   
    ThreeD<int> td3(3), td4(4), td5(5), td6(6), td7(100, 200, 300);
    bag<ThreeD<int>> bag_3D;
    bag_3D.push_back(td5);
    bag_3D.push_back(td6);
    bag_3D.push_front(td4);
    bag_3D.push_front(td3);
    bag_3D.pop_front();
    bag_3D.pop_back();
    bag_3D.show_bag();
    cout << "\nfront = " << bag_3D.front() << "  back = " << bag_3D.back();
    cout << "\n" << bag_3D[0] << " " << bag_3D[1] << "\n";
    bag_3D[1] = td7;
    cout << "\n" << bag_3D[0] << " " << bag_3D[1] << "\n";
    bag_3D.clear();
    bag_3D.show_bag();
    cout << "\nsize = " << bag_3D.size();
    
 
    linked_list<string>ls_1;
    ls_1.push_front("David");
    ls_1.push_front("John");
    ls_1.push_front("Pat");
    ls_1.push_front("Ben");
    ls_1.push_front("Jeff");
    cout << endl;
    cout << ls_1 << endl;
    
    linked_list<string>ls_2;
    ls_2.push_front("Wendy");
    ls_2.push_front("Mary");
    ls_2.push_front("Nancy");
    ls_2.push_front("Jennifer");
    cout << endl;
    cout << ls_2 << endl;
  
    bag<linked_list<string>> bag_string;
    bag_string.push_back(ls_1);
    bag_string.push_back(ls_2);
    bag_string.show_bag();
    cout << endl;
    cout << bag_string[1];
    
    ThreeD<double> t10(3.2, 7.4, 8.9), t11(5.6, 7.7, 2.987), t12(4.6, 7.5, 3.1416), t13(55.6, 66.8, 333.45);
    linked_list<ThreeD<double>> LTD1;
    LTD1.push_front(t10);
    LTD1.push_front(t11);
    linked_list<ThreeD<double>> LTD2;
    LTD2.push_front(t13);
    LTD2.push_front(t12);
    LTD2.push_front(t10);
    LTD2.push_front(t11);
    
    bag<linked_list<ThreeD<double> > > BLTD;
    BLTD.push_back(LTD1);
    BLTD.push_back(LTD2);
    cout << endl;
    BLTD.show_bag();
    
    
    
    getchar();
    getchar();
    
    
    
}
