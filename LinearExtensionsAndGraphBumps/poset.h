/****************************************************************
/*            poset.h
/*            Sept 2019
/*            by Gara Pruesse
/*            modified by Nawaf Alharbi
/*            class that reads a poset in from a file
/*            builds transitive closure, transitive reduction
/*            
/*********************************************************************/
#include <string>
#include <fstream>
#include <iostream>
#include <values.h>
#include <array>
#include <vector>   // STL vector, for adjacency list; ability to iterate
#include <stack>


using namespace std;

const int NO_EDGE=0;

class poset{
   private:
      int n;
      int default_nonedge;
      vector<int> *LowerIdeal;  // array of neighbour-vector
                         // all subsequent entries are names of neighbours
      vector<int> *UpperIdeal;  // array of neighbour-vector
                         // all subsequent entries are names of neighbours
      vector<int> *LowerCover;  // array of neighbour-vector
      vector<int> *UpperCover;  // array of neighbour-vector
      bool **Less; // nxn array of less-than relations from data file
      bool **Covers; // nxn array of Lower Cover relations 
                     // Covers[i][j]==1 means i covers j

   public: 
	  
	
      poset();
      poset(int num);
      int posetRead(char *fn);

      
      void VISUALIZE_MATRICES(bool** matrix); // here for testing - REMOVE ONCE DONE - 


      void VISUALIZE_VECTORS(vector <int> *vec); // here for testing - REMOVE ONCE DONE -

	  void displayGraph(int ** graph, int V);

      void ReadReduceWrite(char *fn); 


      int posetWrite(char *fn);
	   ~poset();
	   int numElements() { return n; }
	   int addCover(int u, int v);
	   int removeCover(int u, int v);
	   bool lessThan(int u, int v);
	   void printPoset();
	   void listLowerIdeal(int v);
	   //int BreadthFirstTraversal(int v, void (*f)(int));
};


	
