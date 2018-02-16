#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void permute(string str);
bool sentensePallindrome(string str);

int main() {
	string str = "Tact Coa";
	permute(str);
	return 0;
}

void permute(string str)
{
    sort(str.begin(),str.end());
  
    do
    {
         bool res = sentensePallindrome(str);
        if(res)
        {
            if(str[4]==' ')              // we only want the palindrome with taco cat, atco cta, etc.. type
        cout<< str <<"\n";
        }
    }while(next_permutation(str.begin(),str.end())); //rotates the senetences including spaces
    
     
}


bool sentensePallindrome(string str)
{
    int l=0, h = str.length();
    
    for (int i = 0; i < h; i++)
        str[i] = tolower(str[i]);                      
    
    while(l<=h)
    {
        if (!(str[l] >= 'a' && str[l] <= 'z' ))
            l++;
        
        else if (!(str[h] >= 'a' && str[h] <= 'z'))
            h--;
        
        if(str[l]==str[h])
        {
            l++;
            h--;
        }
        else
            return false;
        
    }
    return true;
}