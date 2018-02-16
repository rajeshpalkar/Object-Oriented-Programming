
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool stringRotation(string test1,string test2);

int main() {
 
    string test1 = "optimusprime";
    string test2 = "usprimeoptim";
    
    bool res = stringRotation(test1, test2);      //only one call to isSubstring function i.e. stringRotation
    if(res==true)
    {
        cout<<"\nYes! "<<test2<<" is subtring rotation of "<<test1<<"\n";
        
    }else{
         cout<<"\nNooooo! "<<test2<<" is not subtring rotation of "<<test1<<"\n";
    }

}

bool stringRotation(string test1,string test2)
{
    int flag=0;
    string test3 = test1 + test1;
    int i,j = 0;
    if(test1.length()==test2.length())    // checking if both strings are of same length or not
    {
    //cout<<"\nLen "<<test3.length();
    while(j<=test3.length())
    {
     while(test3[j]!=test2[0] & j!=test2.length()) // incrementing j index of bigger string until it 
            j++;                                    //matches first letter of substring
        
            for(i=0;i<test2.length();i++)         // checking every letter in substring 
            {
                if(test2[i]==test3[j])              // if equal setting flag to 1
                {
                    flag = 1;
                    j++;
                }else{
                    flag = 0;                       // if not equal setting flag = 0 and breaking the loop
                    j++;
                    break;
                }
                
            }
        
        if(i==test2.length() & flag==1)            
            goto a;  // checking if substring reached its last letter and flag is 1 that is a match
        
    }
}
return false;
    
a:
    return true;
}
    

