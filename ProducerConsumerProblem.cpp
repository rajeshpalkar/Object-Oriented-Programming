//
//  main.cpp
//  CPP07
//
//  Created by Rajesh Palkar on 12/3/17.
//  Copyright © 2017 Rajesh Palkar. All rights reserved.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <ctime>

std::mutex m;
std::condition_variable r1[3],r2[3];

void bufferSpacePut(int productionRequest[],int i);
void bufferSpaceGet(int consumerRequest[],int i);
void placeRequest(int productionRequest[]);
void getRequest(int consumerRequest[]);
void PartWorker(int i);
void ProductWorker(int i);
int buffer[3] = {0,0,0};
int mark[3] = {0,0,0};

int main(int argc, const char * argv[]) {
    // insert code here...
    
        std::thread partW[10];
        std::thread prodW[7];
        for (int i = 0; i < 7; i++){
            partW[i] = std::thread(PartWorker, i);
            prodW[i] = std::thread(ProductWorker, i);
        }
        for (int i = 7; i<10; i++) {
            partW[i] = std::thread(PartWorker, i);
        }
        /* Join the threads to the main threads */
        for (int i = 0; i < 7; i++) {
            partW[i].join();
            prodW[i].join();
        }
        for (int i = 7; i<10; i++) {
            partW[i].join();
        }
    std::cout << "Finish!" << std::endl;
        return 0;
}

void PartWorker(int i)
{
    int productionRequest[3];
    placeRequest(productionRequest);
    bufferSpacePut(productionRequest,i);
    
}

void ProductWorker(int i)
{
    int consumerRequest[3];
    getRequest(consumerRequest);
    bufferSpaceGet(consumerRequest,i);
}

void placeRequest(int productionRequest[])
{
    int a,b,c;
    bool x=false;
    
   // srand((unsigned)time(0));
    
    while(x==false){
        a = rand() % 4;
        b = rand() % 4;
        c = rand() % 4;
        if(a+b+c == 3)
        {
            x=true;
        }
    }
    productionRequest[0]= a;
    productionRequest[1]= b;
    productionRequest[2]= c;
}

void getRequest(int consumerRequest[])
{
    int a,b,c;
    
    
    int x = rand()%3;
    
    switch (x)
    {
        case 0:  // a and b
        {
            c =0;
            
            int y = rand()%3;
            switch(y)
            {
                case 0:
                    a = 1;
                    b = 3;
                    break;
                case 1:
                    a = 3;
                    b = 1;
                    break;
                case 2:
                    a = 2;
                    b = 2;
                    break;
            }
        }
            break;
        
        case 1:  // a and c
        {
            b =0;
            
           int y = rand()%3;
            switch(y)
            {
                case 0:
                    a = 1;
                    c = 3;
                    break;
                case 1:
                    a = 3;
                    c = 1;
                    break;
                case 2:
                    a = 2;
                    c = 2;
                    break;
            }
        }
            break;
        
            
        case 2:  // b and c
        {
            a =0;
            
           int y = rand()%3;
            switch(y)
            {
                case 0:
                    b = 1;
                    c = 3;
                    break;
                case 1:
                    b = 3;
                    c = 1;
                    break;
                case 2:
                    b = 2;
                    c = 2;
                    break;
            }
        }
            break;
        
    }
 
    
    consumerRequest[0]= a;
    consumerRequest[1]= b;
    consumerRequest[2]= c;
}

void bufferSpacePut(int productionRequest[],int i)
{
    
    int a = productionRequest[0];
    int b = productionRequest[1];
    int c = productionRequest[2];
    
    std::unique_lock<std::mutex> ulock1(m);
    
    loop:
    mark[0] = 0;
    mark[1] = 0;
    mark[2] = 0;
    
    std::cout << "\n\nPartWorker ID: "<<i;
    std::cout << "\nBuffer State: (" << buffer[0] << "," << buffer[1] << "," << buffer[2] << ")";
    std::cout << "\nPlace Request: (" << productionRequest[0] << "," << productionRequest[1] << "," << productionRequest[2] << ")";
    
    while((a!=0 && buffer[0]!= 6) || (b!=0 && buffer[1]!= 5) || (c!=0  && buffer[2]!= 4))
    {
      
        if(buffer[0] + a <= 6)
        {
            buffer[0] = buffer[0] + a;
            a = 0;
            r2[0].notify_one();
            if(buffer[0]==6)
            {
                mark[0] = 1;
            }
        }
        else{
            
            int x = 6 - buffer[0];
            buffer[0] = buffer[0] + x;
            a = a - x;
            r2[0].notify_one();
            if(buffer[0]==6)
            {
                mark[0] = 1;
            }

        }
        
        if(buffer[1] + b <= 5)
        {
            buffer[1] = buffer[1] + b;
            b = 0;
            r2[1].notify_one();
            if(buffer[1]==6)
            {
                mark[1] = 1;
            }

        }
        else{
            int x = 5 - buffer[1];
            buffer[1] = buffer[1] + x;
            b = b - x;
            r2[1].notify_one();
            if(buffer[1]==6)
            {
                mark[1] = 1;
            }

        }
        
        if(buffer[2] + c <= 4)
        {
            buffer[2] = buffer[2] + c;
            c = 0;
            r2[2].notify_one();
            if(buffer[2]==6)
            {
                mark[2] = 1;
            }

        }
        else{
            int x = 4 - buffer[2];
            buffer[2] = buffer[2] + x;
            c = c - x;
            r2[2].notify_one();
            if(buffer[2]==6)
            {
                mark[2] = 1;
            }

        }
    }
    productionRequest[0] = a;
    productionRequest[1] = b;
    productionRequest[2] = c;
    
    std::cout << "\nUpdated Buffer State: (" << buffer[0] << "," << buffer[1] << "," << buffer[2] << ")";
    std::cout << "\nUpdated Place Request: (" << productionRequest[0] << "," << productionRequest[1] << "," << productionRequest[2] << ")";
    
    
    if (mark[0] == 1)
        r1[0].wait(ulock1);
    if (mark[1] == 1)
        r1[1].wait(ulock1);
    if (mark[2] == 1)
        r1[2].wait(ulock1);
    
    if ((mark[0] == 1 && productionRequest[0] != 0) ||
        (mark[1] == 1 && productionRequest[1] != 0) ||
        (mark[2] == 1 && productionRequest[2] != 0))
    {
        goto loop;
    }
}

