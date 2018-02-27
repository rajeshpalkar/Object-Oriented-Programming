#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

class Graph{
    
public:
    list<int> *adj;
    int V;
    
    Graph(int v){
        V = v;
        adj =  new list<int>[V];
    }
    void addEdge(int v, int w);
    void bfs(int s,int t);
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::bfs(int s, int t)
{
    bool visited[V],visitedT[V];
    
    for(int i=0;i<V; i++){
        visited[i] = false;
        visitedT[i] =false;
    }
    
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    
    list<int> queueT;
    visitedT[t] = true;
    queueT.push_back(t);
    

    list<int>::iterator itr;
    list<int>::iterator itrT;
    
    list<int>::iterator i,j;
    
    while(!queue.empty() && !queueT.empty())
    {
        
        cout<<"\n QUEUE1 elements: ";
        for(i = queue.begin(); i!= queue.end(); i++)
            cout<<" -> "<<*i;
        
        cout<<"\n QUEUE2 elements: ";
        for(j = queueT.begin(); j!= queueT.end(); j++)
            cout<<" -> "<<*j;
        
        s = queue.front();
        cout<<"\nQ1 "<<s;
        queue.pop_front();
        
        t = queueT.front();
        cout<<"\nQ2 "<<t;
        queueT.pop_front();
        
        
        for(itr = adj[s].begin(); itr!= adj[s].end(); itr++)
        {
            if(visited[*itr]==true && visitedT[*itr]==true)
            {cout<<"\n there exist a path!"; goto a;}
            if(!visited[*itr])
            {
                queue.push_back(*itr);
                visited[*itr] = true;
            }
        }
            
        for(itrT = adj[t].begin(); itrT!=adj[t].end();itrT++)
        {
             if(visited[*itrT]==true && visitedT[*itrT]==true)
             {cout<<"\n there exist a path!"; goto a;}
            
           
            if(!visitedT[*itrT]){
                queueT.push_back(*itrT);
                visitedT[*itrT] = true;
            }
           
        }
        
    }
    
    cout<<"\n there is no path!";
    a:
    cout<<"\n";
    
}


int main()
{
    Graph g(37);
    
    cout<<"\n";
     g.addEdge(1, 2);
     g.addEdge(1, 3);
     g.addEdge(1, 4);
     g.addEdge(1, 5);
    
    
    
    g.addEdge(2, 12);
    g.addEdge(2, 13);
    
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    
    g.addEdge(4, 8);
    g.addEdge(4, 9);
    
    g.addEdge(5, 10);
    g.addEdge(5, 11);
    
    g.addEdge(6, 23);
    g.addEdge(6, 24);
    g.addEdge(6, 25);
   
    g.addEdge(7, 20);
    g.addEdge(7, 21);
    g.addEdge(7, 22);
    
 //   g.addEdge(8, 17);
  //  g.addEdge(8, 18);
    g.addEdge(8, 19);
    
    g.addEdge(9, 14);
    g.addEdge(9, 15);
    g.addEdge(9, 16);
    
    g.addEdge(10, 26);
    g.addEdge(10, 27);
    g.addEdge(10, 28);
    
    g.addEdge(11, 29);
    g.addEdge(11, 30);
    g.addEdge(11, 31);
    
    g.addEdge(12, 32);
    g.addEdge(12, 33);
    g.addEdge(12, 34);
    
    g.addEdge(13, 35);
    g.addEdge(13, 36);
    g.addEdge(13, 37);
    
    g.addEdge(12, 1);
    g.addEdge(13, 1);
    g.addEdge(10, 1);
    g.addEdge(11, 1);
    
     g.addEdge(1,11);
    
   /* g.addEdge(5, 12);
    g.addEdge(12, 13);
    g.addEdge(13, 3);
    g.addEdge(3, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 5);*/
    
    g.bfs(4, 19);
    

    
    cout<<"\n";
    return 0;
}

