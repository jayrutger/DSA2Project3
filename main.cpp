#include "AdjacencyMatrix.hpp"

bool valid = false;

int numCities, numTours, numGenerations, numPercent;

int main()
{

	do{
		valid = true;
		std::cout << "Please enter number of cities to run: " << std::endl;
		
		std::cin >> numCities;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter only integers\n";
			valid=false;

		}

	}while(valid==false);

	
	
	do{
		valid = true;
		
		std::cout << "How many individual tours are in a given generation: " << std::endl;
		
		std::cin >> numTours;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter only integers\n";
			valid=false;

		}

	}while(valid==false);



	do{
		valid = true;
		
		std::cout << "Please enter how many generations to run: " << std::endl;
		
		std::cin >> numGenerations;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter only integers\n";
			valid=false;

		}

	}while(valid==false);


	
	do{
		valid = true;
		
		std::cout << "Please enter what percentage of generation should be compromised of mutations: " << std::endl;
		
		std::cin >> numPercent;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter only integers\n";
			valid=false;

		}

	}while(valid==false);


	std::cout << std::endl;

	AdjacencyMatrix obj;

	obj.MakeArrayFromFile();

	std::cout << "The number of cities ran is: " << numCities << std::endl<< std::endl;

	obj.Permutate(numCities);	

	std::cout << std::endl;

	obj.Generational(numCities, numTours, numGenerations, numPercent);


	std::cout << std::endl << std::endl;


	return 0;
}
