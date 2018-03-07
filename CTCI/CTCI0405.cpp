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
    node *left;
    node *right;
    int data;
    
    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class BT{
public:
    node *root;
  
    node *insert(node *root,int x);
    void checkBST(node *root);
    void levelTraversal(node *root);
    node *normalTree(node *root,int x);
};

node *BT::insert(node *root, int x){

    node *temp = root;
    if(temp==nullptr)
    {
        temp = new node(x);
    }
    else{
         if(x < temp->data)
            temp->left = insert(temp->left, x);
        else
            temp->right = insert(temp->right, x);
    }
    return temp;
}

void BT::levelTraversal(node *root)
{
    if(root==nullptr)
        return;
    
    queue<node *> q;

    q.push(root);
    
    while(1){
        int numNodes = (int)q.size();
        if(numNodes == 0)
            break;
        while(numNodes>0)
        {
            node *temp = q.front();
            cout<<" "<<temp->data;
            q.pop();
            if(temp->left!=nullptr)
                q.push(temp->left);
            if(temp->right!=nullptr)
                q.push(temp->right);
            numNodes--;
        }
        cout<<endl;
    }
}

node *BT::normalTree(node *root, int x)
{
    node *temp = root;
    if(temp==nullptr)
    {
        temp = new node(x);
    }
    else{
         if(temp->left==nullptr)
             temp->left = new node(x);
        else if(temp->right==nullptr)
            temp->right = new node(x);
        else
            normalTree(temp->left, x);
    }
    return temp;
}

void BT::checkBST(node *root)
{
   
    if(root==nullptr){
        cout<<"\n There is no tree! ";
        return ;
    }
    
    node *temp = root;
    
    if(temp->left!=nullptr)
    {
        if(temp->left->data > temp->data)
            cout<<"\n NOT BST at Left Node of "<<temp->data;
        checkBST(temp->left);
    }
    
    if(temp->right!=nullptr)
    {
        if(temp->right->data < temp->data)
            cout<<"\n NOT BST at right Node of "<<temp->data;
        checkBST(temp->right);
    }

    
}
int main()
{
    BT b1,b2;
    
     b1.root= b1.insert(b1.root, 5);
     b1.root= b1.insert(b1.root, 2);
     b1.root= b1.insert(b1.root, 1);
     b1.root= b1.insert(b1.root, 6);
     b1.root= b1.insert(b1.root, 8);
     b1.root= b1.insert(b1.root, 4);
     b1.root= b1.insert(b1.root, 3);
     b1.root= b1.insert(b1.root, 7);
     b1.root= b1.insert(b1.root, 9);
  
    
    
    b1.levelTraversal(b1.root);
    b1.checkBST(b1.root);
    
    cout<<"\n Normal Tree \n";
    b2.root = nullptr;
    b2.root = new node(5);
    b2.root->left = new node(2);
    b2.root->right = new node(6);
    b2.root->left->left = new node(1);
    b2.root->left->right = new node(4);
    b2.root->right->right = new node(8);
    b2.root->right->right->left = new node(7);
    b2.root->right->right->right = new node(9);
    b2.root->left->right->left = new node(10);   //created unbalanced BST at node 4
    
    
    b2.levelTraversal(b2.root);
    b2.checkBST(b2.root);
   
    cout<<endl;
    return 0;
}

