

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string stringCompression(string test);

int main() {
    string test= "aaabcccccaaa";
    string res = stringCompression(test);
    cout<<"\nOutput: "<<res;
    return 0;
}

string stringCompression(string test)
{
    string temp;
    int count=1;
    for(int i=0;i<=test.length();i++)
    {
        if(i==0)       // for the first element registry
        {
            temp = test[i];
            cout<<"\nTemp: "<<temp;
        }
        else
        {
            if(test[i-1]==test[i])  //checking if the element occured previously
                count++;
            else
            {
                temp = temp + to_string(count);    //append the count
                cout<<"\nTemp: "<<temp;
                count=1;                           //make count to 1 (default value)
                temp.append(1,test[i]);
                cout<<"\nTemp: "<<temp;            
            }
        }
    }
    if(temp.length()<test.length())
        return temp;
    else
        return test;
}

