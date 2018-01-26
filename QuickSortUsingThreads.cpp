//
//  main.cpp
//  CPP05
//
//  Created by Rajesh Palkar on 11/5/17.
//  Copyright © 2017 Rajesh Palkar. All rights reserved.
//

#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
using namespace std;

int partitionArray(vector<int> &V, int low, int high);
void swapNumbers(int *i,int *j);
//The following funciton will be the work for each thread
void quick_sort(vector<int> &V, int i, int j); //sort elements of vector V from position i to position j


int partitionArray(vector<int> &V, int low, int high)
{
    int pivot = V[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++)
    {
        if (V[j] <= pivot)
        {
            i++;
            swapNumbers(&V[i],&V[j]);
        }
    }
    
    swapNumbers(&V[i+1],&V[high]);
    return (i + 1);
}

void swapNumbers(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void quickSort(vector<int> &V, int low, int high) {
    if (low < high) {
        int center = partitionArray(V, low, high);
        quickSort(V, low, center - 1);
        quickSort(V, center + 1, high);
    }
}

int main() {
    
    int n = 100000;
    int firstInterval, secondInterval, thirdInterval;
    vector<int> V(n);//V has n elements.
    for (int i = 0; i < 100000; i++) V[i] = rand() % 5000;
    //You need to crate four threads to help perform sorting
    //You need to then save the sorted result to output.txt
    
    thread t[4];
    ofstream ofs;
    
    secondInterval = partitionArray(V, 0, n - 1);
    
    if (secondInterval != 0)
    {
        firstInterval = partitionArray(V, 0, secondInterval - 1);
    }
    else
    {
        firstInterval = 0;
    }
    if (secondInterval != n - 1)
    {
        thirdInterval = partitionArray(V, secondInterval + 1, n - 1);
    }
    else
    {
        thirdInterval = n;
    }
    
    t[0] = thread(quickSort, ref(V), 0, firstInterval - 1);
    t[1] = thread(quickSort, ref(V), firstInterval + 1, secondInterval - 1);
    t[2] = thread(quickSort, ref(V), secondInterval + 1, thirdInterval - 1);
    t[3] = thread(quickSort, ref(V), thirdInterval + 1, n - 1);
    
    for (int i = 0; i < 4; i++)
    {
        t[i].join();
    }
    
    ofs.open("output.txt");
    
    for(int i = 0 ; i< n ; i++)
        ofs<< " " << V[i];
    
    getchar();
}




