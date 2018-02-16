#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
   // reverseString("Hello");
    
   //Checked every letter with every other letter except itself
        string test = "1323";
        int flag=1;
    
        for(int i=0;i<test.size();i++)
        {
            for(int j=0;j<test.size();j++)
            {
                if(i!=j)
                {
                    if(test[i]==test[j])
                        flag=0;
                }
            }
        }
        
        if(flag==0)
            cout<<" Not Unique\n";
        else
            cout<<" Unique\n";
        return 0;
  
    
}
