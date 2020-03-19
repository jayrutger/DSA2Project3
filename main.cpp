#include "AdjacencyMatrix.hpp"

int main()
{

	AdjacencyMatrix obj;

	obj.MakeArrayFromFile();

	obj.PrintMatrix();
		

	obj.Permutate(10);	



	return 0;
}
