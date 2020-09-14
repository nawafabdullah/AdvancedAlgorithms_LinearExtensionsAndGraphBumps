/**
* Nawaf Alharbi
* CSCI 422
* Lab4
**/

#include "poset.h"
//#include "bump.h"


void displayGraph(int ** graph, int V);
void ReadReduceWrite(char *fn);


int main(int argc, char *argv[])
{
  if (argc != 2)
  {
     perror ("not suffecient number of arguments \n exiting program ..");
     return 0;
  } 
  //char *fn[80] = argv[1];
  ReadReduceWrite(argv[1]);
  cout << endl;
  return 1;
}

void ReadReduceWrite(char *fn)
{
  int **graph; // stores elements from input file 
  int V = 0; // read input and store it here 
  ifstream input_file; // ifstream  descriptor 
  input_file.open(fn); // open file 
  input_file >> V; // read and store first input here  
  int read = 0;
  graph = new int *[V]; // allocate memory - will be freed later -

  //loop inserting values and storing them in graph 
  for (int i = 0; i < V; i++)
   {
     graph[i] = new int[V]; 
     for (int j = 0; j < V; j++)
     {
       graph[i][j] = 0;
     }
     input_file >> read;
     while (read != V)
     {
       graph[i][read] = 1;
       input_file >> read;
     }
   }
  input_file.close(); // close file after reading 
  cout << "Input Graph : " <<endl;
  displayGraph(graph, V);
  cout << endl;
  
  ofstream output_file; //ofstream descriptor
  string output_file_name = fn; // extract the same name that was passed in the command line argument 
  output_file_name = output_file_name + ".treduc"; // add treduc to end of file name as per specs 
  output_file.open(output_file_name); //open the new file using the desriptor    

  for (int i = 0; i < V; ++i)
  {
    for (int j = 0; j < V; ++j)
    {
      for (int k = 0; k < V; ++k)
      {
	if (graph[i][k] == 1 && graph[k][j] == 1 && i != j && j != k && i != k)
	  graph[i][j] = 0;
      }
    }
  }

  cout << "Output Graph (also written in the output file (" + output_file_name + ")) : " << endl;
  displayGraph(graph, V);
  cout <<endl;
  
  output_file << V << endl;
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (graph[i][j] == 1)
	output_file << j << " ";
    }
    output_file << V << endl;
  }
  output_file << V;
  output_file.close();
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
