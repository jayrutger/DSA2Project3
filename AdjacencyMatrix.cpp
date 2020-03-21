#include "AdjacencyMatrix.hpp"
#include <iostream>
#include <fstream>

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

//	thisTotal += matrix[permVect.at(j)-1][permVect2.at(0)-1];	

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
		
		std::cout << "It took : " << time_span.count() << " seconds" << std::endl;

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



