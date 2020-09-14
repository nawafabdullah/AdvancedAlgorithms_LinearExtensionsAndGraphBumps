/** 
* Nawaf Alharbi
* CSCI422
* Lab4
**/

int **graph; // stores elements from input file here


#include "poset.h"
#include "bump.h"

struct node{
  int index;
  int priority;
};
void linearExtension(int V, int **graph);

void linearExtensionUtil(int v, bool visited[], stack<node> &Stack, int V, int **graph, node*nodes);

int main(int argc, char **argv)
{
 
  int V = 0; // to compare against input  
  ifstream input_file; // ifstream  descriptor 
  input_file.open(argv[1]); // open file 
  input_file >> V; // read and store first input here  
  int read = 0;
  graph = new int *[V]; // allocate memory - will be freed later -

  //loop inserting values and storing them in graph 
  for (int i = 0; i < V; i++)
  {
    graph[i] = new int[V]; 
    for (int j = 0; j < V; j++)
    {
      graph[i][j] = 0; //initilaize matrix (2d array) with 0s
    }
    input_file >> read; // start reading from file and inserting data to read  
    while (read != V)
    {
      graph[i][read] = 1;
      input_file >> read;
    }
   }
  input_file.close(); // close file after reading  
  cout << "Input Graph : " <<endl; // display to screen 
  displayGraph(graph, V); // display content inside 2d array 
  cout << endl;
  cout <<endl;
  cout << endl;
  linearExtension(V, graph);
  return 1;
}

// got some help here from Geeks for Geeks 
void linearExtensionUtil(int v, bool visited[], stack<node> &Stack, int V, int **graph, node*nodes)
{
  visited[v] = true; // keep track of visited nodes 
  for (int i = 0; i != V; ++i) // loop looking for visited nodes 
  {
    if (graph[v][i] == 1)
    {
      if (!visited[i])
	linearExtensionUtil(i, visited, Stack, V, graph, nodes);
    }
  }
  Stack.push(nodes[v]); //push nodes 
}


void linearExtension(int V, int **graph)
{
  stack<node> Stack;
  bool *visited = new bool[V];
  node *nodes = new node[V];
  for (int i = 0; i < V; i++)
  {
    nodes[i].priority = rand() % 100;
    nodes[i].index = i;
    visited[i] = false;
  }
  for (int i = 0; i < V; i++)
  {
    if (visited[i] == false)
      linearExtensionUtil(i, visited, Stack, V, graph, nodes);
  }
  stack<node> Stack2;
  stack<node> Stack3;
  while (Stack.empty() == false)  
  {
    cout << Stack.top().index << " ";
    Stack2.push(Stack.top());
    Stack.pop();
  }
  while (Stack2.empty() == false)
  {
    Stack3.push(Stack2.top());
    Stack2.pop();
  }
  cout << "\nPriorities:" << endl;
  
  while (Stack3.empty() == false)
  {
    cout << Stack3.top().priority << " ";
    Stack3.pop();
  }

  cout <<endl;
}

void displayGraph(int ** graph, int V)
{
  cout << V << endl;
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (graph[i][j] == 1)
	cout << j << " ";
    }
    cout << V << endl;
  }
  cout << V;
}


