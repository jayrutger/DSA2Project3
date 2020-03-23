#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>

/*********************************************************************************
 Student Name: James Rutger
 File Name: AdjacencyMatrix.hpp
 Assignment: Project 3 - Brute Force and Generational

 Data Structures and Algorithms 2
 Dr. John Coffey

 Class Description:

 This class has the functions for the brute force method and the generational method
 for the traveling salesman problem. The brute force takes in the number of cities, 
 and outputs the minimum distance with the time it took to calculate it.
 The generational method takes in the number of cities, tours, generations, and
 mutation percentage per generation, and finally outputs the min distance by this
 method and the time it took to calculate it. 
***********************************************************************************/

class AdjacencyMatrix
{

	private:
		double bruteForce;
		double genForce;	
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
