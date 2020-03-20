#include "AdjacencyMatrix.hpp"
#include <iostream>
#include <fstream>

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
				std::cout << std::endl;
			}
			std::cout << matrix[i][j] << " ";
		}
	}
}


void AdjacencyMatrix::Permutate(int NUMELEMENTS)
{

	numElements = NUMELEMENTS;
	int permsThisCall = 1;

	for(int i=0;i<NUMELEMENTS;i++)
	{
		permsThisCall = permsThisCall * (NUMELEMENTS-i);
	}

	for(int i=0;i<=numElements;i++)
	{
		permVect.push_back(i+1);
	}

	int m, k, p, q, i;
	printS();//set called S
	
	for(i = 1;i < permsThisCall; i++)
	{
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
		printS();
	}
	

}

void AdjacencyMatrix::printS()
{

	for(int i=0;i<numElements;i++)
	{
		std::cout << permVect.at(i) << " ";
	}
	std::cout << std::endl;

}
