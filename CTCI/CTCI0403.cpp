#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


class node{
    
public:
    int data;
    node *left;
    node *right;
    
    
    node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
    
    
};


class listNode{
public:
    int data;
    listNode *next;
    
    
    listNode(int x){
        data = x;
        next = nullptr;
    }
    
};

class linked_list{
    
public:
    listNode *listRoot;
    
    listNode* insert(listNode *root,int x);
   // void print(vector<linked_list> lv);
    
};


class BST{
    
public:
    node *root;
    
    node* insert(node *root,int x);
    vector<linked_list> levelTraversal(node *temp);
    node * makeBST(int [],int mid, int n,node *);
};

class VectorOfLinkedList
{
public:
    void print(vector<linked_list>lv);
};

listNode *linked_list::insert(listNode *root, int x)
{
    listNode * temp = root;
    if(temp==nullptr)
        temp = new listNode(x);
    else
    {
        listNode * temp1 = root;
        while(temp1->next!=nullptr)
            temp1 = temp1->next;
        
        temp1->next = new listNode(x);
    }
    
    return temp;
}

node *BST::insert(node *root,int x)
{
    node *temp = root;
    if(temp==nullptr)
    {
        temp = new node(x);
    }
    else{
        
        if(x < temp->data)
            temp -> left = insert(temp->left,x);
        else
            temp -> right = insert(temp->right,x);
        
    }
    
    return temp;
    
}

node *BST::makeBST(int a[],int l,int n, node *root)
{
    
    int m = (l+n)/2;
    
    if(l==n)
    {
        m = l;
        return root;
    }
    root = insert(root, a[m]);
    
    makeBST(a, l, m, root);
    makeBST(a, m+1, n, root);
    
    return root;
}


void VectorOfLinkedList::print(vector<linked_list> LV)
{

    for (vector<linked_list>::iterator iter = LV.begin();
         iter != LV.end(); iter++)
     {
        //listNode *temp = root;
         listNode *temp = iter->listRoot;
         while(temp!=nullptr)
         {
            cout<<" "<<temp->data;
            temp = temp->next;
         }
         cout<<endl;
    }

}

vector<linked_list> BST::levelTraversal(node *root)
{
    
   
    vector< linked_list > linkedListVector;
    if(root==nullptr)
        return linkedListVector;
    vector<linked_list *> vc;
    queue<node *>q;
    
    q.push(root);
    
    
   
    
    while(1)
    {
        linked_list l1;
        l1.listRoot= nullptr;
        int numNodes = (int)q.size();
        if(numNodes==0)
            break;
        while(numNodes>0)
        {
            node * temp = q.front();
            cout<<" "<<temp->data;
            q.pop();
            l1.listRoot = l1.insert(l1.listRoot, temp->data);
            if(temp->left!=nullptr)
                q.push(temp->left);
            if(temp->right!=nullptr)
                q.push(temp->right);
            numNodes--;
        }
         linkedListVector.push_back(l1);
        cout<<endl;
    }
    return linkedListVector;
}


int main()
{
    
    
    BST b1;
  /*  node *root = nullptr;
    root = b1.insert(root,5);
    b1.insert(root,4);
    b1.insert(root,6);
    b1.insert(root,8);
    b1.insert(root,9);
    b1.insert(root,3);
    b1.insert(root,1);
    b1.insert(root,7);
    b1.insert(root,2);
    b1.insert(root,10);
    
    
    cout<<"\nLevel: \n";
    b1.levelTraversal(root);
    */
    //sorted array:
    int a[10];
    
    for(int i=0;i<10;i++)
        a[i]=i+1;
    
    
    
    
    int n = (sizeof(a)/4);
    
    
    b1.root =nullptr;
    
    
    b1.root = b1.makeBST(a,0,n,b1.root);
    
    
    
    cout<<"\nBalanced Level: \n";
    vector<linked_list> LV = b1.levelTraversal(b1.root);
    
    VectorOfLinkedList l1;
    
    cout<<"\n Linked list: \n";
    l1.print(LV);
    cout<<"\n";
    return 0;
}

