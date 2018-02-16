

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool oneWay(string input,string output);

int main() {
    string input = "pale", output = "bake";
    bool res = oneWay(input,output);
    if(res)
        cout<<"\nTrue!";
    else
        cout<<"\nFalse!";
    return 0;
}

bool oneWay(string input, string output)
{
    int count =0,i=0,j=0 ;
    while(i<input.length() & j<output.length())
    {
        if(output[j]==input[i])   // checking if input char is same as output char
        {
            i++;
            j++;
        }
        else
        {
            if(output[j]==input[i+1])   // checking output's current char is input's next char 
            {                           // hence removing input's current char
                input.erase(remove(input.begin(), input.end(), input[i]), input.end());
                cout<<"\nRemove "<<input;
                //remove input char i
                count++;
                i++;
                j++;
            }else if(output[j+1]==input[i+1])  // checking output's next char is input's next char 
            {                                 // hence replacing inupt's current char with output's current
                //replace input char i
               // input.replace(input[i],input[i],input[i],output[j]);
                input[i] = output[j];
                cout<<"\n Replaced "<<input;
                count++;
                i++;
                j++;
            }
        }
    }
    
    while(i<input.length())    // checking if input char is still remaining hence erasing all 
    {
        input.erase(remove(input.begin(), input.end(), input[i]), input.end());
        //remove char from input
        cout<<"\n Replaced "<<input;
        i++;
        count++;
    }
    while(j<output.length())  // checking if output char is still remaining hence adding 
    {
        input.insert(input[i],1,output[j]);
        //insert chat in input
        cout<<"\n Replaced "<<input;
        j++;
        count++;
    }
    
    
    if(input==output & (count<2))
        return true;
    else
        return false;
    
    
    
}

