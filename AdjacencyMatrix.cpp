#include "AdjacencyMatrix.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>

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
//	printS();//set called S
	
///	permVect2.push_back(permVect);//To store normal int vector

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

///		permVect2.push_back(permVect);//Permutated vectors

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


//		printS();
	}

//		printS();	

		high_resolution_clock::time_point t2 = high_resolution_clock::now();


		duration<double> time_span = duration_cast<duration<double>>(t2-t1);

//		GetDistance();

		std::cout << "The minimum distance is: " << minValue << std::endl;// WORKS ME THINKS
		
		std::cout << "It took : " << time_span.count() << " seconds" << std::endl  <<std::endl;

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
		
				//std::cout <<  matrix[permVect2[i].at(j)-1][permVect2[i].at(0)-1] << std::endl;	
			}

			else
			{	
				thisTotal += matrix[permVect2[i].at(j)-1][permVect2[i].at(j+1) - 1];
	
				//std::cout << matrix[permVect2[i].at(j)-1][permVect2[i].at(j+1) - 1] << std::endl;
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
//		std::cout << thisTotal;
	}

	std::cout << "The minimum distance is: " << minValue << std::endl;// WORKS ME THINKS

}





void AdjacencyMatrix::Generational(int numCities, int numTours, int numGenerations, int numPercentage)
{

//	auto rng = std::default_random_engine {};

	double genMin = 0;

	int numGen=0;

	for(int i=0;i<numCities;i++)//Makes initial chronological list
	{
		genPermVect.push_back(i+1);
	}

	for(int i=0; i<numGenerations; i++)
	{

		int smallTracker=0;
	
		int numStart=0;

		double minDistance=0;

//		for(int i=0;i<numCities;i++)//Makes initial chronological list
//		{
//			genPermVect.push_back(i+1);
//		}

		generationVect.clear();
	
		if(!eliteTracker.empty())
		{

			generationVect.push_back(eliteTracker.at(0));
			generationVect.push_back(eliteTracker.at(1));
		}

	//	eliteTracker.clear();
		std::srand ( unsigned (std::time(0)));
		for (int i=0; i<numTours; i++)
		{
			double thisTotal=0;
 	//		eliteTracker.clear();
	
			//std::shuffle(genPermVect.begin(),genPermVect.end(),rng);
			std::random_shuffle (genPermVect.begin(), genPermVect.end());		
//			std::srand ( unsigned (std::time(0)));
			
			for(int j=0;j<numCities;j++)//Prints out shuffled vector
			{
//				std::cout << genPermVect.at(j) << " ";
	
	
				if(j==numCities-1)
				{
					thisTotal += matrix[genPermVect.at(j)-1][genPermVect.at(0)-1];		
				}

				else
				{	
					thisTotal += matrix[genPermVect.at(j)-1][genPermVect.at(j+1) - 1];	
				}


			}

//			std::cout << std::endl;
			
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


 //			eliteTracker.clear();
	
		
		}
	
 //		eliteTracker.clear();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

	for(int j=0;j<eliteTracker.size();j++)
	{

		for(int i=0;i<numCities;i++)
		{
			std::cout << eliteTracker[j].at(i) << " ";
		}
		std::cout << std::endl;
	}


		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout <<"The min distance of this generation is: " <<  genMin << std::endl; 


		std::cout << "The elites of this generation are: ";

		for(int i=0;i<numCities;i++)
		{
			std::cout << eliteTracker[eliteTracker.size()-1].at(i) << " ";
		}
		std::cout << std::endl;

		std::cout << "With a distance of: ";

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


		std::cout << totalOne;
		
		std::cout << std::endl;
		std::cout << "and: ";

		double totalTwo=0;

		for(int i=0;i<numCities;i++)
		{
			std::cout << eliteTracker[eliteTracker.size()-2].at(i) << " ";
		}
		std::cout << std::endl;
		
		std::cout << "With a distance of: ";
	
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

			std::cout << totalTwo;

			std::cout << std::endl <<std::endl;
			

	numGen++;
	}

//		eliteTracker.clear();

}
