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
	
	public:
	
		std::vector <std::vector <int>> permVect2;
		std::vector <int> permVect;	
		std::vector <int> genPermVect;
		std::vector <std::vector <int>> eliteTracker;
		std::vector <std::vector <int>> generationVect;
		void PrintMatrix();
		void MakeArrayFromFile();
		void printS();
		void Permutate(int numElements);
		double GetDistance();
		void Generational(int numCities, int numTours, int numGenerations, int numPercentage);
};

#endif 
