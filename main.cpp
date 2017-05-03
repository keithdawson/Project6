//Code by Blake Mizzell to implement Project5 for CS 101 using Prims algorithm with an adjacency graph
using namespace std;
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mst.cpp"



// Driver program to test above functions
int main(int argc, char *argv[])
{   int vertexes;
	Vert * vertA;
	if ( argc < 1 ){ // argc should be 2 for correct execution
		// We print argv[0] assuming it is the program name
		cout<<"usage: "<< argv[0] <<" <filename> or 'random # #'\n";
		return 0;}
	if( argv[1] != "random") {
		// We assume argv[1] is a filename to open
		ifstream the_file(argv[1]);
		// Always check to see if file opening succeeded
		if (!the_file.is_open())
			cout << "Could not open file\n";
		else {
			char x;
			int j = 0;
			// the_file.get ( x ) returns false if the end of the file
			//  is reached or an error occurs
			while (the_file.get(x)) {
				if(x >= '0' && x<= '9') j++;
			}
			vertexes = j / 2;
		}
		the_file.close();
		Vert *vertB[vertexes];
		vertA = *vertB;
		// the_file is closed implicitly here
		// We assume argv[1] is a filename to open
		ifstream the_file2(argv[1]);
		cout << "test1" << endl;
		// Always check to see if file opening succeeded
		if (!the_file2.is_open())
			cout << "Could not open file\n";
		else {
			cout << "test0" << endl;

			char x;
			int c = 0;
			bool boo = true;
			long int i = 0;
			// the_file.get ( x ) returns false if the end of the file
			//  is reached or an error occurs
			while (the_file2.get(x)) {
				if(x >= '0' && x<= '9'){
					c = x - '0';
					if (boo) {
						vertA[i].coordX = c;
						boo = false;
					}
					else {
						cout<< c  <<endl;
						vertA[i].coordY = c;
						i++;
						boo = true;
					}
				}
			}
		}
		the_file2.close();
		// the_file is closed implicitly here
		cout << "test11" << endl;
	}
	cout << "testLOL" << vertA[4].coordX << ' ' <<vertexes<<endl;
	double graph[vertexes][vertexes];
	for (int i=0;i<vertexes;i++){
		for (int j=0;j<vertexes;i++){
			cout<<vertA[i].coordX<<endl;
			graph[i][j] = intdistanceCalculate(vertA[i].coordX, vertA[i].coordY, vertA[j].coordX, vertA[j].coordY);
			//cout << graph[i][j];
		}
		cout << endl;
	}
	cout << "testing" << endl;
	return 0;
}