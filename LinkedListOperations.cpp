//HW1: Rajesh Palkar
//SUID: 956903134
//Implement the three member functions of linked_list class: sort, remove_all, and insert
//as described in the code blow
//Due: 11:59pm, Friday, September 8
//Submit a text vesion of your program to blackboard

//Linked List Examples by C-Y (Roger) Chen, Syracuse University

#include <iostream>
using namespace std;

class node {
public:
    int value;
    node * next;
    node() { next = nullptr; }
    node(int k) { value = k; next = nullptr; }
};

class linked_list {
public:
    int num_nodes;
    node * head;
    linked_list() { num_nodes = 0; head = nullptr; }
    void new_make_random_list(int k, int m);
    void make_random_list(int k);//create a linked list of
    //k nodes with values in 0 ..99 randomly
    void print(); //Print values of all nodes from head node
    
    void reverse(); //Reverse the order of nodes of linked list
    //*********************
    //Implement the following three member functions.
    
    void sort(); //Sort the nodes, based on ascending order of node values
    
    void insert(int k); //Create a new node with values k, and properly add it to an already sorted list
    //After the insertion, the entire linked list is still sorted.
    
    void remove_all(int k); //Remove all nodes whose node values are equal to k
    
};

/*
void linked_list::make_random_list(int k) {
    node * p;
    for (int i = 0; i < k; i++) {
        p = new node(rand() % 100);
        p->next = head;
        head = p;
        num_nodes++;
    }
}*/

void linked_list::new_make_random_list(int k, int m) {
    node * p;
    for (int i = 0; i < k; i++) {
        p = new node(rand() % m);
        p->next = head;
        head = p;
        num_nodes++;
    }
    
}

void linked_list::print() {
    node * p = head;
    cout << endl;
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->next;
    }
}

 void linked_list::reverse() {
 if (num_nodes <= 1) return;
 node * p1 = head, *p2 = head->next, *p3;
 while (p2 != nullptr) {
 p3 = p2->next;
 p2->next = p1;
 if (p1 == head) p1->next = nullptr;
 p1 = p2;
 p2 = p3;
 }
 head = p1;
 }
 
 
 void linked_list::remove_all(int k)
 {
 node *p,*q;
 p = head;
 q = head;
    
     if(head==nullptr) return;
 
     while( q!=nullptr && q->value==k){
         head=head->next;
         p=head;
         delete q;
          q= head;
     }
 
     while( p!=nullptr && p ->next!=nullptr)
     {
         if(p->next->value==k)
         {
             q= p->next;
             p->next = p->next->next;
             delete q;
         }else{
             p =p->next;}
     }
 }
 
 void linked_list::sort()
 {
 node *p,*q;
 int temp,flag=0;
 
 if(head==nullptr) return;
 
 do
 {
 p= head;
 flag = 1;
 while(p->next!=nullptr)
 {
 if(p->value > p->next->value)
 {
 temp = p->value;
 p->value = p->next->value;
 p->next->value = temp;
 flag=0;
 }
 p=p->next;
 }
 }while(flag==0);
 }

void linked_list::insert(int k)
{
    node *p;
    node *newNode = new node(k);
    if(head==nullptr){
        head = newNode;
        return;
    }
    
    if(head->value > k)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        
        p = head;
        while(p->next!=nullptr && p->next->value < k)
            p=p->next;
        
        if(p->next!=nullptr)
            newNode->next = p->next;
        
        p->next = newNode;
    }
    
}




int main() {
    
    //Some examples of tests for your program are given below
    //During grading, other test cases will also be used
    linked_list L1;
    cout<<"\nOriginally Created List 1:";
    L1.new_make_random_list(50, 7);
    L1.print();
     cout<<"\nAfter Deleting 1:";
    L1.remove_all(1);
    L1.print();
    cout<<"\nAfter Deleting 6:";
    L1.remove_all(6);
    L1.print();
    
    linked_list L2;
    cout<<"\n\nOriginally Created List 2:";
    L2.new_make_random_list(60, 20);
    L2.print();
    cout<<"\nAfter Sorting:";
    L2.sort();
    L2.print();
    
    cout<<"\nAfter Inserting -1:";
    L2.insert(-1);
    L2.print();
    cout<<"\nAfter Inserting 20:";
    L2.insert(20);
    L2.print();
    cout<<"\nAfter Inserting 15:";
    L2.insert(15);
    L2.print();
    cout<<"\nAfter Inserting 10:";
    L2.insert(10);
    L2.print();
    cout<<"\nRemoving 20:";
    L2.remove_all(-1);
    L2.print();
    
    linked_list L3;
    L3.insert(-1);
    L3.insert(-1);
    L3.insert(-1);
    L3.insert(2);
    L3.print();
    
    cout<<"\nRemoving -1:";
    L3.remove_all(-1);
    L3.print();
    
    getchar();
    getchar();
    return 0;
}


//int main() {
//    /*
//     node * head = nullptr, *p;
//     int num_nodes=0;
//     int k = 5;
//     for (int i = 0; i < k; i++) {
//     p = new node(i);
//     //(*p).next = head;
//     p->next = head;
//     head = p;
//     num_nodes++;
//     }
//     p = head;
//     cout << endl;
//     while (p != nullptr) {
//     cout << (*p).value << " ";
//     //p = (*p).next;
//     p = p->next;
//     }
//     
//     */
//    //Some examples of tests for your program are given below
//    //During grading, other test cases will also be used
//    linked_list L1;
//    cout<<"\nOriginally Created List :";
//    L1.make_random_list(25);
//    L1.print();
//    cout<<"\nReverse:";
//    L1.reverse();
//    L1.print();
//    cout<<"\nAfter Deleting 9:";
//    L1.remove_all(9);
//    L1.print();
//    cout<<"\nAfter Sorting:";
//    L1.sort();
//    L1.print();
//    cout<<"\nAfter Inserting 39:";
//    L1.insert(39);
//    L1.print();
//    getchar();
//    getchar();
//    return 0;
//    
//}
