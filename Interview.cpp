// Assignment No. 4

/*   You are a job seeker preparing for a interview in different location. You have a list of cities where interviews are schedule. Objective is to minimize the 
     total travel distance and time which ensuring you to reach each interview location on time.
     Use appropriate data structure and algorithm to implement it.

      - You want to find the shortest path to visit all interview location.
      - Starting from your current location.   

     */
     
#include<iostream>
using namespace std;


class MST
{
  int v;
  string city[10];
  int adj[10][10];
  
  public:
      void create();
      void sp();
}e;


void MST :: create()
{
    cout << "Enter the number of cities: ";
    cin >> v;
    cout << "\nEnter the names of the cities:\n";

   
    for(int i = 0; i < v; i++) 
    {
          
        cout << "  Enter city " << (i + 1) << " name: ";
        cin >> city;
        
    }
    
    for(int i = 0; i < v; i++)
    {
    for(int j = 0; j < v; j++)
    {
      if(i == j)
      {
        adj[i][j] = 0;
      }
      else
      {
        cin >> adj[i][j];
      }
    }
    }
}


void MST :: sp()
{
  int key[10];
  int parent[10];
  bool visited[10];
  
  for(int i = 0; i < n; i++)
  {
    visited[i] = false;
    key[i] = 999;
    parent[i] = 999;
  }
  
  int min = 999, u;
  key(0) = 0;
  parent(0) = -1;
  
  
  for(e = 0; e < v-1; e++)
  {
    min = 999;
    for(i = 0; i < v; i++)
    {
      if(!visited[i] && min > key[i])
      {
        min = key[i];
        u = i;
      }
    }
    
    visited(u) = true;
    for(j = 0; j < v; j++)
    {
      if(adj[u][j] && !visited[j] && adj[u][j] < key[j])
      {
        parent[j] = u;
        key[j] = adj[u][j];
      }
    }
  }
}
  
}
