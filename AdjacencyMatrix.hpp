#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

class AdjacencyMatrix
{

	private:
		int numElements;
		int numPermutations;
		double matrix[20][20];
		//int permMatrix[10] = {1,2,3,4,5,6,7,8,9,10};
//		std::vector <int> permVect;
	public:
		std::vector <std::vector <int>> permVect2;
		std::vector <int> permVect;
		void PrintMatrix();
		void MakeArrayFromFile();
		void printS();
		void Permutate(int numElements);
		double GetDistance();
};

#endif 
