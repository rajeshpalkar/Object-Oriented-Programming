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
    int checkBalanced(node *root);
    void levelTraversal(node *root);
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

int BT::checkBalanced(node *root)
{
    int leftHeight=0,rightHeight=0;
    if(root==nullptr){
        cout<<"\n There is no tree! ";
        return -1;
    }
    
    node *temp = root;
    
    if(temp->left!=nullptr)
    {
       // leftHeight++;
        leftHeight = checkBalanced(temp->left) +1;
    }
    if(temp->right!=nullptr)
    {
        //rightHeight++;
        rightHeight = checkBalanced(temp->right) +1;
    }
    
    
    if(abs(leftHeight-rightHeight)>1)
    {
        cout<<"\nTree is not Balanced at: "<<root->data;
        //return -1;
    }
    
    return max(leftHeight,rightHeight);
    
}
int main()
{
    
    //This tree is not balanced at 2,4,9,8,6 nodes
    
    BT b1;
    
     b1.root= b1.insert(b1.root, 5);
     b1.root= b1.insert(b1.root, 2);
     b1.root= b1.insert(b1.root, 1);
     b1.root= b1.insert(b1.root, 6);
     b1.root= b1.insert(b1.root, 8);
     b1.root= b1.insert(b1.root, 4);
     b1.root= b1.insert(b1.root, 3);
     b1.root= b1.insert(b1.root, 7);
     b1.root= b1.insert(b1.root, 9);
     b1.root= b1.insert(b1.root, 2.5);
     b1.root= b1.insert(b1.root, 10);
     b1.root= b1.insert(b1.root, 11);
    
    
    
    b1.levelTraversal(b1.root);
    b1.checkBalanced(b1.root);
    
    cout<<endl;
    return 0;
}

