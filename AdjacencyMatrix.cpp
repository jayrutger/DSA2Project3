#include "AdjacencyMatrix.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>

/*********************************************************************************
 Student Name: James Rutger
 File Name: AdjacencyMatrix.cpp
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
using namespace std::chrono;

void AdjacencyMatrix::MakeArrayFromFile()
{
	std::string line;
	std::ifstream myFile;
	myFile.open("distances.txt");
	
	for (int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(myFile.is_open())
			{
					if(i == j)
					{
						matrix[i][j]=0;
					}
					else
					{
						
						std::getline(myFile,line);
						std::stringstream ss;
						ss << line;
						std::string line2;
						line2 = ss.str();
						matrix[i][j] = std::stod(line2);
					}	
			
			}
			
		}
	}

}

void AdjacencyMatrix::PrintMatrix()
{
		
	for (int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(j == 19)
			{
				std::cout << matrix[i][j] << std::endl;
			}
			else
			{
				std::cout << matrix[i][j] << " ";
			}
		}
	}
}


void AdjacencyMatrix::Permutate(int NUMELEMENTS)
{
	double minValue = 0;
	numElements = NUMELEMENTS;
	int permsThisCall = 1;

	for(int i=0;i<NUMELEMENTS;i++)
	{
		permsThisCall = permsThisCall * (NUMELEMENTS-i);
	}

	numPermutations = permsThisCall;
	for(int i=0;i<=numElements;i++)
	{
		permVect.push_back(i+1);
	}

	int m, k, p, q, i;
	
	double firstTotal=0;

	for(int j=0;j<numElements;j++)
	{

		if(j==numElements-1)
		{
			firstTotal += matrix[permVect.at(j)-1][permVect.at(0)-1];		
		}

		else
		{	
			firstTotal += matrix[permVect.at(j)-1][permVect.at(j+1) - 1];
		}
	}
			minValue = firstTotal;


	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	for(i = 1;i < permsThisCall; i++)
	{
		double thisTotal = 0;

		m = NUMELEMENTS-2;
		while(permVect.at(m)>permVect.at(m+1))
		{
			m = m - 1;            
		}
		k = NUMELEMENTS - 1;
		while(permVect.at(m) > permVect.at(k))
		{
			k = k - 1;
		}
		std::swap(permVect.at(m),permVect.at(k));
		p = m + 1;
		q = NUMELEMENTS-1;
		while(p < q)
		{
			std::swap(permVect.at(p),permVect.at(q));
			p++;
			q--;
		}

		for(int j=0;j<numElements;j++)
		{

			if(j==numElements-1)
			{
				thisTotal += matrix[permVect.at(j)-1][permVect.at(0)-1];		
			}

			else
			{	
				thisTotal += matrix[permVect.at(j)-1][permVect.at(j+1) - 1];	
			}
		}


		if(thisTotal < minValue)
		{
			minValue = thisTotal;
		}


	}


		high_resolution_clock::time_point t2 = high_resolution_clock::now();


		duration<double> time_span = duration_cast<duration<double>>(t2-t1);

		this->bruteForce = minValue;
	
		std::cout << "The optimal cost of brute force is: " << minValue << std::endl;// WORKS ME THINKS
		
		std::cout << "It took: " << time_span.count() << " seconds"  <<std::endl;

}

void AdjacencyMatrix::printS()
{

	for(int i=0;i<numPermutations;i++)
	{
		for(int j=0;j<numElements;j++)
		{
			std::cout << permVect2[i].at(j) << " ";
	
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;


}

double AdjacencyMatrix::GetDistance()
{	
	double minValue=0;

	for(int i=0;i<permVect2.size();i++)
	{
		double thisTotal = 0;

		for(int j=0;j<numElements;j++)
		{

			if(j==numElements-1)
			{
				thisTotal += matrix[permVect2[i].at(j)-1][permVect2[i].at(0)-1];		
			}

			else
			{	
				thisTotal += matrix[permVect2[i].at(j)-1][permVect2[i].at(j+1) - 1];	
			}
		}

		if(i == 0)
		{
			minValue = thisTotal;
		}

		if(thisTotal < minValue)
		{
			minValue = thisTotal;
		}
	}

	std::cout << "The minimum distance is: " << minValue << std::endl;// WORKS ME THINKS

}





void AdjacencyMatrix::Generational(int numCities, int numTours, int numGenerations, int numPercentage)
{

	double genMin = 0;

	int numGen=0;

	for(int i=0;i<numCities;i++)//Makes initial chronological list
	{
		genPermVect.push_back(i+1);
	}

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i=0; i<numGenerations; i++)
	{

		int smallTracker=0;
	
		int numStart=0;

		double minDistance=0;

		generationVect.clear();
	
		if(!eliteTracker.empty())
		{

			generationVect.push_back(eliteTracker.at(0));
			generationVect.push_back(eliteTracker.at(1));
		}

		std::srand (unsigned (std::time(0)));
		for (int i=0; i<numTours; i++)
		{
			double thisTotal=0;
	
			std::random_shuffle (genPermVect.begin(), genPermVect.end());		
			
			for(int j=0;j<numCities;j++)//Prints out shuffled vector
			{
	
	
				if(j==numCities-1)
				{
					thisTotal += matrix[genPermVect.at(j)-1][genPermVect.at(0)-1];		
				}

				else
				{	
					thisTotal += matrix[genPermVect.at(j)-1][genPermVect.at(j+1) - 1];	
				}


			}
	
			generationVect.push_back(genPermVect);

			if(i==0 && numGen ==0)
			{
				genMin = thisTotal;
				minDistance = thisTotal;
				smallTracker++;
				eliteTracker.push_back(genPermVect);
			}
			if(thisTotal <= genMin)
			{
				genMin = thisTotal;
				minDistance = thisTotal;
				smallTracker++;
				eliteTracker.push_back(genPermVect);
			}	
		
		}
	
		if(numGen == numGenerations-1)
		{	
			std::cout <<"The cost from the generational model is: " <<  genMin << std::endl; 

		}

		double totalOne = 0;
			for(int j=0;j<numCities;j++)//Prints out shuffled vector
			{
	
	
				if(j==numCities-1)
				{
					totalOne += matrix[eliteTracker[eliteTracker.size()-1].at(j)-1][eliteTracker[eliteTracker.size()-1].at(0)-1];		
				}

				else
				{	
					totalOne += matrix[eliteTracker[eliteTracker.size()-1].at(j)-1][eliteTracker[eliteTracker.size()-1].at(j+1) - 1];	
				}


			}



		double totalTwo=0;

	
			for(int j=0;j<numCities;j++)//Prints out shuffled vector
			{	
	
				if(j==numCities-1)
				{
					totalTwo += matrix[eliteTracker[eliteTracker.size()-2].at(j)-1][eliteTracker[eliteTracker.size()-2].at(0)-1];		
				}

				else
				{	
					totalTwo += matrix[eliteTracker[eliteTracker.size()-2].at(j)-1][eliteTracker[eliteTracker.size()-2].at(j+1) - 1];	
				}


			}	

	numGen++;
	
	}

		high_resolution_clock::time_point t2 = high_resolution_clock::now();

		duration<double> time_span = duration_cast<duration<double>>(t2-t1);

		std::cout << "It took: " << time_span.count() << " seconds"  <<std::endl;

		std::cout << "Percent of optimal that the GA produced:  " << (genMin/bruteForce)*100  << "%" << std::endl;
}
