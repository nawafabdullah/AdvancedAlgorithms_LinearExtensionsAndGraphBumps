#include <iostream>
#include <stack>
#include <queue>
//#include <SDL.h>
#include <fstream>
#include <string.h>

void linearExtensionUtil(int v, bool visited[], stack <int> &Stack, int V, int **graph);
void linearExtension(int V, int **graph); 

void displayGraph(int ** graph, int V);
void writeGraph(int ** graph, int V, string outName);