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

class BST{
    
    public:
    node *root;
    
    node* insert(node *root,int x);
    void printIn(node *temp);
    void levelTraversal(node *temp);
    node * makeBST(int [],int mid, int n,node *);
};


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


void BST::printIn(node *temp)
{
    if(temp == nullptr)
        return;
    
    printIn(temp->left);
    cout<<"-> "<<temp->data;
    printIn(temp->right);
}

void BST::levelTraversal(node *root)
{
    
    if(root == nullptr)
        return;
    
    queue<node *> queue;
    
    queue.push(root);
    
    while(1)
    {
        int numNodes = (int)queue.size();
        if(numNodes==0)
            break;
        while(numNodes>0)
        {
        node * temp = queue.front();
        cout<<" "<<temp->data;
        queue.pop();
        if(temp->left!=nullptr)
            queue.push(temp->left);
        if(temp->right!=nullptr)
            queue.push(temp->right);
        numNodes--;
        }
        cout<<endl;
    }
    
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

int main()
{

   
    BST b1,b2;
    node *root = nullptr;
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
    
    cout<<"\nNodes in tree: ";
    b1.printIn(root);
  
    cout<<"\nLevel: \n";
    b1.levelTraversal(root);
    
    //sorted array:
    int a[10];
    
    for(int i=0;i<10;i++)
        a[i]=i+1;
    
   

    
    int n = (sizeof(a)/4);


    b1.root =nullptr;
    
    
    b1.root = b1.makeBST(a,0,n,b1.root);
    

    cout<<"\nBalanced Level: \n";
    b2.levelTraversal(b1.root);
    
    cout<<"\n";
    return 0;
}

