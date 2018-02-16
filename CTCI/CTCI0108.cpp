

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void zeroMatrix(int m,int n);

int main() {
    zeroMatrix(5,6);
    return 0;
}

void zeroMatrix(int m, int n)
{
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)          
        {
            if(i==3 & j==2)            // making one element 0 rest all are 1
                a[i][j]=0;
            else
                a[i][j]=1;
        }
        
        //cout<<"\n";
    }

    for(int i=0;i<m;i++)               //displaying the matrix
    {
        for(int j=0;j<n;j++)
        {
            cout<< a[i][j]<<" ";
            
        }
        
        cout<<"\n";
    }
    
    for(int i=0;i<m;i++)               //replacing col and rows to where a[i][j]=0
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                for(int k=0;k<n;k++)
                    a[i][k]=0;
                for(int l=0;l<m;l++)
                    a[l][j]=0;
                goto a;                 //when all col and rows are replaced by 0 goto exiting the loop
            }
        }
        
        //cout<<"\n";
    }
a:
    cout<<"\nREsult\n";               //displaying results
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<< a[i][j]<<" ";
            
        }
        
        cout<<"\n";
    }
    
}

