#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class SOA{

public:
    int array[9];          // array which holds three stacks
    int firstIndex=0;      // first index of first stack start with 0 then 3, and 6
    int secondIndex=1;     // second index of second stack start with 1 then 4, and 7
    int thirdIndex=2;      // third index of third stack start with 2 then 5, and 8
    

    void push(int x, int stack);  //takes the paramertes stack's number and data 
    int pop(int stack);           //takes stack as parameter to find which stack's number to pop the number
    void pushOne(int x);
    void pushTwo(int x);
    void pushThree(int x);
    int popOne();
    int popTwo();
    int popThree();
};

void SOA::push(int x, int stack)
{
    switch (stack) {        //depending on stack number call goes to that stack's push
        case 1:
            pushOne(x);
            break;
        case 2:
            pushTwo(x);
            break;
        case 3:
            pushThree(x);
            break;
            
        default:
            break;
    }
}

int SOA::pop(int stack)
{
    switch (stack) {      //depending on stack number call goes to that stack's pop
        case 1:
            return popOne();
            break;
        case 2:
            return popTwo();
            break;
        case 3:
            return popThree();
            break;
    }
    return false;
}

void SOA::pushOne(int x)
{
    if(firstIndex > sizeof(array)/4-1) //checking if first index gets more than array size then its overflow
        cout<<"\nOverflow!!";
    else{
    array[firstIndex] = x;
    firstIndex = firstIndex + 3;       //incrementing the index of elements by 3
        }
}

void SOA::pushTwo(int x)
{
    if(secondIndex > sizeof(array)/4-1)
        cout<<"\nOverflow!!";
        else{
            array[secondIndex] = x;
            secondIndex = secondIndex + 3;
        }
}

void SOA::pushThree(int x)
{
    if(thirdIndex > sizeof(array)/4-1)
        cout<<"\nOverflow!!";
        else{
            array[thirdIndex] = x;
            thirdIndex = thirdIndex + 3;
        }
}

int SOA::popOne()
{
    firstIndex = firstIndex - 3;      //decrementing the index by 3
    int x = array[firstIndex];
    array[firstIndex] = 0;
    if(firstIndex < 0)                //if the index count goes to negative that means the underflow
        cout<<"\n Underflow!!";     
    
    return x;
}

int SOA::popTwo()
{
    secondIndex = secondIndex - 3;
    int x = array[secondIndex];
    array[secondIndex] = 0;
    if(secondIndex < 0)
        cout<<"\n Underflow!!";
    
    return x;
}

int SOA::popThree()
{
    thirdIndex = thirdIndex - 3;
    int x = array[thirdIndex];
    array[thirdIndex] = 0;
    if(thirdIndex < 0)
        cout<<"\n Underflow!!";
    
    return x;
}

int main()
{
    SOA a;
    
    a.push(44,1);
     a.push(55,1);
     a.push(66,1);
    //a.push(13, 1);
    
    a.push(77, 2);
     a.push(88, 2);
     a.push(99, 2);
   // a.push(23, 2);
    
    a.push(30, 3);
    a.push(31, 3);
    a.push(32, 3);
   // a.push(33, 3);
    
    cout<<"\nPoped: "<<a.pop(2);
    cout<<"\nPoped: "<<a.pop(2);
    cout<<"\nPoped: "<<a.pop(2);
    
    cout<<"\nPoped: "<<a.pop(3);
    cout<<"\nPoped: "<<a.pop(1);
 //   cout<<"\nPoped: "<<a.pop(2);
    
   // a.push(24, 2);

    
    
    cout<<"\n";
    for(int i=0;i<9;i++)
        cout<<" "<<a.array[i];
    
    cout<<"\n";
    return 0;
}
