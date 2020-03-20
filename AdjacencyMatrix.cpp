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
	
	permVect2.push_back(permVect);//To store normal int vector
	
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

		permVect2.push_back(permVect);

//		printS();
	}

		printS();	

}

void AdjacencyMatrix::printS()
{
//	permVect2.push_back(permVect);

	for(int i=0;i<numPermutations;i++)
	{
		for(int j=0;j<numElements;j++)
		{
			//std::cout << permVect.at(i) << " ";
			std::cout << permVect2[i].at(j) << " ";
	
		}

	std::cout << std::endl;
	}
	//std::cout << numPermutations;
	std::cout << std::endl;
	//std::cout << permVect2.size();


}

double AdjacencyMatrix::GetDistance()
{	
	double minValue=0;
	//std::cout << permVect2.size() << std::endl;
	for(int i=0;i<permVect2.size();i++)
	{
		double thisTotal = 0;

		for(int j=0;j<numElements;j++)
		{

			if(j==numElements-1)
			{
				//thisTotal += matrix[permVect2[i].at(j)-1][permVect2[i].at(0)-1];	

				std::cout <<  matrix[permVect2[i].at(j)-1][permVect2[i].at(0)-1] << std::endl << "last\n";	
			}
			else
			{
				//thisTotal+=  matrix[permVect2[i].at(j)-1][permVect2[i].at(j)];
		
				std::cout << matrix[permVect2[i].at(j)-1][permVect2[i].at(j+1) - 1] << std::endl;
			}
		}

//		if(i == 0)
	//	{
	//		minValue = thisTotal;
//		}

		//if(thisTotal < minValue)
		//{
		//	minValue = thisTotal;
		//}
	//	std::cout << thisTotal;
	}

//std::cout << minValue; WORKS ME THINKS




}
