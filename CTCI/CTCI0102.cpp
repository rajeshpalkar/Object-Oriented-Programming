#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
   // sort the strings and compare to find out if they have any permutation in them
   
    
    string test1 = "1132";
    string test2 = "121";
 
    //cout<<"\nUnSorted String :"<<test1;
    
    sort(test1.begin(),test1.end());
    sort(test2.begin(),test2.end());
    
    //cout<<"\nSorted String :"<<test1;
    
    if(test1==test2)
        cout<<"\nOne String is Permutation of Other!\n";
  else
      cout<<"\n Not a Permutation!\n";

    return 0;
}
