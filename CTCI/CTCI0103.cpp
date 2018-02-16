#include <iostream>
#include <algorithm>

using namespace std;

void reverseString(std:: string s);

int main(int argc, const char * argv[]) {
   // reverseString("Hello");
 

        
        string test = "This is Optimus Prime                             ";
        //string result;
        
        for(int i=0;i<test.size();i++)
        {
            if(test[i]==' ' && test[i+1]==' ')   // to avoid adding %20 at last of the sentense
                break;
            else{
                if(test[i]==' ')
                    test.replace(i,1,"%20");  //as space bar is replaced by %20 added one more space 1
            }
        }
        
        cout<<"\n Result:"<<test;
        return 0;
    
}
