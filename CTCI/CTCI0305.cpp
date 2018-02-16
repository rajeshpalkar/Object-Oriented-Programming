#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

std::stack<int> sortStack(std::stack<int> s1);

using namespace std;




int main() {
    
    stack<int> s1;
    int x;
    
    //created a random stack
    for(int i = 4;i<8;i++)
        s1.push(i*i);
    
    s1.pop();
    cout<<"\n";
    
    
    s1.push(5);
    s1.push(10);
    s1.push(23);
    cout<<"\n";
    
    
    
    cout<<"\n";
    
    stack<int> s3 = sortStack(s1);
    
    for(int i = 4;i<10;i++)     //just for displaying elements of stack
    {
        x = s3.top();
        cout<<" "<<x;
        s3.pop();
    }
    
    cout<<"\n";
    
}


std::stack<int> sortStack(std::stack<int> s1)
{
    stack<int> s2;
    
    int x;
    //checking if s1 first stack itself is not empty
    if(!s1.empty()){
        x = s1.top();
        s2.push(x);
        s1.pop();
    }
    
    while(!s1.empty())
    {
        if(s1.top() > s2.top())     //if s2's element is less than s1's then push directly
        {
            x = s1.top();
            s2.push(x);
            s1.pop();
        }
        else{                      //otherwise swap the tops
            int x = s1.top();
            int y = s2.top();
        
            s1.pop();
            s2.pop();
        
            s2.push(x);
            s1.push(y);
        }
    }
    
    if(!s2.empty()){      //checking while putting all elements back to s1, first putting one element in s1
        x = s2.top();
        s1.push(x);
        s2.pop();
    }
    
    while(!s2.empty())   //here checking the reverse conditions as above 
    {
        if(s1.top() > s2.top())
        {
            x = s2.top();
            s1.push(x);
            s2.pop();
        }
        else{
            int x = s1.top();
            int y = s2.top();
            
            s1.pop();
            s2.pop();
            
            s2.push(x);
            s1.push(y);
        }
    }
    
    return s1;
}


