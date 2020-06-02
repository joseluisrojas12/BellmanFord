//Program in C++ to execute the Bellman-Ford algorithm to find the
//shortest path distance from one chosen source vertex to another one
//and to the rest of vertex in the same graph.

#include<iostream>
#define MAX 10
using namespace std;

typedef struct edge
{
  int src;
  int dest;
  int wt;
}edge;

void bellman_ford(int nv,edge e[],int src_graph,int ne)
{
  int u,v,weight,i,j=0;
  int dis[MAX];
  int destiny;

  /* initializing array 'dis' with 999. 999 denotes infinite distance */
  for(i=0;i<nv;i++)
  {
    dis[i]=999;
  }

  /* distance of source vertex from source vertex is o */
  dis[src_graph]=0;

  /* relaxing all the edges nv - 1 times */
  for(i=0;i<nv-1;i++)
  {
    for(j=0;j<ne;j++)
    {
      u=e[j].src;
      v=e[j].dest;
      weight=e[j].wt;

      if(dis[u]!=999 && dis[u]+weight < dis[v])
      {
        dis[v]=dis[u]+weight;
      }
    }

  }

  /* checking if negative cycle is present */
  for(j=0;j<ne;j++)
  {
    u=e[j].src;
    v=e[j].dest;
    weight=e[j].wt;

    if(dis[u]+weight < dis[v])
    {
      cout<<"\n\nNEGATIVE CYCLE PRESENT..!!\n";
      return;
    }
  }

  //This part is to show the shortest distance from the source vertex to
  //another vertex in the same graph

  cout<<endl;
  cout<<"The Vertex number for source is "<<src_graph;
  cout<<" enter the Vertex number for destiny: ";
  cin>>destiny;
  cout<<endl;
  for(int show=0;show<nv;show++)
  {
      if(destiny==show)
      {
          cout<<"The mtr value from source Vertex to destiny Vertex is: "<<dis[show]<<endl;
      }
  }

  //This part is to show the shortest distance from the source vertex to each
  //of the other vertex in the same graph.

  cout<<"\nVertex"<<"  Distance from source";
  for(i=1;i<nv+1;i++)
  {
    cout<<"\n"<<i<<"\t"<<dis[i];
  }

}

//Preconditions: Assign a number to each vertex in the graph so the same for each edge.
//Post-conditions: The program will ask to type the name for each vertex, next the source
//vertex from wich will be calculated the distance to the other vertex in the graph,
//then the source and destiny for each vertex with its respective weight in ms.
//The program will ask to enter the destiny vertex number to estimate its mtr from the source
//vertex to the vertex chosen as destiny. A table with the distance from source vertex to the
//rest vertex will be displayed also.

int main()
{
  int nv,ne,src_graph;
  edge e[MAX];

  cout<<"Enter the number of vertices: ";
  cin>>nv;
  cout<<endl;

  string name_vertice[nv];

  for(int name=0;name<nv;name++)
  {
      cout<<"For vertex number "<<name+1<<" its name is: ";
      cin>>name_vertice[name];
      //cout<<endl;
  }

  cout<<endl;

  /* if you enter no of vertices: 5 then vertices will be 1,2,3,4,5.
  so while giving input enter source and destination vertex accordingly */

  cout<<"Enter the vertex number for source vertex of the graph: ";
  cin>>src_graph;
  //cout<<endl;
  cout<<"\nEnter no. of edges: ";
  cin>>ne;
  //cout<<endl;
  for(int i=0;i<ne;i++)
  {
    cout<<"\nFor edge "<<i+1<<"=>";
    cout<<"\nEnter its source vertex number:";
    cin>>e[i].src;
    cout<<"Enter its destination vertex number:";
    cin>>e[i].dest;
    cout<<"Enter its weight (average time in ms) :";
    cin>>e[i].wt;
  }
cout<<endl;

//I use this output to show the distance from the source vertex to all
//the other ones in the graph during testing of the program.

cout<<"| Vertex number |  Vertex name  |"<<endl;
cout<<"---------------------------------"<<endl;

for(int jk=0;jk<nv;jk++)
{
    cout<<"|       "<<jk+1<<"       |   "<<name_vertice[jk];
    cout<<endl;
}

  bellman_ford(nv,e,src_graph,ne);

  cout<<endl;

  return 0;
}
