// Assignment No. 5

/*  - You are planning your wedding and need to select a marriage hall location from list of available option. 
    - You want to find the shortest path from your current location to visit all the marriage hall location.
    - Determine the optimal root that minimize travel distance and time.
    - Use Appropriate Data Structure (Dijkshtras Algorithm) to implement it.                */
    



#include<iostream>
using namespace std;

class MH
{
  int v, ad[10][10];
  string city[10];
  
  public:
         void accept();
         void ssp();
         
}m;


void MH :: accept()
{
   cout<<"\n  Enter the No. of Locations: ";
   cin>>v;
   
   cout<<"\n  Enter Location Name: \n\n";
   for(int i=0; i<v; i++)
   {
     cout<<"    Enter "<<i+1<<" City Name: ";
     cin>>city[i];
   }
   
   cout<<"\n  Enter distance from Source city to Destination City: \n\n";
   for(int i=0; i<v; i++)
   {
     for(int j=i+1; j<v; j++)
     {
        if(i==j)
        {
          ad[i][j]=0;
        }
        else
        {
           cout<<"    Enter "<<city[i]<<" To "<<city[j]<<" Distance: ";
           cin>>ad[i][j];
           ad[j][i]=ad[i][j];
        }
     }
   }
}

/*
void MH :: ssp()
{
   string src;
   int dist[10], visited[10];
   dist[0]=0;
   visited[0]=0;
   
   for(int i=1; i<v; i++)
   {
     dist[i]=999;
     visited[i]=0;
   }
   
   for(int i=0; i<v; i++)
   {
     for(int j=0; j<v; j++)
     {
       if(ad[i][j] && !visited[j] && (dist[i]+ad[i][j]<dist[j]))
       {
          dist[j]=dist[i]+ad[i][j];
       }
     }
     
     visited[i]=1;
     
   }

   cout<<"\n  Shortest Path From Source Vertex: \n";
   for(int i=1; i<v; i++)
   {
     cout<<"\n    Distance From "<<city[0]<<" To "<<city[i]<<" IS "<<dist[i]<<".";
   }
} */

void MH :: ssp()
{
    string src;
    int sourceIndex = -1;

    cout<<"\n  Enter Source Location Name: ";
    cin>>src;

    // Find index of source city
    for(int i = 0; i < v; i++)
    {
        if(city[i] == src)
        {
            sourceIndex = i;
            break;
        }
    }

    if(sourceIndex == -1)
    {
        cout<<"\n  Invalid Source Location Entered!";
        return;
    }

    int dist[10], visited[10];

    for(int i = 0; i < v; i++)
    {
        dist[i] = 999;  // Set distance to "infinity"
        visited[i] = 0;
    }

    dist[sourceIndex] = 0;

    for(int count = 0; count < v - 1; count++)
    {
        int min = 999, u;

        // Find the unvisited vertex with the smallest distance
        for(int i = 0; i < v; i++)
        {
            if(!visited[i] && dist[i] <= min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int i = 0; i < v; i++)
        {
            if(!visited[i] && ad[u][i] && dist[u] + ad[u][i] < dist[i])
            {
                dist[i] = dist[u] + ad[u][i];
            }
        }
    }

    cout<<"\n  Shortest Path From Source Location ("<<src<<"): \n";
    for(int i = 0; i < v; i++)
    {
        if(i != sourceIndex)
        {
            cout<<"\n    Distance From "<<src<<" To "<<city[i]<<" Is "<<dist[i]<<".";
        }
    }
}



int main()
{
   int ch;
   
   while(true)
   {
     cout<<"\n\nMenu.\n  1. Accept Locations and Distance.\n  2. Find Shortest Path.\n  3. Exit.";
     cout<<"\n  Enter your choice: ";
     cin>>ch;
     
     switch(ch)
     {
       case 1:
              m.accept();
              break;
              
       case 2:
              m.ssp();
              break;
              
       case 3:
              return 0;
              
              default:
              
              cout<<"\n  Wrong Choice.";
     }
   }
   
   return 0;
}