void bufferSpaceGet(int consumerRequest[], int i)
{
    int a = consumerRequest[0];
    int b = consumerRequest[1];
    int c = consumerRequest[2];
    
    std::unique_lock<std::mutex> ulock1(m);
    
    loop1:
    
    mark[0] = 0;
    mark[1] = 0;
    mark[2] = 0;
    
    std::cout << "\n\nProductWorker ID: "<<i;
    std::cout << "\nBuffer State: (" << buffer[0] << "," << buffer[1] << "," << buffer[2] << ")";
    std::cout << "\nPickup Request: (" << consumerRequest[0] << "," << consumerRequest[1] << "," << consumerRequest[2] << ")";

    int x=0,y=0,z=0;
    if(a==0)
    {
        while((y!=b && buffer[1]!= 0) || (z!=c && buffer[2]!= 0))
        {
            if(b!=0 && buffer[1]!=0)
            {
                b--;//y++;
                buffer[1]--;
            
                r1[1].notify_one();
                if(buffer[1]==0)
                {
                    mark[1]=1;
                }
            }
        
            if(c!=0 && buffer[2]!=0)
            {
                c--;//z++;
                buffer[2]--;
                
                r1[2].notify_one();
                if(buffer[2]==0)
                {
                    mark[2]=1;
                }
            }
        }
        
        
    }
    
    if(b==0)
    {
        while((x!=a && buffer[0]!= 0) || (z!=c && buffer[2]!= 0))
        {
            if(a!=0 && buffer[0]!= 0)
            {
                a--;//x++;
                buffer[0]--;
                
                r1[0].notify_one();
                if(buffer[0]==0)
                {
                    mark[0]=1;
                }
                
            }
            
            if(c!=0 && buffer[2]!= 0)
            {
                c--;//z++;
                buffer[2]--;
                
                r1[2].notify_one();
                if(buffer[2]==0)
                {
                    mark[2]=1;
                }
                
            }
        }
    }
    
    if(c==0)
    {
        while((x!=a && buffer[0]!= 0) || (y!=b && buffer[1]!= 0))
        {
            if(a!=0 && buffer[0]!=0)
            {
                a--;//x++;
                buffer[0]--;
                
                r1[0].notify_one();
                if(buffer[0]==0)
                {
                    mark[0]=1;
                }
            }
            
            if(b!=0 && buffer[1]!=0)
            {
                b--;//y++;
                buffer[1]--;
                
                r1[1].notify_one();
                if(buffer[1]==0)
                {
                    mark[1]=1;
                }
            }
        }
    }
    
    consumerRequest[0] = a;
    consumerRequest[1] = b;
    consumerRequest[2] = c;
    
    std::cout << "\nUpdated Buffer State: (" << buffer[0] << "," << buffer[1] << "," << buffer[2] << ")";
    std::cout << "\nUpdated Pickup Request: (" << consumerRequest[0] << "," << consumerRequest[1] << "," << consumerRequest[2] << ")";
    
    
    if (mark[0] == 1)
        r2[0].wait(ulock1);
    if (mark[1] == 1)
        r2[1].wait(ulock1);
    if (mark[2] == 1)
        r2[2].wait(ulock1);
    
    if ((mark[0] == 1 && consumerRequest[0] != 0) ||
        (mark[1] == 1 && consumerRequest[1] != 0) ||
        (mark[2] == 1 && consumerRequest[2] != 0))
    {
        goto loop1;
    }
   
}


    

