// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
using namespace std;
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mst.cpp"



// Driver program to test above functions
int main(int argc, char *argv[])
{
	if ( argc > 1 ){ // argc should be 2 for correct execution
		// We print argv[0] assuming it is the program name
		cout<<"usage: "<< argv[0] <<" <filename> or 'random # #'\n";
		return 0;}
	else if( argv[1] != "random"){
		// We assume argv[1] is a filename to open
		ifstream the_file(argv[1]);
		// Always check to see if file opening succeeded
		if (!the_file.is_open())
			cout << "Could not open file\n";
		else {
			char x;
			int j=0;
			long int i;
			// the_file.get ( x ) returns false if the end of the file
			//  is reached or an error occurs
			while (the_file.get(x)){
				j++;
			}
		}
		// the_file is closed implicitly here
		// We assume argv[1] is a filename to open
		ifstream the_file2(argv[1]);
		// Always check to see if file opening succeeded
		if (!the_file2.is_open())
			cout << "Could not open file\n";
		else {
			char x;
			int j=0;
			long int i=0;
			// the_file.get ( x ) returns false if the end of the file
			//  is reached or an error occurs
			while (the_file2.get(x)){
				j = x - '0';
				graphArray[i] = j;
			}
		}
		// the_file is closed implicitly here
	}

	//V = 4;  // Number of vertices in graph
	//E = 5;  // Number of edges in graph
	double z=0.0;
	int m=0,n=0, weightVal;
	for (int i=0;i < V;i++){
		for (int j=0;j < V;j++){
			if (m!=n){
				graph->edge[i*V+j].src = m;
				graph->edge[i*V+j].dest = n;
				graph->edge[i*V+j].weight = distanceCalculate(graphArray[m*2], graphArray[m*2+1], graphArray[n*2], graphArray[n*2+1]);
			}
			n++;
		}

	}

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	KruskalMST(graph);

	return 0;
}