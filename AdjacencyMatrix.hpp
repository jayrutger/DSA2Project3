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
	
	public:
		void PrintMatrix();
		void MakeArrayFromFile();


};

#endif 
