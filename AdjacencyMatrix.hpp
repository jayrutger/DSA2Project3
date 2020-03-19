#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class AdjacencyMatrix
{

	private:
		double matrix[20][20];
		int permMatrix[10] = {1,2,3,4,5,6,7,8,9,10};
	public:

		void PrintMatrix();
		void MakeArrayFromFile();
		void printS();
		void Permutate(int numElements);

};

#endif 
