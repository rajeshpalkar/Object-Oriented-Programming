//Name: Rajesh Palkar
//SUID: 956903134
//HW2: Sparse Vector Operations Using Linked List structures
//Due: 11:59PM, Friday, September 22

//Implement the following member functions for class my_vector:
//add_node
//operator+
//operator*



#include <iostream>
#include <fstream>
using namespace std;

ofstream out("data1.txt");
class node {
    public:
    int value;
    int position;
    node * next;
    node() { value = -9999; position = -1; next = nullptr; }
    node(int i, int j) { value = i; position = j; next = nullptr; }
};

class my_vector {
    public:
    int size;
    int num_nodes; //number of non-zero elements
    node * head;
    my_vector() { size = num_nodes = 0; head = nullptr; }
    
    void add_node(int v, int p); //add a new node with value v and position p;
    //if a node at position p already exists, update its value to v
    
    void make_random_vector(int s, int n, int k);
    //set the value of size  to s;
    //randomly create n nodes in -(k-1) to k-1
    
    my_vector operator+(my_vector V); //vector addition
    
    int operator*(my_vector V);//inner product
    
    void print();
};

void my_vector::make_random_vector(int s, int n, int k) {
    size = s;
    for (int i = 0; i < n; i++) {
        int p = rand() % s;
        int v = rand() % (2 * k - 1) - (k - 1);
        add_node(v, p);
    }
}

void my_vector::print() {
    out << endl;
    node * p = head;
    while (p != nullptr) {
        out << p->value << " " << p->position << "  ";
        p = p->next;
    }
}

void my_vector::add_node(int v, int p) {
    
    node *ptr,*qtr;
    
    if(head==nullptr && v!=0){
        head = new node(v,p);
        num_nodes++;
    }
    else{
        qtr = head;
        ptr = new node(v,p);
        if(ptr->position == head->position)
        {
            if(v!=0){
                head->value = ptr->value;
            }
            else{
                head = head->next;
                delete qtr;
            }
        }
        else if(ptr->position<head->position && v!=0)
        {
            ptr->next = head;
            head= ptr;
            num_nodes++;
        }
        else
        {
            while(qtr->next!=nullptr && qtr->next->position  < ptr->position)
            {
                qtr=qtr->next;
            }
            
            if(qtr->next!=nullptr)
            {
                if(qtr->next->position==ptr->position)
                {
                    if(v!=0)
                    {
                        qtr->next->value=ptr->value;
                    }
                    else{
                        node *rtr = qtr->next;
                        qtr->next = qtr->next->next;
                        delete rtr;
                    }
                    
                }
                else if(v!=0)
                {
                    ptr->next = qtr->next;
                    qtr->next = ptr;
                    num_nodes++;
                }
            }
            else
            {
                qtr->next = ptr;
                num_nodes++;
            }
            
        }
    }
}


int my_vector::operator*(my_vector V)
{
    int result=0;
    
    int val;
    node * list1head, * list2head;
    
    list1head = this->head;
    list2head = V.head;
    
    if(this->size != V.size) {
        return -99999;
    }
    
    
    while (list2head!=nullptr && list1head!=nullptr)
    {
        
        if(list1head->position==list2head->position)
        {
            val =  list1head -> value * list2head -> value; //check zero
            result = result + val;
            list1head= list1head->next;
            list2head= list2head->next;
        }
        else if(list1head->position < list2head->position)
        {
            list1head= list1head->next;
        }
        else
        {
            list2head= list2head->next;
        }
        
        
    }
    
    
    return result;
}

my_vector my_vector::operator+(my_vector V) {
    
    my_vector temp;
    int val,pos;
    node * list1head, * list2head, *list3ptr,*q;
    
    
    if (this->size != V.size) {
        temp.head = new node(-99999,-9);
        head->next = new node(-99999, -9);
        return temp;
    }
    
    list1head = this->head;
    list2head = V.head;
    list3ptr = temp.head;
    
    while (list2head!=nullptr && list1head!=nullptr) {
        
        if(temp.head == nullptr)
        {
            if(list1head->position==list2head->position)
            {
                val = list1head -> value + list2head -> value; //check zero
                pos = list1head -> position;
                if(val!=0)
                temp.head = new node(val,pos);
                
                list1head= list1head->next;
                list2head= list2head->next;
                temp.num_nodes++;
                
            }
            else if(list1head->position < list2head->position)
            {
                val = list1head -> value;
                pos = list1head -> position;
                temp.head = new node(val,pos);
                list1head= list1head->next;
                temp.num_nodes++;
                
            }
            else
            {
                val = list2head -> value;
                pos = list2head -> position;
                temp.head = new node(val,pos);
                list2head= list2head->next;
                temp.num_nodes++;
            }
        }
        else
        {
            if(list1head->position==list2head->position)
            {
                val = list1head -> value + list2head -> value; //check zero
                pos = list1head -> position;
                if(val!=0)
                list3ptr = new node(val,pos);
                
                q= temp.head;
                while(q->next!=nullptr)
                q= q->next;
                
                q->next = list3ptr;
                
                list1head= list1head->next;
                list2head= list2head->next;
                temp.num_nodes++;
            }
            else if(list1head->position < list2head->position)
            {
                val = list1head -> value;
                pos = list1head -> position;
                list3ptr = new node(val,pos);
                
                q= temp.head;
                while(q->next!=nullptr)
                q= q->next;
                
                q->next = list3ptr;
                
                list1head= list1head->next;
                temp.num_nodes++;
            }
            else
            {
                val = list2head -> value;
                pos = list2head -> position;
                list3ptr = new node(val,pos);
                
                q= temp.head;
                while(q->next!=nullptr)
                q= q->next;
                
                q->next = list3ptr;
                
                list2head= list2head->next;
                temp.num_nodes++;
            }
            
        }
        
    }
    
    while(list1head!=nullptr){
        val = list1head -> value;
        pos = list1head -> position;
        list3ptr = new node(val,pos);
        
        q= temp.head;
        while(q->next!=nullptr)
        q= q->next;
        
        q->next = list3ptr;
        
        list1head= list1head->next;
        temp.num_nodes++;
    }
    
    while (list2head!=nullptr) {
        val = list2head -> value;
        pos = list2head -> position;
        list3ptr = new node(val,pos);
        
        q= temp.head;
        while(q->next!=nullptr)
        q= q->next;
        
        q->next = list3ptr;
        
        list2head= list2head->next;
        temp.num_nodes++;
    }
    
    
    //You need to complete the implementation.
    
    return temp;
    
}

int main() {
    
    my_vector V1, V2, V3;
    V1.make_random_vector(30, 8, 10);
    V1.print();
    V2.make_random_vector(30, 6, 10);
    V2.print();
    V3 = V1 + V2;
    V3.print();
    int inner_product = V1 * V2;
    out << inner_product << endl;
    
    out.close();
    return 0;
    
}

