
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void rotateMatrix(int m,int n);

int main() {
    rotateMatrix(6,6);
    return 0;
}

void rotateMatrix(int m, int n)
{
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=i*j + i;      // inserting random numnbers in matrix
        }
        
        //cout<<"\n";
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<< a[i][j]<<"   ";   //displaying original matrix
            
        }
        
        cout<<"\n";
    }
    
   for(int i=0;i<m;i++)          // transposing matrix by changing row and columns
    {
        for(int j=0;j<n;j++)
        {
            if(i<j){             // make sure to transpose only half of the matrix other wise full transpose will get doewn to original matrix
            int temp = 0;
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
            }
        }
        
        //cout<<"\n";
    }

    cout<<"\nTranspose\n";     // displaying transpose matrix
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<< a[i][j]<<"    ";
        }
        cout<<"\n";
    }


    for(int i=0;i<m;i++)        // reversing the rows of matrix to rotate matrix to its right
    {
        for(int j=0;j<n;j++)
        {
            if(j<=n/2)          // make sure to swap only half of the matrix otherwise it will lead to original matrix
            {
            int temp;
            temp = a[i][j];
            a[i][j] = a[i][n-j-1];
            a[i][n-j-1] = temp;
           }
        }
        
    }
    


cout<<"\nResult\n";
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<< a[i][j]<<"    ";
    }
    cout<<"\n";
}

}
